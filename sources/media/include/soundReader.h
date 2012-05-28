/** 
* @file
* Declaration of class reading sounds from any source
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __SOUND_READER_H__
#define __SOUND_READER_H__

#include "mediaContainer.h"

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