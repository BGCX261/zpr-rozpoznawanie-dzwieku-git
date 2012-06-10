/** 
* @file
* Implementation of Network class
* 
* It represents whole neural network structure \n
* Provides interface to control the whole neural network
*/

/// Lukasz Rychter
/// Maciej Sikora

#ifndef __NEURAL_NETWORK_IMPL_H__
#define __NEURAL_NETWORK_IMPL_H__

template <typename LABEL>
void NeuralNetwork<LABEL>::initializeNetwork(unsigned long inputNeuronsNum, const std::auto_ptr< std::set<LABEL> >& outputCategories)
{
	//TODO
}


template <typename LABEL>
void NeuralNetwork<LABEL>::learnPattern(const std::vector<float>& inputSignals, const ResultSet<LABEL>& desirableResult)
{

}


template <typename LABEL>
std::auto_ptr<ResultSet<LABEL>>	NeuralNetwork<LABEL>::recognizePattern(const std::vector<float>& inputSignals)
{
	return std::auto_ptr<ResultSet<LABEL>>; //TODO
}


#endif