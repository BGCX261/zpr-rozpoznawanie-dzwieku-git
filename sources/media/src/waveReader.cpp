/** 
* @file
* Implementation of WaveReader class
* 
* Reads sounds from WAVE files
*/

/// Lukasz Rychter
/// Maciej Sikora

#include "stdafx.h"
#include "waveReader.h"

#include <cstring>
#include <stdexcept>

using namespace media;

const char * WaveReader::wav_id_value_ = "RIFF";
const char * WaveReader::wav_format_id_value_ = "WAVE";
const char * WaveReader::wav_description_value_ = "fmt ";
const char * WaveReader::wav_data_id_value_ = "data";

void WaveReader::openFile(const std::string& file)
{
	if (file_.is_open())
		file_.close();
	file_ = std::fstream(file, std::ios::in | std::ios::binary);
	if (file_.fail())
	{
		throw std::runtime_error("Opening file failed.");
	}
	const int size = 5;
	const char str_end = '\0';

	// Varbiable names correspond to WAV file header names.
	byte id[size], format[size], description[size], data_indicator[size];
	dword file_size, format_length, sample_rate, avg_bytes_per_sec, data_size;
	word format_tag, channels, block_align, bits_per_sample;

	file_.read(id, sizeof(byte) * 4);
	id[size - 1] = str_end;
	if (!strcmp(id, wav_id_value_))
	{
		file_.read((char *)&file_size, sizeof(dword));
		file_.read(format, sizeof(byte) * 4);
		format[size - 1] = str_end;
		if (!strcmp(format, wav_format_id_value_))
		{
			file_.read(description, sizeof(byte) * 4);
			description[size - 1] = str_end;
			if (!strcmp(description, wav_description_value_))
			{
				// It's now almost sure that this is a WAV file.
				file_.read((char *)&format_length, sizeof(dword));
				file_.read((char *)&format_tag, sizeof(word));
				file_.read((char *)&channels, sizeof(word));
				file_.read((char *)&sample_rate, sizeof(dword));
				file_.read((char *)&avg_bytes_per_sec, sizeof(dword));
				file_.read((char *)&block_align, sizeof(word));
				file_.read((char *)&bits_per_sample, sizeof(word));
				file_.read(data_indicator, sizeof(byte) * 4);
				data_indicator[size - 1] = str_end;
				if (strcmp(data_indicator, wav_data_id_value_))
				{ 
					// throw away additional params
					const int temp_size = 4;
					byte temp_byte;
					byte temp_buff[temp_size];
					while (!file_.eof())
					{
						file_.read(&temp_byte, sizeof(byte));
						// check first byte
						if (temp_byte == wav_data_id_value_[0]) // temp_byte == 'd'?
						{
							file_.read(temp_buff, sizeof(byte) * 3);
							temp_buff[temp_size - 1] = str_end;
							if (!strcmp(temp_buff, wav_data_id_value_ + 1)) // temp_buff == 'ata'?
								break;
						}
					}
					if (file_.eof())
						throw std::runtime_error("Bad file structure - no 'data' section");
				}

				file_.read((char *)&data_size, sizeof(dword));
				if (data_size < 0)
					throw std::runtime_error("Bad file structure - 'data size' is not positive");
				else
				{
					// we can set WaveReader object
					data_size_ = data_size;
					sample_rate_ = sample_rate;
					channels_ = channels;
				}
			}
			else
				throw std::runtime_error("Bad file structure - bad 'description' value");
		}
		else
			throw std::runtime_error("Bad file structure - bad 'format' value");
	}
	else
		throw std::runtime_error("Bad file structure - bad 'id' value");
}

void WaveReader::closeFile() 
{
	if (file_.is_open())
		file_.close();
}

void WaveReader::readTo(const AudioSample& buffer) 
{
	if (file_.is_open())
	{
		// TODO
		;
	}
	else
	{
		throw std::logic_error("Tried to read from file which isn't opened");
	}
}
