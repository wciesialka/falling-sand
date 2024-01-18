/**
 * @file Renderer.cpp
 * @brief This file contains definitions for the Renderer class.
 * 
 * @date 2024-01-17
 * @author Willow Ciesialka
*/

#include "sandrenderer/Renderer.hpp"

void sandrenderer::Renderer::render() const {
    sf::RenderWindow& render_window = this->window->get_window();
    while (render_window.isOpen())
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
    }
}