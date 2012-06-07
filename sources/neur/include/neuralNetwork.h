/** 
* @file
* Declaration of NeuralNetwork class
*
* It represents whole neural network structure \n
* Provides interface to control the whole neural network
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __NEURAL_NETWORK_H__
#define __NEURAL_NETWORK_H__

#include <list>
#include <memory> // for auto_ptr
#include "baseLayer.h"
#include "resultSet.h"

namespace neur /// neural network namespace
{

/// Class representing whole neural network structure
class NeuralNetwork
{
protected:
	std::list<std::auto_ptr<BaseLayer> >	layers_;	///< list of pointers to layers of the neural network
};

}; //namespace

#endif
