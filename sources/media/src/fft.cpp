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

#include "fftw3.h"

using namespace media;

FFT* FFT::instance_;


FFT& FFT::getInstance() throw(...)
{
	if (!instance_)
	{
		initialize();

		if (!instance_)
			throw std::bad_alloc();
	}
	return *instance_;
}


void FFT::initialize() throw(...)
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