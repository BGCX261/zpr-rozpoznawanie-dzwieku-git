/** 
* @file
* Declaration of ResultSet class
*
* It represent results of sample catogirization done by neural network \n
* Results are stored as percentage fitting of sample to each category
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __RESULT_SET_H__
#define __RESULT_SET_H__

#include <map>


namespace neur
{
	class Network;

/// Class representing results of sample catogirization done by neural network
template <typename LABEL=std::string>
class ResultSet
{
public:
	unsigned int	getCategoriesNum() const throw() { return results_.size(); } /// returns number of result categories
	float			getCategoryResult(const LABEL& label) const throw(...) /// retuns percentage fitting for given category. May throw std::invalid_argument if result for given category doesn't exists
	{  
		std::map<LABEL, float>::iterator iter;
		iter = results_.find(label);
		if (iter != results_.end())
			return iter->second;
		else
			throw std::invalid_argument();
	}

	const std::map<LABEL, float>& getResults() const throw() { return results_; } /// returns const reference to results

protected:
	std::map<LABEL, float> results_;

friend class neur::Network; /// giving direct access to members for the friend class
};

}; //namespace

#endif