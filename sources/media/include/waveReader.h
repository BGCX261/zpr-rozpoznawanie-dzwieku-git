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
	
/// Declaration of class reading sounds from WAVE files.
class WaveReader : public SoundReader
{
public:
	/// Byte type definition.
	typedef char byte;
	/// Word type definition.
	typedef unsigned short word;
	/// Double word type definition.
	typedef unsigned int dword;

	static const char * wav_id_value_;
	static const char * wav_format_id_value_;
	static const char * wav_description_value_;
	static const char * wav_data_id_value_;

	/// Default constructor.
	/// Initializes object without connecting it with a file.
	WaveReader() : data_size_(0), channels_(0), sample_rate_(0), bits_per_sample_(0) {}
	/// Constructor which connects object with a file.
	/// After that it opens the file.
	WaveReader(const std::string& file) 
		: data_size_(0), channels_(0), sample_rate_(0), bits_per_sample_(0) { openFile(file); }
	/// Destructor.
	virtual ~WaveReader() { closeFile(); }

	/// Function reads audioTime miliseconds of audio data and writes it
	/// to the passed buffer. If audioTime is 0 (default) then it reads the whole file
	virtual void readTo(AudioSample& buffer, unsigned long audioTime=0);
	/// Function reads WAV file - it skips WAV headers and provides
	/// the object access to audio data.
	void openFile(const std::string& file);
	/// Cheks if object's file is open.
	bool is_open() { return file_.is_open() ? true : false; }
	/// Closes audio file.
	void closeFile();
	/// Gets size of read data.
	dword get_data_size() const;
	/// Gets sample rate of read data.
	dword get_sample_rate() const;
	/// Gets number of channels of read data.
	word get_channels() const;
	/// Gets number of bits per sample.
	word get_bits_per_sample() const;

protected:
	/// WAV file with audio data.
	std::fstream file_;
	/// Size of audio data.
	dword data_size_;
	/// Sample rate of audio data.
	dword sample_rate_;
	/// Number of channels of audio data.
	word channels_;
	/// Number of bits per audio sample.
	word bits_per_sample_;
};

}; //namespace

#endif
