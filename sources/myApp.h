/** 
* @file
* Declaration of MyApp class - base class for application, controlling learning/classifying process 
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __MY_APP_H__
#define __MY_APP_H__

#include <boost\smart_ptr\shared_ptr.hpp>
#include "neur\include\network.h"

class MyApp
{
public:
	void setLearningSetsFolder(const std::string& learningSetsFolder) throw() { learningSetsFolder_ = learningSetsFolder; } /// sets folder from which to read learning sets
	
	const neur::ResultSet<> doCategorizeFile(const std::string& filePath) throw(...); /// examines sound sample from file with learned neural network

protected:
	std::string							learningSetsFolder_; /// path to a folder with lerning sets
	boost::shared_ptr<neur::Network>	neuralNetwork_; /// pointer to learned neural network
};

#endif