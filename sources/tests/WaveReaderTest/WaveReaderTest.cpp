// generating main function
#define BOOST_TEST_MAIN
// enabling dynamic linking
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include "waveReader.h"

using namespace media;
using namespace boost::unit_test;
using namespace boost::unit_test_framework;

BOOST_AUTO_TEST_SUITE(wave_reader_test)

BOOST_AUTO_TEST_CASE(test_default_initialization)
{
	WaveReader reader;
	BOOST_CHECK_EQUAL(reader.is_open(), false);
	BOOST_CHECK_EQUAL(reader.get_data_size(), 0);
	BOOST_CHECK_EQUAL(reader.get_sample_rate(), 0);
	BOOST_CHECK_EQUAL(reader.get_channels(), 0);
	BOOST_CHECK_EQUAL(reader.get_bits_per_sample(), 0);
}

BOOST_AUTO_TEST_CASE(test_object_after_open_file)
{
	WaveReader reader;
	reader.openFile("sources/tests/WaveReaderTest/data/1.wav");
	BOOST_CHECK_EQUAL(reader.is_open(), true);
	
	// Object fields must be properly set by now.
	BOOST_CHECK_GT(reader.get_data_size(), 0U);
	BOOST_CHECK_GT(reader.get_sample_rate(), 0U);
	BOOST_CHECK_GT(reader.get_channels(), 0U);
	BOOST_CHECK_GT(reader.get_bits_per_sample(), 0U);
}

BOOST_AUTO_TEST_CASE(test_object_after_construction_with_file)
{
	WaveReader reader("sources/tests/WaveReaderTest/data/1.wav");
	BOOST_CHECK_EQUAL(reader.is_open(), true);
	
	// Object fields must be properly set by now.
	BOOST_CHECK_GT(reader.get_data_size(), 0U);
	BOOST_CHECK_GT(reader.get_sample_rate(), 0U);
	BOOST_CHECK_GT(reader.get_channels(), 0U);
	BOOST_CHECK_GT(reader.get_bits_per_sample(), 0U);
}

BOOST_AUTO_TEST_CASE(test_open_another_file)
{
	WaveReader reader("sources/tests/WaveReaderTest/data/1.wav");
	int old_channels = reader.get_channels();
	int old_data_size = reader.get_data_size();
	int old_sample_rate = reader.get_sample_rate();
	int old_bits_per_sample = reader.get_bits_per_sample();
	
	// Load new file.
	reader.openFile("sources/tests/WaveReaderTest/data/2.wav");
	BOOST_CHECK_EQUAL(reader.is_open(), true);
	int new_channels = reader.get_channels();
	int new_data_size = reader.get_data_size();
	int new_sample_rate = reader.get_sample_rate();
	int new_bits_per_sample = reader.get_bits_per_sample();

	// Check if file has been changed.
	BOOST_CHECK_EQUAL(reader.get_channels() != old_channels ||
		reader.get_sample_rate() != old_sample_rate ||
		reader.get_data_size() != old_data_size ||
		reader.get_bits_per_sample() != old_bits_per_sample, true);
}

BOOST_AUTO_TEST_CASE(test_open_bad_file)
{
	WaveReader reader;
	std::string fake_file("this/file/doesnt/exist");
	BOOST_CHECK_THROW(reader.openFile(fake_file), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(test_open_inappropriate_file)
{
	WaveReader reader;
	std::string fake_file("sources/tests/WaveReaderTest/data/inappropriate.txt");
	BOOST_CHECK_THROW(reader.openFile(fake_file), std::runtime_error);
	BOOST_CHECK(reader.is_open());
}

BOOST_AUTO_TEST_CASE(test_read_whole_file)
{
	WaveReader reader("sources/tests/WaveReaderTest/data/1.wav");
	AudioSample buffer;
	BOOST_CHECK_NO_THROW(reader.readTo(buffer));
}

BOOST_AUTO_TEST_CASE(test_read_after_reading)
{
	WaveReader reader("sources/tests/WaveReaderTest/data/1.wav");
	AudioSample buffer;
	BOOST_CHECK_NO_THROW(reader.readTo(buffer));
	BOOST_CHECK_THROW(reader.readTo(buffer), std::out_of_range); 
}

BOOST_AUTO_TEST_CASE(test_data_correctness)
{
	WaveReader reader("sources/tests/WaveReaderTest/data/synthetic.wav");
	AudioSample buffer;
	BOOST_CHECK_NO_THROW(reader.readTo(buffer));
	BOOST_CHECK_EQUAL(buffer.get().front(), 0x1234);
	BOOST_CHECK_EQUAL(buffer.get()[1000], 0); // some random position inside
	BOOST_CHECK_EQUAL(buffer.get().back(), 0x4321);

}

// to easily run test from exe file
#ifdef _WIN32
BOOST_AUTO_TEST_CASE(wait)
{
	std::cout << std::endl;
	system("PAUSE");
}
#endif

BOOST_AUTO_TEST_SUITE_END()
