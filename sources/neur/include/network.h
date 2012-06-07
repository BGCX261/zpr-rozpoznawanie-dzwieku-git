/** 
* @file
* Declaration of Network class
*
* It represents whole neural network structure \n
* Provides interface to control the whole neural network
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __NETWORK_H__
#define __NETWORK_H__

#include <list>
#include <memory> // for auto_ptr
#include "baseLayer.h"
#include "resultSet.h"

namespace neur /// neural network namespace
{

/// Class representing whole neural network structure
class Network
{
protected:
	std::list<std::auto_ptr<BaseLayer> >	layers_;	///< list of pointers to layers of the neural network
};

}; //namespace

#endif
