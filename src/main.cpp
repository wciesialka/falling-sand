/**
 * @file main.cpp
 * @brief Main driver file.
 * 
 * Establish screen rendering, run simulation, etc.
 * 
 * @date 2024-01-17
 * @author Willow Ciesialka
*/

#include <chrono>
#include <thread>

#include "sandrenderer/Renderer.hpp"
#include "sandrenderer/Pixel.hpp"
#include "fallingsand/Simulation.hpp"
#include "fallingsand/cells/CellFactory.hpp"

#define WIDTH 320
#define HEIGHT 320

const int TICK_RATE = 10;

void start_rendering(sandrenderer::Renderer* renderer){
    renderer->begin_rendering();
}

int main(){
    sandrenderer::Renderer* renderer = new sandrenderer::Renderer(WIDTH * sandrenderer::Pixel::ACTUAL_SIZE, HEIGHT * sandrenderer::Pixel::ACTUAL_SIZE);
    fallingsand::Simulation* simulation = new fallingsand::Simulation(1, WIDTH, HEIGHT); 
    renderer->add_renderable(simulation);

    fallingsand::CellFactory* factory = simulation->get_factory();
    for(int i = 120; i < 220; i++){
        for(int j = 100; j < 104; j++){
            factory->create(fallingsand::CellType::SAND, i, j);
        }
    }
    simulation->commit();

    sf::Thread render_thread(&start_rendering, renderer);
    render_thread.launch();

    while(renderer->is_open()){
        simulation->update_all();
        std::this_thread::sleep_for(std::chrono::milliseconds(TICK_RATE));
    }

    delete simulation;

    return 0;
}