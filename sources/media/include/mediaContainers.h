/** 
* @file
* Declaration of media container classes
* 
* Those classes are specific buffers for audio data before and after processing
*/

/// Lukasz Rychter
/// Maciej Sikora

#ifndef __MEDIA_CONTAINERS_H__
#define __MEDIA_CONTAINERS_H__

#include <vector>

namespace media /// namespace for media processing modules
{

/// Declaration of class representing sample of sound before processing
template <typename T>
class SimpleBuffer
{
public:
	SimpleBuffer() {};
	SimpleBuffer(const T*, unsigned short size);
	
	const std::vector<T>&	get();
	void					set(const T*, unsigned short size);

protected:
	std::vector<T>			buffer_;
};


class FFTSample : public SimpleBuffer<unsigned short>
{
public:
	unsigned short getBandsNum() { return buffer_.size(); }

};


class AudioSample : public SimpleBuffer<unsigned short>
{
public:
	unsigned short getLength() { return buffer_.size() * 1000 / sampleRate_; } //ms
	unsigned short getSampleRate() { return sampleRate_; }

protected:
	unsigned short sampleRate_;
};


}; //namespace

#endif
