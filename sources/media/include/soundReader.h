/** 
* @file
* Declaration of SoundReader class
*
* It gives abstract interface for reading sound from any source
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __SOUND_READER_H__
#define __SOUND_READER_H__

#include "audioSample.h"

namespace media
{

/// Declaration of class reading sounds from any source
class SoundReader
{
public:
	SoundReader() {}
	virtual ~SoundReader() {}

	/// Function reads audioTime miliseconds of audio data and writes it
	/// to the passed buffer. If audioTime is 0 (default) then it reads the whole file
	virtual void readTo(AudioSample& buffer, unsigned long audioTime=0) = 0; 
};

}; //namespace

#endif
