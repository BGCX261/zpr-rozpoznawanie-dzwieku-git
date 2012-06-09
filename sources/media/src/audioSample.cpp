/** 
* @file
* Implementation of AudioSample class
* 
* It represents sample of raw audio data \n
* If it if multichannel data then it is in form ch1 ch2 ch1 ch2 ...
*/

/// Lukasz Rychter
/// Maciej Sikora

#include "stdafx.h"
#include "AudioSample.h"

using namespace media;

unsigned int AudioSample::getLength() const
{ 
	unsigned int samplesNum = getSize();
	if (samplesNum == 0)
		throw std::out_of_range("Sampling rate is not set");

	return getSize() * 1000 / sampleRate_ / channels_; 
} 


void AudioSample::set(const unsigned short* data, unsigned int count)
{
	if (buffer_.get())
		clear();
	else
		buffer_ = std::auto_ptr<std::vector<unsigned short>>(new std::vector<unsigned short>); /// new may throw bad alloc
	
	if (!buffer_.get())
		throw std::bad_alloc();

	buffer_->assign(data, data + count);
}