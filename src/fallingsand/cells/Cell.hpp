/**
 * @file Cell.hpp
 * @brief Basic cell class.
 *
 * @date 2024-01-23
 * @author Willow Ciesialka
 */

#ifndef FALLINGSAND_CELLS_CELL_H
#define FALLINGSAND_CELLS_CELL_H

#include "../../sandrenderer/Renderable.hpp"

namespace fallingsand
{
    class Cell : public sandrenderer::Renderable
    {
    public:
        Cell(sandrenderer::Renderable *renderable) : x(0), y(0), renderable(renderable) {}
        ~Cell() { delete this->renderable; }

        /**
         * @brief Set the x position of the cell.
         *
         * @param x New x coordinate.
         */
        void set_x(const int x)
        {
            this->x = x;
        }

        /**
         * @brief Set the y position of the cell.
         *
         * @param y New y coordinate.
         */
        void set_y(const int y)
        {
            this->y = y;
        }

        /**
         * @brief Set the position of the cell.
         *
         * @param x New x-coordinate.
         * @param y New y-coordinate.
         */
        void set_position(int x, int y)
        {
            this->set_x(x);
            this->set_y(y);
        }

        /**
         * @brief Get the x position of the cell.
         *
         * @returns Cell's x-coordinate.
         */
        int get_x() const
        {
            return this->x;
        }

        /**
         * @brief Get the y position of the cell.
         *
         * @returns Cell's y-coordinate.
         */
        int get_y() const
        {
            return this->y;
        }

        /**
         * @brief Move the cell by a specific amount.
         *
         * @param x Change in x position.
         * @param y Change in y position.
         */
        void move(const int x, const int y)
        {
            this->set_x(this->get_x() + x);
            this->set_y(this->get_y() + y);
        }

        virtual void render(sf::RenderWindow &window) const
        {
            this->renderable->set_render_position(this->get_x(), this->get_y());
            this->renderable->render(window);
        }

    private:
        int x;
        int y;
        sandrenderer::Renderable *renderable;
    };
}

#endif