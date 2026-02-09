cpp
#ifndef STIMULATION_MODEL_H
#define STIMULATION_MODEL_H

#include <string>
#include <memory>
#include "NeuralNetwork.h"

class StimulationModel {
private:
    std::string region;
    float intensity;
    
public:
    StimulationModel() : region(""), intensity(0.0f) {}
    
    void applyStimulation(NeuralNetwork& network);
    void setRegion(const std::string& region);
    void setIntensity(float intensity);
};

#endif // STIMULATION_MODEL_H