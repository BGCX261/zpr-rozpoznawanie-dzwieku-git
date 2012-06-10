/** 
* @file
* Declaration of Layer class
*
* Class representing layer in a neural network
*/
/// Lukasz Rychter
/// Maciej Sikora


#ifndef __LAYER_H__
#define __LAYER_H__

#include <list>
#include <memory> // for auto_ptr
#include "baseNeuron.h"

namespace neur
{

/// Class representing layer in a neural network
class Layer
{
protected:
	std::list<std::auto_ptr<BaseNeuron> >	neurons_; ///< list of pointers to neurons from this layer
};

}; //namespace

#endif
