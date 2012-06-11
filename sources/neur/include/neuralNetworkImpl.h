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
	layers_.clear();

	if (inputNeuronsNum == 0)
		throw std::invalid_argument("Neurons number for input layer cannot be 0");

	/// adding input layer
	boost::shared_ptr<Layer> inputLayer(new Layer(InputLayerNeuron(), inputNeuronsNum));
	layers_.push_back(inputLayer);
	
	/// adding hidden layers
	for (std::vector<unsigned long>::const_iterator citer=hiddenLayersNeuronNums.begin(); citer!=hiddenLayersNeuronNums.end(); ++citer)
	{
		unsigned long layerNeuronsNum = *citer;
		if (layerNeuronsNum == 0)
			throw std::invalid_argument("Neurons number for hidden layer cannot be 0");

		boost::shared_ptr<Layer> hiddenLayer(new Layer(HiddenLayerNeuron(), layerNeuronsNum));
		layers_.push_back(hiddenLayer);
	}

	/// adding output layer
	unsigned long outputNeuronsNum = outputCategories->size();
	if (outputNeuronsNum == 0)
		throw std::invalid_argument("There must be at least one output category (two to do anything practical)");

	boost::shared_ptr<Layer> outputLayer(new Layer(OutputLayerNeuron<LABEL>(), outputNeuronsNum));
	layers_.push_back(outputLayer);


	/// assigns categories to neurons from output layer
	std::list< boost::shared_ptr<BaseNeuron> >& outputLayerNeurons = layers_.back()->neurons_;
	
    typename std::set<LABEL>::const_iterator category_iter = outputCategories.get()->begin();
	std::list< boost::shared_ptr<BaseNeuron> >::iterator neuron_iter=outputLayerNeurons.begin();
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
	for (std::list< boost::shared_ptr<Layer> >::iterator iter=layers_.begin(); iter!=--layers_.end(); ++iter)
	{
		std::list< boost::shared_ptr<Layer> >::iterator next_layer_iter = iter;
		++next_layer_iter;
		(*iter)->connectWithNextLayer(*(next_layer_iter->get()));
	}
}


template <typename LABEL>
void NeuralNetwork<LABEL>::resetNeuronsValue()
{
	for (std::list< boost::shared_ptr<Layer> >::iterator iter=layers_.begin(); iter!=layers_.end(); ++iter)
	{
		if (!iter->get())
			throw std::runtime_error("Missing layer");
		
		iter->get()->resetNeuronsValue();
	}
}


template <typename LABEL>
void NeuralNetwork<LABEL>::propagateSignal()
{
	/// propagating signal through neural network
	for (std::list< boost::shared_ptr<Layer> >::iterator iter=layers_.begin(); iter!=--layers_.end(); ++iter)
	{
		if (!iter->get())
			throw std::runtime_error("Missing layer");
		
		iter->get()->propagateSignal();
	}
}


template <typename LABEL>
void NeuralNetwork<LABEL>::learnPattern(const std::vector<float>& inputSignals, const ResultSet<LABEL>& desirableResult)
{
	if (!layers_.size() || !layers_.front().get())
		throw std::runtime_error("Neural network is not initialized");


	/// sets desirable results to outputs
	std::list< boost::shared_ptr<BaseNeuron> >& outputLayerNeurons = layers_.back()->neurons_;
	
	for (std::list< boost::shared_ptr<BaseNeuron> >::const_iterator neuron_iter=outputLayerNeurons.begin(); 
		neuron_iter!=outputLayerNeurons.end(); 
		++neuron_iter)
	{
		if (!neuron_iter->get())
			throw std::runtime_error("Missing neuron");

		OutputLayerNeuron<LABEL>* outputNeuron= dynamic_cast< OutputLayerNeuron<LABEL>* >(neuron_iter->get());
		if (!outputNeuron)
			throw std::runtime_error("Neuron is not valid output layer neuron");
	
		outputNeuron->setDesiredValue( desirableResult.getCategoryResult(outputNeuron->getCategory() ) );
	}


	/// passing inputs onto input layer
	Layer& inputLayer = *layers_.front().get();
	std::list< boost::shared_ptr<BaseNeuron> >& inputLayerNeurons = inputLayer.neurons_;

	do
	{
		resetNeuronsValue();

		std::vector<float>::const_iterator input_iter = inputSignals.begin();
		std::list< boost::shared_ptr<BaseNeuron> >::iterator neuron_iter=inputLayerNeurons.begin();
		for (; neuron_iter!=inputLayerNeurons.end() && input_iter!=inputSignals.end(); ++neuron_iter, ++input_iter)
		{
			if (!neuron_iter->get())
				throw std::runtime_error("Missing neuron");
	
			neuron_iter->get()->processInput(*input_iter);
		}
				
		propagateSignal();
				
		/// backpropagate learning info
		for (std::list< boost::shared_ptr<Layer> >::reverse_iterator iter=layers_.rbegin(); iter!=--layers_.rend(); ++iter)
			iter->get()->propagateLearningResponse(learningFactor_);
	} 
	while (0); //TODO add condition maybe
}


template <typename LABEL>
std::auto_ptr< ResultSet<LABEL> > NeuralNetwork<LABEL>::recognizePattern(const std::vector<float>& inputSignals)
{
	if (!layers_.front().get())
		throw std::runtime_error("Neural network is not initialized");

	resetNeuronsValue();

	/// passing inputs onto input layer
	Layer& inputLayer = *layers_.front().get();
	std::list< boost::shared_ptr<BaseNeuron> >& inputLayerNeurons = inputLayer.neurons_;

	std::vector<float>::const_iterator input_iter = inputSignals.begin();
	std::list< boost::shared_ptr<BaseNeuron> >::iterator neuron_iter=inputLayerNeurons.begin();
	for (; neuron_iter!=inputLayerNeurons.end() && input_iter!=inputSignals.end(); ++neuron_iter, ++input_iter)
	{
		if (!neuron_iter->get())
			throw std::runtime_error("Missing neuron");
	
		neuron_iter->get()->processInput(*input_iter);
	}

	propagateSignal();

	std::auto_ptr< ResultSet<LABEL> > resultSet(new ResultSet<LABEL>);
	std::list< boost::shared_ptr<BaseNeuron> >& outputLayerNeurons = layers_.back()->neurons_;
	
	for (std::list< boost::shared_ptr<BaseNeuron> >::const_iterator neuron_iter=outputLayerNeurons.begin(); 
		neuron_iter!=outputLayerNeurons.end(); 
		++neuron_iter)
	{
		if (!neuron_iter->get())
			throw std::runtime_error("Missing neuron");

		OutputLayerNeuron<LABEL>* outputNeuron= dynamic_cast< OutputLayerNeuron<LABEL>* >(neuron_iter->get());
		if (!outputNeuron)
			throw std::runtime_error("Neuron is not valid output layer neuron");
	
		resultSet->getWritable()[outputNeuron->getCategory()] = (float)(outputNeuron->getValue());
	}
	
	return resultSet;
}


#endif
