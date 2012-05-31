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

// TODO
#include <iostream>

using namespace media;

// Now it'll be like this.
std::string WaveReader::file_prefix_ = "";

void WaveReader::openFile(std::string file) 
{
	std::fstream wav_file(file, std::ios::in | std::ios::binary);
	if (wav_file.fail()) 
	{
		// TODO
		// throw exception
		std::cout << "blad przy konstrukcji!" << std::endl;
		return;
	}
	if (wav_file.is_open())
		std::cout << "success!" << std::endl;
	else
		std::cout << "blad przy otwieraniu!" << std::endl;
	char header_buffer[4];
	for (int i = 0; i < 4; ++i)
		header_buffer[i] = 0;
	wav_file.read(header_buffer, 4);
	std::cout.write(header_buffer, 4); // to 
	// TODO
	// hardcode path - to modify
	std::ofstream my_out_file("C:/Users/Maciek/Desktop/test.txt", std::ios::out | std::ios::binary);
	if (!my_out_file.fail() && my_out_file.is_open())
		std::cout << std::endl << "output ok" << std::endl;
	my_out_file.write(header_buffer, 4);
	if (!my_out_file.fail() && my_out_file.is_open())
		std::cout << "output po zapisie ok" << std::endl;
	wav_file.close();
	my_out_file.close();
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
