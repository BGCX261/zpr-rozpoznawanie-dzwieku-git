#include "stdafx.h"
#include "../include/waveReader.h"

// TODO
#include <iostream>

using namespace media;

// Now it's like this.
std::string WaveReader::file_prefix_ = "";

void WaveReader::openFile(std::string file) {
	std::fstream wav_file(file);
	if (wav_file.fail()) {
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
	std::cout.write(header_buffer, 4);
	std::ofstream my_out("test.txt", std::ios::in);
	if (!my_out.fail() && my_out.is_open())
		std::cout << std::endl << "output ok" << std::endl;
	my_out.write(header_buffer, 4);
	if (!my_out.fail() && my_out.is_open())
		std::cout << "output po zapisie ok" << std::endl;
	wav_file.close();
	my_out.close();
}

void WaveReader::closeFile() {
	// TODO
}

void WaveReader::readTo(const AudioSample& buffer) {
	// TODO
}

void WaveReader::waveReaderTests() {
	WaveReader *reader = new WaveReader();
	// TODO
	// hardcode path - to modify
	std::string file_name = "C:/Users/Maciek/Desktop/1.wav";
	reader->openFile(file_name);
	delete reader;
}
