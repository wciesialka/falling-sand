/**
 * @file Window.hpp
 * @brief Contains declerations of the Window class.
 * 
 * @date 2024-01-17
 * @author Willow Ciesialka
*/

#ifndef SANDRENDERER_WINDOW_H
#define SANDRENDERER_WINDOW_H

#include <SFML/Window.hpp>
#include "sandrenderer/Renderable.hpp"

namespace sandrenderer {
    class Window {
        public:
            Window(sf::Window* window) : window(window) {};
            Window(int width, int height, char* title) {
                this->window = new sf::Window(sf::VideoMode(width, height), title);
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
            sf::Window& get_window() const {
                return *(this->window);
            }
        private:
            sf::Window* window;
    };
}

#endif