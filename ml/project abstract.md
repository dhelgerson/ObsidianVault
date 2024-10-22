# Abstract
The goal of this project is to develop a neural network-based system for removing background noise from an audio stream. This will be achieved through supervised learning, where the model is trained on recordings that consist of a known sound source mixed with various types of background noise. Each individual training process will be conducted in a known, consistent environment, allowing the network to be more precise and specialized. By providing the neural network with pairs of noisy and clean audio samples, it will learn to differentiate between the two. System evaluation will involve metrics such as signal-to-noise ratio (SNR) improvement and perceptual audio quality. The end goal of this project is to provide a robust method for removing unwanted artifacts from a microphone during recording and live communication. 

# Extended Abstract Outline

## 1. Introduction
- **Problem Statement**: many times, communication and recording need to take place in a consistent, but less than ideal environment such as home environments, work, etc.
- **Motivation**: a noisy audio source is very distracting. noisy audio contains more data, some unnecessary. by removing the unnecessary parts, we can also achieve a cleaner sound after compression. Other implementations attempt to create a "one size fits all" approach. we can create a much more flexible and precise system by training in the specific environment where the system will be implemented.
- **Objective**: we will develop a neural network-based system to remove background noise using supervised learning.

## 2. Methodology
- **2.1 Data Collection**
  - Describe the process of creating the dataset.
  - a dataset will be collected by creating professionally clean audio samples, mostly of human speech but some will also be of other desirable sounds to avoid over-fitting to the human voice.
  - Explain the known sound source and the types of background noise used.
  - Discuss how the recordings will be made in a known, consistent environment to ensure controlled conditions for training.
  
- **2.2 Neural Network Architecture**
  - Provide an overview of the neural network model (e.g., type of architecture, layers, etc.).
  - Mention the choice of architecture (e.g., convolutional neural networks, recurrent neural networks) and why it is suitable for audio processing.

- **2.3 Training Process**
  - Explain the concept of supervised learning in this context.
  - Describe how pairs of noisy and clean audio samples will be used to train the network.
  - Discuss any data augmentation techniques or preprocessing steps to improve the model’s generalization.

## 3. Evaluation
- **3.1 Performance Metrics**
  - Define the key metrics used to evaluate the system (e.g., signal-to-noise ratio (SNR) improvement, perceptual audio quality).
  - Explain how these metrics effectively measure the noise reduction capabilities of the model.
  
- **3.2 Testing Environment**
  - Describe how the system will be tested to ensure it performs reliably in different scenarios.
  - Include details on how well the model generalizes to unseen noise types or varied conditions within the known environment.

## 4. Results and Analysis (Placeholder)
- Summarize expected outcomes based on your approach.
- Briefly discuss how you will interpret the results once you conduct experiments.
- Mention any potential limitations you anticipate and how they might be addressed in future iterations.

## 5. Applications
- **5.1 Speech Processing**
  - Discuss the relevance of this system for enhancing speech in live communication scenarios.
  
- **5.2 Audio Recording**
  - Explain how this system can be beneficial for professional and consumer-level audio recordings.
  
- **5.3 Other Use Cases**
  - Mention additional fields where precise noise reduction is critical (e.g., hearing aids, call centers).

## 6. Conclusion
- **Summary**: Recap the main points of the extended abstract.
- **Future Work**: Highlight any future directions for improving or expanding the project.

## 7. References
- Provide a list of any relevant papers, articles, or resources you have referred to or plan to include in the extended abstract.
