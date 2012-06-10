/** 
* @file
* Declaration of AudioSample class
*
* It represents sample of raw audio data \n
* If it if multichannel data then it is in form ch1 ch2 ch1 ch2 ...
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
    AudioSample(unsigned int sampleRate=0) throw() : sampleRate_(sampleRate), channels_(0) {} /// default constructor. Construct empty object. Sampling rate may be set
    AudioSample(unsigned short* data, unsigned int count, unsigned int sampleRate=0) throw() : sampleRate_(sampleRate), SimpleBuffer<unsigned short>(data, count) {} /// Construct object with provided data. Sampling rate may be set
    virtual ~AudioSample() {}

	unsigned int	getLength() const; /// sample length in milliseconds. May throw if sample rate is not set (or set to 0)

	virtual void	set(const unsigned short* data, unsigned int count); /// allows to set buffer content. May throw bad_alloc
	
	void			setSampleRate(unsigned int sampleRate) throw() { sampleRate_ = sampleRate; } /// sets sampling rate
	unsigned int	getSampleRate() const throw() { return sampleRate_; } /// returns sampling rate

	void			setChannels(unsigned short channels) throw() { channels_ = channels; } /// sets number of channels of audio
	unsigned short	getChannels() const throw() { return channels_; } /// returns number of channels of audio
	

protected:
	unsigned short	sampleRate_;	/// sampling rate
	unsigned short	channels_;		/// number of channels of audio
};

} //namespace

#endif
