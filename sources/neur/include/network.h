/** 
* @file
* Deklaracja klasy Network
* 
* Udostepnia interfejs pozwalajacy uzywac sieci neuronowej
*/

/// Lukasz Rychter
/// Maciej Sikora


#ifndef __NETWORK_H__
#define __NETWORK_H__

#include <list>
#include <memory> // dla auto_ptr
#include "baseLayer.h"

namespace neur /// Przestrzen nazw sieci neuronowej
{

/// Klasa reprezentujaca siec neuronowa
class Network
{
protected:
	std::list<std::auto_ptr<BaseLayer> >	layers_;	///< lista wskaznikow do warstw sieci
};

}; //namespace

#endif
