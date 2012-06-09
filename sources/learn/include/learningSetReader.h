/** 
* @file
* Declaration of LearningSetReader class
*
* Parses given folder file structure building learning set based on its contents
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __LEARNING_SET_READER_H__
#define __LEARNING_SET_READER_H__

#include <memory>
#include <map>
#include "learningSample.h"

namespace learn
{

class LearningSetReader
{
public:
    bool initialize(const std::string& learningSetsFolder) throw(); /// parses given folder structure. Reads categories and file names. May throw. Returns true if files in correct file structure were found, false otherwise
    std::auto_ptr< std::vector<std::string> > getCategories() const throw(); /// returns smart pointer to vector of learning categories represented as text labels (taken from folder names)

	std::auto_ptr< LearningSample<std::string> > getNextLearningSample(); /// when class is initialized, every time it is called it returns another learning sample. May throw exceptions from FileReader

protected:
	std::multimap<std::string, std::string>	filesByCategory_; /// assigns path to the files to category labels
};

} //namespace

#endif
