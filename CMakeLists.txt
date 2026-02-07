cmake_minimum_required(VERSION 3.10)
project(BrainConsciousnessSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(glfw3 3.3 REQUIRED)
find_package(GLEW 2.0 REQUIRED)
find_package(glm REQUIRED)
find_package(nlohmann_json 3.7.0 REQUIRED)

# Add executable
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/NeuralNetwork.cpp
    src/BrainStimulator.cpp
    src/ConsciousnessAnalyzer.cpp
    src/Visualization.cpp
)

# Link libraries
target_link_libraries(${PROJECT_NAME} 
    glfw
    GLEW::GLEW
    glm::glm
    nlohmann_json::nlohmann_json
)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    include
    ${GLFW_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
    ${GLM_INCLUDE_DIRS}
    ${NLOHMANN_JSON_INCLUDE_DIRS}
)