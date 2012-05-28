/** 
* @file
* Declaration of class reading sounds from WAVE files
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __SOUND_READER_H__
#define __SOUND_READER_H__

#include <iostream>
#include "mediaContainer.h"
#include "soundReader.h"

namespace media
{

/// Declaration of class reading sounds from WAVE files
class WaveReader : public SoundReader
{
public:
	WaveReader() {}
	virtual ~WaveReader() { closeFile(); }

	virtual bool readTo(const AudioSample& buffer);
	void openFile(std::string file);
	void closeFile();

protected:
	std::iostream file_;

};

}; //namespace

#endif