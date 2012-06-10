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
	typedef char byte; /// Byte type definition.
	typedef unsigned short word; /// Word type definition.
	typedef unsigned int dword; /// Double word type definition.

	static const char*	wav_id_value_;
	static const char*	wav_format_id_value_;
	static const char*	wav_description_value_;
	static const char*	wav_data_id_value_;
	static const long	wav_pcm_format_tag;

	/// Default constructor.
	/// Initializes object without connecting it with a file.
	WaveReader() : data_size_(0), channels_(0), sample_rate_(0), bits_per_sample_(0) {}

	/// Constructor which connects object with a file.
	/// After that it opens the file.
	WaveReader(const std::string& file) : data_size_(0), channels_(0), sample_rate_(0), bits_per_sample_(0) 
	{ 
		openFile(file); 
	}
	
	/// Destructor.
	virtual ~WaveReader() 
	{ 
		closeFile(); 
	}

	/// Function reads audioTime miliseconds of audio data and writes it
	/// to the passed buffer. If audioTime is 0 (default) then it reads the whole file
	virtual void readTo(AudioSample& buffer, unsigned long audioTime=0);

	/// Function reads WAV file - it parses WAV headers and provides access to audio data
	void openFile(const std::string& file);

	/// Cheks if object's file is open
	bool is_open() { return file_.is_open() ? true : false; }
	
	/// Closes audio file
	void closeFile();


	dword	get_data_size() const { return data_size_; } /// Gets size of read data
	dword	get_sample_rate() const { return sample_rate_; } /// Gets sample rate of read data
	word	get_channels() const { return channels_; } /// Gets number of channels of read data
	word	get_bits_per_sample() const { return bits_per_sample_; } /// Gets number of bits per sample

protected:
	std::fstream	file_; /// WAV file with audio data
	dword			data_size_; /// Size of audio data
	dword			sample_rate_; /// Sample rate of audio data
	word			channels_; /// Number of channels of audio data
	word			bits_per_sample_; /// Number of bits per audio sample
};

}; //namespace

#endif
