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
void NeuralNetwork<LABEL>::initializeNetwork(unsigned long inputNeuronsNum, const std::vector<unsigned long>& hiddenLayersNeuronNums, const std::auto_ptr< std::set<LABEL> >& outputCategories)
{
	/// adding input layer
	std::auto_ptr<Layer> inputLayer(new Layer(InputLayerNeuron(), inputNeuronsNum));
	layers_.push_back(std::auto_ptr<Layer>(inputLayer));
	
	/// adding hidden layers
	for (std::vector<unsigned long>::const_iterator citer=hiddenLayersNeuronNums.begin(); citer!=hiddenLayersNeuronNums.end(); ++citer)
	{
		std::auto_ptr<Layer> hiddenLayer(new Layer(HiddenLayerNeuron(), *citer));
		layers_.push_back(std::auto_ptr<Layer>(hiddenLayer));
	}

	/// adding output layer
	std::auto_ptr<Layer> outputLayer(new Layer(OutputLayerNeuron<LABEL>(), outputCategories->size()));
	layers_.push_back(std::auto_ptr<Layer>(outputLayer));

	/// assigns categories to neurons from output layer
	std::list<std::auto_ptr<BaseNeuron> >& outputLayerNeurons = layers_.back()->neurons_;
	
	std::set<LABEL>::const_iterator category_iter = outputCategories.get()->begin();
	std::list<std::auto_ptr<BaseNeuron> >::iterator neuron_iter=outputLayerNeurons.begin();
	for (; neuron_iter!=outputLayerNeurons.end()/* && category_iter!=outputCategories.end()*/; ++neuron_iter, ++category_iter)
	{
		if (!neuron_iter->get())
			throw std::runtime_error("Missing neuron");
	
		neur::OutputLayerNeuron<LABEL>* outputNeuron = dynamic_cast< OutputLayerNeuron<LABEL>* >(neuron_iter->get());
		if (!outputNeuron)
			throw std::runtime_error("Neuron is not valid output layer neuron");

		outputNeuron->setCategory(*category_iter);
	}


	/// Connecting layers to each other
	for (std::list<std::auto_ptr<Layer> >::iterator iter=layers_.begin(); iter!=--layers_.end();)
	{
		(*iter)->connectWithNextLayer(*((iter++)->get()));
	}
}


template <typename LABEL>
void NeuralNetwork<LABEL>::learnPattern(const std::vector<float>& inputSignals, const ResultSet<LABEL>& desirableResult)
{
	if (!layers_.front().get())
		throw std::runtime_error("Neural network is not initialized");

	Layer& inputLayer = *layers_.front().get();

	/// passing inputs onto input layer
	std::list<std::auto_ptr<BaseNeuron> >& inputLayerNeurons = inputLayer.neurons_;

	do
	{
		std::vector<float>::const_iterator input_iter = inputSignals.begin();
		std::list<std::auto_ptr<BaseNeuron> >::iterator neuron_iter=inputLayerNeurons.begin();
		for (; neuron_iter!=inputLayerNeurons.end() && input_iter!=inputSignals.end(); ++neuron_iter, ++input_iter)
		{
			if (!neuron_iter->get())
				throw std::runtime_error("Missing neuron");
	
			neuron_iter->get()->processInput(*input_iter);
		}

		/// propagating signal through neural network
		for (std::list<std::auto_ptr<Layer> >::iterator iter=layers_.begin(); iter!=--layers_.end(); ++iter)
			iter->get()->propagateSignal();


		/// backpropagate learning info
		for (std::list<std::auto_ptr<Layer> >::reverse_iterator iter=layers_.rbegin(); iter!=--layers_.rend(); ++iter)
			iter->get()->propagateLearningResponse();
	} 
	while (0); //TODO add condition
}


template <typename LABEL>
std::auto_ptr< ResultSet<LABEL> > NeuralNetwork<LABEL>::recognizePattern(const std::vector<float>& inputSignals)
{
	if (!layers_.front().get())
		throw std::runtime_error("Neural network is not initialized");

	Layer& inputLayer = *layers_.front().get();

	/// passing inputs onto input layer
	std::list<std::auto_ptr<BaseNeuron> >& inputLayerNeurons = inputLayer.neurons_;

	std::vector<float>::const_iterator input_iter = inputSignals.begin();
	std::list<std::auto_ptr<BaseNeuron> >::iterator neuron_iter=inputLayerNeurons.begin();
	for (; neuron_iter!=inputLayerNeurons.end() && input_iter!=inputSignals.end(); ++neuron_iter, ++input_iter)
	{
		if (!neuron_iter->get())
			throw std::runtime_error("Missing neuron");
	
		neuron_iter->get()->processInput(*input_iter);
	}

	/// propagating signal through neural network
	for (std::list<std::auto_ptr<Layer> >::iterator iter=layers_.begin(); iter!=--layers_.end(); ++iter)
		iter->get()->propagateSignal();

	std::auto_ptr< ResultSet<LABEL> > resultSet(new ResultSet<LABEL>);


	std::list<std::auto_ptr<BaseNeuron> >& outputLayerNeurons = layers_.back()->neurons_;
	
	for (std::list<std::auto_ptr<BaseNeuron> >::const_iterator neuron_iter=outputLayerNeurons.begin(); 
		neuron_iter!=outputLayerNeurons.end(); 
		++neuron_iter)
	{
		if (!neuron_iter->get())
			throw std::runtime_error("Missing neuron");

		OutputLayerNeuron* outputNeuron= dynamic_cast<OutputLayerNeuron>(neuron_iter->get());
		if (!outputNeuron)
			throw std::runtime_error("Neuron is not valid output layer neuron");
	
		resultSet->getWritable()[outputNeuron->getCategory()] = outputNeuron->getValue();
	}
	
	return resultSet;
}


#endif