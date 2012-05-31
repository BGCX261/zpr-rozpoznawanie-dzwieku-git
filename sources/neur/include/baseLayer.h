/** 
* @file
* Declaration of BaseLayer class
*
* Base class for all layers in neural network
*/
/// Lukasz Rychter
/// Maciej Sikora


#ifndef __BASE_LAYER_H__
#define __BASE_LAYER_H__

#include <list>
#include <memory> // for auto_ptr
#include "neuron.h"

namespace neur
{

/// Base class for all layers in neural network
class BaseLayer
{
protected:
	std::list<std::auto_ptr<Neuron> >	neurons_;	///< list of pointers to neurons from this layer
};

}; //namespace

#endif
