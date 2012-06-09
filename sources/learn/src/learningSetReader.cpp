/** 
* @file
* Implementation of LearningSetReader class
* 
* Parses given folder file structure building learning set based on its contents
*/

/// Lukasz Rychter
/// Maciej Sikora

#include <stdexcept>
#include "stdafx.h"
#include "learningSetReader.h"

using namespace learn;
using namespace std;


bool LearningSetReader::initialize(const std::string& learningSetsFolder) throw ()
{
    /* if(1 == 2)
        throw std::exception; */
    return false; //TODO
}


auto_ptr< std::vector<string> > LearningSetReader::getCategories() const throw()
{
    /* if(1 == 2)
        throw std::exception; */
    return auto_ptr< std::vector<string> >(); //TODO
}


auto_ptr< LearningSample<string> > LearningSetReader::getNextLearningSample()
{
	return auto_ptr< LearningSample<string> >(); //TODO
}
