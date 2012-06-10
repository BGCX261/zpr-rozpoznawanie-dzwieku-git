/** 
* @file
* Implementation of FFT class
* 
* Provides functions to convert signal into its spectrum using Fast Fourier Transform algorithm
*/

/// Lukasz Rychter
/// Maciej Sikora

#include "stdafx.h"
#include "fft.h"

#define FFTW_SINGLE
#include "fftw3.h"

using namespace media;
using namespace std;

FFT* FFT::instance_;


FFT& FFT::getInstance()
{
	if (!instance_)
	{
		initialize();

		if (!instance_)
			throw std::bad_alloc();
	}
	return *instance_;
}


void FFT::initialize()
{
	if (!instance_)
	{
		instance_ = new FFT; /// may throw bad_alloc

		if (!instance_)
			throw std::bad_alloc();
	}
}


void FFT::deinitialize() throw()
{
	if (instance_)
	{
		delete instance_;
		instance_ = NULL;
	}
}

#pragma warning(disable:4996) /// disabling warning about possibly usafe copying
auto_ptr<FFTSample> FFT::calculateFFT(const AudioSample& audio)
{
	unsigned long samples = audio.getSize();
	
	float* in_buf; /// auto_ptr cannot be used here because we need to use malloc and auto_ptr uses delete instead of free()
	fftwf_complex* out_buf; /// ^
	
	in_buf = (float*)fftwf_malloc(samples*sizeof(float));
	if (!in_buf)
		throw std::bad_alloc();

	out_buf = (fftwf_complex*)fftwf_malloc((samples/2+1)*sizeof(fftw_complex));
	if (!out_buf)
	{
		fftwf_free(in_buf);
		throw std::bad_alloc();
	}

	copy(audio.get().begin(), audio.get().end(), in_buf);
	
	fftwf_plan plan = fftwf_plan_dft_r2c_1d(samples, in_buf, out_buf, FFTW_ESTIMATE | FFTW_DESTROY_INPUT);
	fftwf_execute(plan);

	fftwf_free(in_buf);

	unsigned long fftBands = samples/2;
	auto_ptr<FFTSample> fftSample(new FFTSample(fftBands, audio.getSampleRate()/2));
	std::vector<float>& fft_buf = fftSample->getWritable();

	for (unsigned long i=0; i<samples/2; ++i)
		fft_buf[i] = sqrtf(out_buf[i+1][0]*out_buf[i+1][0] + out_buf[i+1][1]*out_buf[i+1][1]) / samples; /// i+1 -> omit DC shift

	fftwf_free(out_buf);

	return fftSample;
}