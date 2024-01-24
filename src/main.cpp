/**
 * @file main.cpp
 * @brief Main driver file.
 * 
 * Establish screen rendering, run simulation, etc.
 * 
 * @date 2024-01-17
 * @author Willow Ciesialka
*/

#include "sandrenderer/Renderer.hpp"
#include "fallingsand/Simulation.hpp"
#include "fallingsand/cells/CellFactory.hpp"

#include <iostream>

#define WIDTH 640
#define HEIGHT 640

int main(){
    sandrenderer::Renderer* renderer = new sandrenderer::Renderer(WIDTH, HEIGHT);
    fallingsand::Simulation* simulation = new fallingsand::Simulation(1, WIDTH, HEIGHT); 
    renderer->add_renderable(simulation);

    fallingsand::CellFactory factory = simulation->get_factory();
    factory.create(fallingsand::CellType::WALL, 10, 10);

    std::cout << "Hi!" << std::endl;

    renderer->begin_rendering();

    delete renderer;
    delete simulation;

    return 0;
}