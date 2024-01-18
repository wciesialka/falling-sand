/**
 * @file Renderable.hpp
 * @brief Contains declerations for the Renderable interface.
 * 
 * @date 2024-01-17
 * @author Willow Ciesialka
*/

#ifndef SANDRENDERER_RENDERABLE_H
#define SANDRENDERER_RENDERABLE_H

#include <SFML/Window.hpp>

namespace sandrenderer {
    /**
     * @brief Interface for an object that is renderable on the screen.
    */
    class Renderable {
        /**
         * @brief Render the renderable object onto a screen. Every renderable
         * object must implement this method.
         * 
         * @param window SFML Window to render onto. 
        */
        virtual void render(const sf::Window& window) const = 0;
    };
}

#endif