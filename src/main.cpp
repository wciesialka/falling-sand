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
#include "fallingsand/Simulation.hpp"
#include "fallingsand/cells/CellFactory.hpp"

#define WIDTH 640
#define HEIGHT 640

const int TICK_RATE = 20;

void start_rendering(sandrenderer::Renderer* renderer, volatile bool &rendering_state){
    rendering_state = true;
    renderer->begin_rendering();
    rendering_state = false;
}

int main(){
    sandrenderer::Renderer* renderer = new sandrenderer::Renderer(WIDTH, HEIGHT);
    fallingsand::Simulation* simulation = new fallingsand::Simulation(1, WIDTH, HEIGHT); 
    renderer->add_renderable(simulation);

    fallingsand::CellFactory* factory = simulation->get_factory();
    factory->create(fallingsand::CellType::SAND, 300, 639);
    simulation->commit();

    volatile bool rendering_state = true;
    std::thread render_thread(start_rendering, renderer, std::ref(rendering_state));

    while(rendering_state){
        simulation->update_all();
        std::this_thread::sleep_for(std::chrono::milliseconds(TICK_RATE));
    }
    render_thread.join();

    delete simulation;

    return 0;
}