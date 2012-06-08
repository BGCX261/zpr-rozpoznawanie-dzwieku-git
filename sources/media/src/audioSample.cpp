/** 
* @file
* Implementation of AudioSample class
* 
* It represents sample of raw audio data (mono)
*/

/// Lukasz Rychter
/// Maciej Sikora

#include "stdafx.h"
#include "AudioSample.h"

using namespace media;

unsigned int AudioSample::getLength() const throw(...)
{ 
	unsigned int samplesNum = getSize();
	if (samplesNum == 0)
		throw std::out_of_range("Sampling rate is not set");

	return getSize() * 1000 / sampleRate_; 
} 


void AudioSample::set(const unsigned short* data, unsigned int count) throw(...)
{
	if (buffer_.get())
		clear();
	else
		buffer_ = std::auto_ptr<std::vector<unsigned short>>(new std::vector<unsigned short>); /// new may throw bad alloc
	
	if (!buffer_.get())
		throw std::bad_alloc();

	buffer_->assign(data, data + count);
}