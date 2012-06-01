/** 
* @file
* Declaration of WaveReader class
*
* Reads sounds from WAVE files
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __WAVE_READER_H__
#define __WAVE_READER_H__

#include <fstream>
#include "soundReader.h"

namespace media
{
	
/// Declaration of class reading sounds from WAVE files
class WaveReader : public SoundReader
{
public:
	typedef char byte;
	typedef unsigned short word;
	typedef unsigned int dword;

	WaveReader() {}
	virtual ~WaveReader() { closeFile(); }

	virtual void readTo(const AudioSample& buffer);
	void openFile(std::string file);
	void closeFile();

	static const char * wav_id_value_;
	static const char * wav_format_id_value_;
	static const char * wav_description_value_;
	static const char * wav_data_id_value_;
	
	// TODO
	// temporary - that is easily for now
	static void waveReaderTests();

protected:
	std::fstream file_;
	dword data_size_;

};

}; //namespace

#endif
