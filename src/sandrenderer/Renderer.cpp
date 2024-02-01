/**
 * @file Renderer.cpp
 * @brief This file contains definitions for the Renderer class.
 * 
 * @date 2024-01-17
 * @author Willow Ciesialka
*/

#include "Renderer.hpp"

#include <chrono>
#include <thread>
#include <unistd.h>
#include <iostream>

const int TICK_RATE = 16;

void sandrenderer::Renderer::begin_rendering() {
    sf::RenderWindow& render_window = this->get_window()->get_render_window();
    while (this->is_open())
    {
        sf::Event event;
        while (render_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                this->window->close();
                continue;
            }
        }
        render_window.clear(sf::Color::Black);

        for(sandrenderer::Renderable* renderable : *(this->renderables)){
            renderable->render(render_window);
        }
        render_window.display();
        //std::this_thread::sleep_for(std::chrono::milliseconds(TICK_RATE));
    }
}