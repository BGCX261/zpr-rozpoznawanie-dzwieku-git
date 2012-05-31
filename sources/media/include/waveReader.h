/** 
* @file
* Declaration of class reading sounds from WAVE files
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __WAVE_READER_H__
#define __WAVE_READER_H__

#include <fstream>
#include "../include/mediaContainers.h"
#include "../include/soundReader.h"

namespace media
{
	
/// Declaration of class reading sounds from WAVE files
class WaveReader : public SoundReader
{
public:
	WaveReader() {}
	virtual ~WaveReader() { closeFile(); }

	virtual void readTo(const AudioSample& buffer);
	void openFile(std::string file);
	void closeFile();
	
	static std::string file_prefix_;

	// TODO
	// temporary - that is easily for now
	static void waveReaderTests();

protected:
	std::fstream file_;

};

}; //namespace

#endif
