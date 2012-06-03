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

	static const char * wav_id_value_;
	static const char * wav_format_id_value_;
	static const char * wav_description_value_;
	static const char * wav_data_id_value_;

	WaveReader() : data_size_(0), channels_(0), sample_rate_(0) {}
	WaveReader(const std::string& file) 
		: data_size_(0), channels_(0), sample_rate_(0) { openFile(file); }
	virtual ~WaveReader() { closeFile(); }

	virtual void readTo(const AudioSample& buffer);
	void openFile(const std::string& file);
	void closeFile();
	dword get_data_size() const;
	dword get_sample_rate() const;
	word get_channels() const;

protected:
	std::fstream file_;
	dword data_size_;
	dword sample_rate_;
	word channels_;
};

}; //namespace

#endif
