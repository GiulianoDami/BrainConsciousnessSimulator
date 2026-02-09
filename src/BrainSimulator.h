cpp
#ifndef BRAINSIMULATOR_H
#define BRAINSIMULATOR_H

#include "NeuralNetwork.h"
#include "StimulationModel.h"

class BrainSimulator {
public:
    void run(NeuralNetwork& network, StimulationModel& stimulation, int iterations);
};

#endif // BRAINSIMULATOR_H