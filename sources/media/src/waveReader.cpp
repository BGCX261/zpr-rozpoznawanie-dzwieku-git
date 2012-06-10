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
#include <memory>

using namespace media;

const char* WaveReader::wav_id_value_ = "RIFF";
const char* WaveReader::wav_format_id_value_ = "WAVE";
const char* WaveReader::wav_description_value_ = "fmt ";
const char* WaveReader::wav_data_id_value_ = "data";
const long	WaveReader::wav_pcm_format_tag = 1;


void WaveReader::openFile(const std::string& file)
{
	if (file_.is_open())
		file_.close();
	file_.open(file.c_str(), std::ios::in | std::ios::binary);
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
				
				if (format_tag != wav_pcm_format_tag)
					throw std::runtime_error("Unsupported WAV file format");

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
					bits_per_sample_ = bits_per_sample;
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


void WaveReader::readTo(AudioSample& buffer, unsigned long audioTime)
{
	if (audioTime < 0)
		throw std::runtime_error("Bad argument audioTime value");
	else if (file_.is_open())
	{
		unsigned long bytes_to_process;
		if (audioTime == 0)
			bytes_to_process = data_size_;
		else
		{
			// audioTime is in miliseconds
			// (audioTime / 1000) * sample_rate_ * (bits_per_sample_ / 8)
			bytes_to_process = audioTime * sample_rate_ * bits_per_sample_ * channels_ / 8000;
			if (bytes_to_process > data_size_)
				throw std::runtime_error("Audio file hasn't got such many samples");
		}

	
		std::auto_ptr<byte> buf(new byte[bytes_to_process]);
		file_.read(buf.get(), bytes_to_process);
		if (file_.eof())
			throw std::out_of_range("Reached end of file before read desired length");
		if (file_.bad())
			throw std::runtime_error("Error while reading file");

		unsigned long samples = bytes_to_process/(bits_per_sample_/8);

		if (buffer.getElementSize() == bits_per_sample_/8)
			buffer.set((AudioSample::element_type*)buf.get(), samples);
		else
			throw std::runtime_error("Audio file has got unsupported bits per sample number"); //TODO - resize samples instead of throwing the error

		buffer.setSampleRate(sample_rate_);
		buffer.setChannels(channels_);
	}
	else
		throw std::logic_error("Tried to read from file which isn't opened");
}