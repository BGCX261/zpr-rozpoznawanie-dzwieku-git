/** 
* @file
* Declaration of FFT class
*
* Provides functions to convert signal into its spectrum using Fast Fourier Transform algorithm
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __FFT_H__
#define __FFT_H__

#include <memory>
#include "fftSample.h"
#include "audioSample.h"

namespace media
{

/// Class providing functions to convert signal into its spectrum using Fast Fourier Transform algorithm. Singleton.
class FFT
{
private:
	FFT() {} /// private empty constructor - for singleton.

public:
	static FFT& getInstance(); /// gets singleton instance. Initializes singleton if it was not yet created. May throw bad_alloc

	static void initialize(); /// initializes singleton if it was not yet created. May throw bad_alloc. User do not have to call this, may use getInstance instead.
	static void deinitialize() throw(); /// destroys singleton

	std::auto_ptr<FFTSample> calculateFFT(const AudioSample& audio); /// calculates FFT of provided audio sample. May throw

protected:
	static FFT* instance_;
};

}; //namespace

#endif