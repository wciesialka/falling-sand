/**
 * @file Pixel.hpp
 * @brief Contains declerations for the Pixel renderable class.
 *
 * @date 2024-01-17
 * @author Willow Ciesialka
 */

#ifndef SANDRENDERER_PIXEL_H
#define SANDRENDERER_PIXEL_H

#include "Renderable.hpp"
#include <SFML/Graphics/Color.hpp>

namespace sandrenderer
{
    /**
     * @brief A pixel, renderable on the screen,
     */
    class Pixel : public sandrenderer::Renderable
    {
    public:
        static const int ACTUAL_SIZE = 2;
        /**
         * Constructor for the Pixel renderable.
         */
        Pixel(int x, int y, sf::Color color) : sandrenderer::Renderable(x, y), color(color) {};



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

        void render(sf::RenderWindow &window) const override;

    private:
        sf::Color color;
    };
}

#endif