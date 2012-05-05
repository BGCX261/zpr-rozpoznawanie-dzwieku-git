/** 
* @file
* Deklaracja klasy BaseLayer
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __BASE_LAYER_H__
#define __BASE_LAYER_H__

#include <list>
#include <memory> // dla auto_ptr
#include "neuron.h"

namespace neur
{

/// Klasa bazowa dla warstw w sieci neuronowej
class BaseLayer
{
protected:
	std::list<std::auto_ptr<Neuron>>	neurons_;	///< lista wskaznikow do neuronow warstwy
};

}; //namespace

#endif