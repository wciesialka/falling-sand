/**
 * @file Window.hpp
 * @brief Contains declerations of the Window class.
 * 
 * @date 2024-01-17
 * @author Willow Ciesialka
*/

#ifndef SANDRENDERER_WINDOW_H
#define SANDRENDERER_WINDOW_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Renderable.hpp"

namespace sandrenderer {
    /**
     * @brief Window class, wraps an \ref sf::RenderWindow.
    */
    class Window {
        public:
            static const sf::Uint32 WINDOW_FLAGS = sf::Style::Titlebar | sf::Style::Close;

            /**
             * @brief Construct the window.
             * 
             * @param width Width of the window (in px).
             * @param height Height of the window (in px).
             * @param title Window title.
            */
            Window(int width, int height, std::string title) {
                this->window = new sf::RenderWindow(sf::VideoMode(width, height), title, sandrenderer::Window::WINDOW_FLAGS);
            };

            /**
             * @brief Close and destruct window.
            */
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
             * 
             * @return Inner rendering window.
            */
            sf::RenderWindow& get_render_window() const {
                return *(this->window);
            }
        private:
            sf::RenderWindow* window;
    };
}

#endif