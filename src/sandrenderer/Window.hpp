/**
 * @file Window.hpp
 * @brief Contains declerations of the Window class.
 * 
 * @date 2024-01-17
 * @author Willow Ciesialka
*/

#ifndef SANDRENDERER_WINDOW_H
#define SANDRENDERER_WINDOW_H

#include <SFML/Graphics.hpp>
#include "sandrenderer/Renderable.hpp"

namespace sandrenderer {
    class Window {
        public:
            static const sf::Uint32 WINDOW_FLAGS = sf::Style::Titlebar | sf::Style::Close;

            Window(sf::RenderWindow* window) : window(window) {};
            Window(int width, int height, char* title) {
                this->window = new sf::RenderWindow(sf::VideoMode(width, height), title, sandrenderer::Window::WINDOW_FLAGS);
            };
            ~Window() {
                this->close();
                delete this->window;
            };

            /**
             * @brief Close the window.
            */
            inline void close() {
                this->window->close();
            };

            /**
             * @brief Get the inner rendering window.
            */
            sf::RenderWindow& get_window() const {
                return *(this->window);
            }
        private:
            sf::RenderWindow* window;
    };
}

#endif