/** 
* @file
* Declaration of FFTSample class
*
* It represents sample of audio after FFT processing
*/

/// Lukasz Rychter
/// Maciej Sikora

#ifndef __FFT_SAMPLE_H__
#define __FFT_SAMPLE_H__

#include "simpleBuffer.h"

namespace media
{
	
class FFTSample : public SimpleBuffer<unsigned short>
{
public:
	FFTSample(unsigned short spectralRange=0) : spectralRange_(spectralRange) {} /// default constructor. Construct empty object. Spectral range may be set
	FFTSample(unsigned short* data, unsigned int count, unsigned short spectralRange=0) : spectralRange_(spectralRange), SimpleBuffer<unsigned short>(data, count) {} /// Construct object with provided data. Spectral range may be set

	void			setBandsNum(unsigned int size) { getWritable().resize(size); } /// allocates buffer for given number of bands. May throw bad_alloc
	unsigned short	getBandsNum() const throw() { return getSize(); } /// returns number of spectral bands
	
	void			setSpectralRange(unsigned short spectralRange) throw() { spectralRange_ = spectralRange; } /// allows to set spectral range
	unsigned short	getSpectralRange() const throw() { return spectralRange_; } /// returns spectral range

	float getSpectralResolution() const /// returns spectral resolution. May throw when data is not set.
	{
		unsigned int bands = getBandsNum();
		if (bands != 0)
			return spectralRange_ / (float)bands;
		else
			throw std::out_of_range("Cannot compute spectral resolution because number of bands is 0");
	}

	const unsigned short& operator[] (unsigned int index) const /// accesor (read-only) to bands values. May throw on bad index
	{ 
		if (index >= getSize())
			throw std::out_of_range("Index is out of range");

		return get()[index]; 
	}
	
	unsigned short& operator[] (unsigned int index) /// accesor (writable) to bands values. May throw on bad index
	{ 
		if (index >= getSize())
			throw std::out_of_range("Index is out of range");

		return getWritable()[index]; 
	}

protected:
	unsigned int spectralRange_;
};

}; //namespace

#endif
