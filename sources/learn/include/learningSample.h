/** 
* @file
* Declaration of LearningSample class - container for sample with assigned category
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __LEARNING_SAMPLE_H__
#define __LEARNING_SAMPLE_H__

#include <boost/smart_ptr/shared_ptr.hpp>
#include "fftSample.h"

namespace learn
{

template <typename LABEL=std::string>
class LearningSample
{
public:
	const boost::shared_ptr<FFTSample>	getSample() const { return sample_ }		/// accessor to the sample
	const LABEL							getCategory() const { return category_ }	/// accessor to the category

protected:
	boost::shared_ptr<FFTSample>	sample_;	/// smart pointer to the sample
	LABEL							category_;	///	 category assigned to the sample

};

}; //namespace

#endif