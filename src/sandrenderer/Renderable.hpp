/**
 * @file Renderable.hpp
 * @brief Contains declerations for the Renderable interface.
 * 
 * @date 2024-01-17
 * @author Willow Ciesialka
*/

#ifndef SANDRENDERER_RENDERABLE_H
#define SANDRENDERER_RENDERABLE_H

#include <SFML/Graphics.hpp>
namespace sandrenderer {
    /**
     * @brief Interface for an object that is renderable on the screen.
    */
    class Renderable {
        public:
            virtual ~Renderable() {};

            /**
             * @brief Render the renderable object onto a screen. Every renderable
             * object must implement this method.
             * 
             * @param window SFML Window to render onto. 
            */
            virtual void render(sf::RenderWindow& window) const = 0;

            /**
             * @brief Set the position of the pixel on the screen.
             *
             * @param value New position.
             */
            inline void set_position(const sf::Vector2f value)
            {
                this->position = value;
            }

            /**
             * @brief Set the position of the pixel on the screen.
             *
             * @param x new x-coordinate
             * @param y new y-coordinate
             */
            inline void set_position(const int x, const int y)
            {
                this->position = sf::Vector2f(x, y);
            }

            /**
             * @brief Get the position of the pixel on the screen.
             *
             * @return Position of the pixel.
             */
            inline sf::Vector2f get_position() const
            {
                return this->position;
            }

        private:
            sf::Vector2f position;
    };
}

#endif