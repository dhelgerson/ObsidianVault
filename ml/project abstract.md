# Abstract
The goal of this project is to develop a neural network-based system for removing background noise from an audio stream. This will be achieved through supervised learning, where the model is trained on recordings that consist of a known sound source mixed with various types of background noise. Each individual training process will be conducted in a known, consistent environment, allowing the network to be more precise and specialized. By providing the neural network with pairs of noisy and clean audio samples, it will learn to differentiate between the two. System evaluation will involve metrics such as signal-to-noise ratio (SNR) improvement and perceptual audio quality. The end goal of this project is to provide a robust method for removing unwanted artifacts from a microphone during recording and live communication. 

# Extended Abstract Outline

## 1. Introduction
- **Problem Statement**: many times, communication and recording need to take place in a consistent, but less than ideal environment such as home environments, work, etc.
- **Motivation**: a noisy audio source is very distracting. noisy audio contains more data, some unnecessary. by removing the unnecessary parts, we can also achieve a cleaner sound after compression. Other implementations attempt to create a "one size fits all" approach. we can create a much more flexible and precise system by training in the specific environment where the system will be implemented.
- **Objective**: we will develop a neural network-based system to remove background noise using supervised learning.

## 2. Methodology
- **2.1 Data Collection**
  - a dataset will be collected by creating professionally clean audio samples, mostly of human speech but some will also be of other desirable sounds to avoid over-fitting to the human voice.
  - Then, the known samples being played and the noisy environment will be recorded in the desired recording setup for the environment.
  - This will create a dataset of noisy samples and their desired outcome, the original sound.
  
- **2.2 Neural Network Architecture**
  - since the goal of this system is to be transparently used in practice, the architecture of the neural network needs to be as simple as possible to improve runtime. to start with, 10% of my GPU or 20% of my CPU will be targeted. if desirable results aren't achieved, neural network complexity will be increased. 
  - the specific neural network architecture hasn't been decided yet. to start, both convolutional  and recurrent neural networks will be tested.

- **2.3 Training Process**
  - supervised learning was chosen for this project because both the input and desired output can be obtained
  - since the pairs are known, training is as simple as running the system on the input, evaluating the error, and adjusting the weights
 - ideally, the model will be able to handle any reasonable volume saturation withing 16-bit audio. however, to start training, the samples will be normalized to hopefully allow a quicker error falloff.
## 3. Evaluation
- **3.1 Performance Metrics**
  - defining our error will be quite simple. there are pre-existing tools for evaluating perceived loudness of an audio signal. what we will do is subtract the desired signal from the recorded, noisy signal, and use those tools to evaluate the loudness of the remaining signal.
  - this method should effectively evaluate the loudness of the noise that we don't want. ideally, this loudness should be as low as possible.
  
- **3.2 Testing Environment**
   - the system will be tested by processing new input. since the training data will be based on a specific environment, it's trivial for me to test it when needed. 
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
