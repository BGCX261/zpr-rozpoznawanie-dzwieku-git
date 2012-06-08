/** 
* @file
* Declaration of AudioSample class
*
* It represents sample of raw audio data (mono)
*/

/// Lukasz Rychter
/// Maciej Sikora

#ifndef __AUDIO_SAMPLE_H__
#define __AUDIO_SAMPLE_H__

#include "simpleBuffer.h"

namespace media
{
	
/// Declaration of class representing sample of raw audio data (mono)
class AudioSample : public SimpleBuffer<unsigned short>
{
public:
	AudioSample(unsigned int sampleRate=0) throw() : sampleRate_(sampleRate) {}; /// default constructor. Construct empty object. Sampling rate may be set
	AudioSample(unsigned short* data, unsigned int count, unsigned int sampleRate=0) throw() : sampleRate_(sampleRate), SimpleBuffer<unsigned short>(data, count) {}; /// Construct object with provided data. Sampling rate may be set

	unsigned int getLength() const throw(...) /// sample length in milliseconds. May throw if sample rate is not set (or set to 0)
	{ 
		unsigned int samplesNum = getSize();
		if (samplesNum == 0)
			throw std::out_of_range("Sampling rate is not set");

		return getSize() * 1000 / sampleRate_; 
	} 

	void			setSampleRate(unsigned int sampleRate) { sampleRate_ = sampleRate; } /// sets sampling rate
	unsigned int	getSampleRate() const throw() { return sampleRate_; } /// returns sampling rate
	

protected:
	unsigned short sampleRate_;
};

}; //namespace

#endif
