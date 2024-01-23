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
#include "fallingsand/cells/Sand.hpp"

#include <iostream>

#define WIDTH 640
#define HEIGHT 640

int main(){
    sandrenderer::Renderer* renderer = new sandrenderer::Renderer(WIDTH, HEIGHT);
    fallingsand::Simulation* simulation = new fallingsand::Simulation(1, WIDTH, HEIGHT); 

    std::cout << "Renderer and Simulation initialized." << std::endl;

    renderer->add_renderable(simulation);

    fallingsand::Sand* sand = new fallingsand::Sand();
    sand->set_position(10, 10);
    sand->commit();

    std::cout << "Sand initialized." << std::endl;

    simulation->add_particle(sand);

    std::cout << "Sand added to renderer." << std::endl;

    renderer->begin_rendering();

    delete renderer;
    delete simulation;

    return 0;
}