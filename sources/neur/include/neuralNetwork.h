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

#include <set>
#include <list>
#include <memory> // for auto_ptr
#include "layer.h"
#include "resultSet.h"
#include "inputLayerNeuron.h"
#include "hiddenLayerNeuron.h"
#include "outputLayerNeuron.h"

namespace neur /// neural network namespace
{

/// Class representing whole neural network structure
template <typename LABEL=std::string>
class NeuralNetwork
{
public:
	void initializeNetwork(unsigned long inputNeuronsNum, const std::vector<unsigned long>& hiddenLayersNeuronNums, const std::auto_ptr< std::set<LABEL> >& outputCategories); /// initializes neural network with given number of inputs and outputs as given categories
	
	void								learnPattern(const std::vector<float>& inputSignals, const ResultSet<LABEL>& desirableResult); /// teaches neural network to recognize given input and produce desirable result mapping
	std::auto_ptr< ResultSet<LABEL> >	recognizePattern(const std::vector<float>& inputSignals); /// propagates input signals through neural network and returns recognition results

protected:
	std::list<std::auto_ptr<Layer> > layers_; ///< list of pointers to layers of the neural network
};

#include "neuralNetworkImpl.h"

} //namespace

#endif
