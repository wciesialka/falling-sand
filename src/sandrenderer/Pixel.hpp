/**
 * @file Pixel.hpp
 * @brief Contains declerations for the Pixel renderable class.
 *
 * @date 2024-01-17
 * @author Willow Ciesialka
 */

#ifndef SANDRENDERER_PIXEL_H
#define SANDRENDERER_PIXEL_H

#include "sandrenderer/Renderable.hpp"
#include <SFML/Graphics/Color.hpp>

namespace sandrenderer
{
    /**
     * @brief A pixel, renderable on the screen,
     */
    class Pixel : public sandrenderer::Renderable
    {
    public:
        /**
         * Constructor for the Pixel renderable.
         */
        Pixel() : position(sf::Vector2f(0, 0)), color(sf::Color::Black){};
        Pixel(sf::Vector2f position, sf::Color color) : position(position), color(color){};
        Pixel(sf::Vector2f position, int r, int g, int b) : position(position), color(sf::Color(r, g, b)){};
        Pixel(int x, int y, sf::Color color) : position(sf::Vector2f(x, y)), color(color){};
        Pixel(int x, int y, int r, int g, int b) : position(sf::Vector2f(x, y)), color(sf::Color(r, g, b)){};

        /**
         * @brief Set the position of the pixel on the screen.
         *
         * @param value New position.
         */
        inline void set_position(sf::Vector2f value)
        {
            this->position = value;
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

        /**
         * @brief Set the color of the pixel on the screen.
         *
         * @param value New color.
         */
        inline void set_color(sf::Color value)
        {
            this->color = value;
        }

        /**
         * @brief Get the color of the pixel on the screen.
         *
         * @return The color of the pixel on the screen.
         */
        inline sf::Color get_color() const
        {
            return this->color;
        }

        virtual void render(sf::RenderWindow &window) const;

    private:
        sf::Vector2f position;
        sf::Color color;
    };
}

#endif