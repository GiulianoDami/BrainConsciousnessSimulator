cpp
#ifndef CONSCIOUSNESSMETRICS_H
#define CONSCIOUSNESSMETRICS_H

#include "NeuralNetwork.h"
#include <vector>
#include <algorithm>
#include <numeric>

class ConsciousnessMetrics {
public:
    /**
     * Calculates the awareness level based on neural network activity
     * @param network The neural network to analyze
     * @return A double representing the awareness level (0.0 to 1.0)
     */
    static double calculateAwarenessLevel(const NeuralNetwork& network) {
        // Get all neuron activations
        const auto& activations = network.getActivations();
        
        if (activations.empty()) {
            return 0.0;
        }
        
        // Calculate average activation
        double avgActivation = std::accumulate(activations.begin(), activations.end(), 0.0) / activations.size();
        
        // Normalize to [0, 1] range
        double normalized = std::min(1.0, std::max(0.0, avgActivation));
        
        // Apply sigmoid-like transformation to emphasize higher activations
        return 1.0 / (1.0 + std::exp(-10.0 * (normalized - 0.5)));
    }
    
    /**
     * Calculates the integration metric based on neural network connectivity
     * @param network The neural network to analyze
     * @return A double representing the integration level (0.0 to 1.0)
     */
    static double calculateIntegration(const NeuralNetwork& network) {
        // Get the connection matrix
        const auto& connections = network.getConnections();
        
        if (connections.empty()) {
            return 0.0;
        }
        
        // Count total connections
        size_t totalConnections = 0;
        size_t activeConnections = 0;
        
        for (const auto& row : connections) {
            for (double weight : row) {
                totalConnections++;
                if (std::abs(weight) > 1e-6) { // Consider non-zero weights as active
                    activeConnections++;
                }
            }
        }
        
        if (totalConnections == 0) {
            return 0.0;
        }
        
        // Calculate integration as ratio of active connections
        double integration = static_cast<double>(activeConnections) / totalConnections;
        
        // Apply exponential decay to emphasize high integration
        return 1.0 - std::exp(-5.0 * integration);
    }
};

#endif // CONSCIOUSNESSMETRICS_H