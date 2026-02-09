cpp
#include "config.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

using json = nlohmann::json;

Config loadConfig(const std::string& filename) {
    Config config;
    
    try {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open config file: " + filename);
        }
        
        json j;
        file >> j;
        
        // Load neural network settings
        if (j.contains("neural_network")) {
            const auto& nn = j["neural_network"];
            if (nn.contains("num_neurons")) {
                config.num_neurons = nn["num_neurons"].get<int>();
            }
            if (nn.contains("connection_probability")) {
                config.connection_probability = nn["connection_probability"].get<float>();
            }
            if (nn.contains("learning_rate")) {
                config.learning_rate = nn["learning_rate"].get<float>();
            }
        }
        
        // Load stimulation settings
        if (j.contains("stimulation")) {
            const auto& stim = j["stimulation"];
            if (stim.contains("frequency")) {
                config.stimulation_frequency = stim["frequency"].get<float>();
            }
            if (stim.contains("intensity")) {
                config.stimulation_intensity = stim["intensity"].get<float>();
            }
            if (stim.contains("duration")) {
                config.stimulation_duration = stim["duration"].get<float>();
            }
        }
        
        // Load consciousness metrics
        if (j.contains("consciousness_metrics")) {
            const auto& cm = j["consciousness_metrics"];
            if (cm.contains("threshold")) {
                config.consciousness_threshold = cm["threshold"].get<float>();
            }
            if (cm.contains("weight_decay")) {
                config.weight_decay = cm["weight_decay"].get<float>();
            }
        }
        
        // Load simulation parameters
        if (j.contains("simulation")) {
            const auto& sim = j["simulation"];
            if (sim.contains("time_step")) {
                config.time_step = sim["time_step"].get<float>();
            }
            if (sim.contains("total_time")) {
                config.total_time = sim["total_time"].get<float>();
            }
            if (sim.contains("output_interval")) {
                config.output_interval = sim["output_interval"].get<int>();
            }
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error loading config: " << e.what() << std::endl;
        // Return default config on error
    }
    
    return config;
}