cpp
#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <vector>
#include <random>
#include <glm/glm.hpp>
#include <nlohmann/json.hpp>

class NeuralNetwork {
private:
    std::vector<float> activations;
    std::vector<std::vector<float>> weights;
    std::vector<std::vector<float>> biases;
    std::mt19937 rng;
    std::uniform_real_distribution<float> dist;

public:
    NeuralNetwork(int numLayers, const std::vector<int>& layerSizes);
    void update();
    float getActivation(int index);
    void setActivation(int index, float value);
    void randomizeWeights(float scale = 1.0f);
    nlohmann::json toJson() const;
    void fromJson(const nlohmann::json& j);
};

#endif // NEURALNETWORK_H