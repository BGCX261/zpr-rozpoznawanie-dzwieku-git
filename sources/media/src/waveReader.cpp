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
// TODO
#include <iostream>

using namespace media;

const char * WaveReader::wav_id_value_ = "RIFF";
const char * WaveReader::wav_format_id_value_ = "WAVE";
const char * WaveReader::wav_description_value_ = "fmt ";
const char * WaveReader::wav_data_id_value_ = "data";

void WaveReader::openFile(std::string file) 
{
	file_ = std::fstream(file, std::ios::in | std::ios::binary);
	if (file_.fail()) 
	{
		// TODO
		// throw exception
		return;
	}
	const int size = 5;
	const char str_end = '\0';
	// Varbiable names correspond to WAV file header names.
	byte id[size], format[size], description[size], data_indicator[size];
	dword file_size, format_length, sample_rate, avg_bytes_per_sec;
	word format_tag, channels, block_align, bits_per_sample;

	file_.read(id, sizeof(byte) * 4);
	id[size - 1] = str_end;
	if (!strcmp(id, wav_id_value_))
	{
		file_.read((char *)&file_size, sizeof(dword)); // read 4 bytes
		file_.read(format, sizeof(byte) * 4);
		format[size - 1] = str_end;
		if (!strcmp(format, wav_format_id_value_))
		{
			file_.read(description, sizeof(byte) * 4);
			description[size - 1] = str_end;
			if (!strcmp(description, wav_description_value_))
			{
				// It's is almost sure that this is a WAV file.
				file_.read((char *)&format_length, sizeof(dword)); // read 4 bytes
				file_.read((char *)&format_tag, sizeof(word)); // read 2 bytes
				file_.read((char *)&channels, sizeof(word));
				file_.read((char *)&sample_rate, sizeof(dword));
				file_.read((char *)&avg_bytes_per_sec, sizeof(dword));
				file_.read((char *)&block_align, sizeof(word));
				file_.read((char *)&bits_per_sample, sizeof(word));
				file_.read(data_indicator, sizeof(byte) * 4);
				data_indicator[size - 1] = str_end;
				if (strcmp(data_indicator, wav_data_id_value_))
				{ // throw away additional params
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
								// it's fine - after that we'll have audio data
								break;
						}
					}
					if (file_.eof())
						// TODO
						// wyjatek - zly plik
						;
				}

				file_.read((char *)&data_size_, sizeof(dword));
				if (data_size_ < 0)
					// TODO
					// wyjatek - zly rozmiar danych
					;
			}
			else // there is no 'fmt ' in headers
				// TODO
				// wyjatek - bledny naglowek
				;
		}
		else // there is no 'WAVE' in headers
			// TODO
			// wyjatek - bledny naglowek
			;
	}
	else // there is no 'RIFF' in headers
		// TODO
		// wyjatek - bledny naglowek
		;
}

void WaveReader::closeFile() 
{
	// TODO
}

void WaveReader::readTo(const AudioSample& buffer) 
{
	// TODO
}

void WaveReader::waveReaderTests() 
{
	WaveReader *reader = new WaveReader();
	// TODO
	// hardcode path - to modify
	std::string file_name = "C:/Users/Maciek/Desktop/1.wav";
	reader->openFile(file_name);
	delete reader;
}
