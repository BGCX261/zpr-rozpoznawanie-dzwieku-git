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

#include "../include/audioSample.h"

namespace media
{

/// Declaration of class reading sounds from any source
class SoundReader
{
public:
	SoundReader() {}
	virtual ~SoundReader() {}

	virtual void readTo(const AudioSample& buffer) = 0;
};

}; //namespace

#endif
