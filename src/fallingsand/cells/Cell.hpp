/**
 * @file Cell.hpp
 * @brief Basic cell class.
 *
 * @date 2024-01-23
 * @author Willow Ciesialka
 */

#ifndef FALLINGSAND_CELLS_CELL_H
#define FALLINGSAND_CELLS_CELL_H

#include <map>
#include <exception>
#include "CellType.hpp"
#include "types/CellState.hpp"
#include "../../sandrenderer/Renderable.hpp"

namespace fallingsand
{

    class CellularMatrix;

    class Cell : public sandrenderer::Renderable
    {
    public:
        Cell(fallingsand::CellType type, fallingsand::CellState *state, sandrenderer::Renderable *renderable) : x(0), y(0), type(type), renderable(renderable)
        {
            this->set_state(state);
        }
        Cell(const fallingsand::Cell &cell) : sandrenderer::Renderable()
        {
            this->set_type(cell.get_type());
            this->set_state(cell.get_state());
            this->set_renderable(cell.get_renderable());
        }
        ~Cell()
        {
            delete this->renderable;
            delete this->state;
        }

        static fallingsand::Cell *create_cell_from_type(const fallingsand::CellType type);

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
         * @brief Get the cell's x-position.
         *
         * @return Cell's x-coordinate.
         */
        int get_x() const
        {
            return this->x;
        }

        /**
         * @brief Get the Cell's y-position.
         *
         * @return Cell's y-coordinate.
         */
        int get_y() const
        {
            return this->y;
        }

        /**
         * @brief Set the Cell's x-position.
         *
         * @param x New x-position.
         */
        void set_x(const int x)
        {
            this->x = x;
        }

        /**
         * @brief Set the Cell's y-position.
         *
         * @param y New y-position.
         */
        void set_y(const int y)
        {
            this->y = y;
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

        /**
         * @brief Set the parent matrix.
         *
         * @param parent New parent matrix.
         */
        void set_parent(fallingsand::CellularMatrix *parent)
        {
            this->parent = parent;
        }

        /**
         * @brief Get the parent matrix.
         *
         * @return Parent matrix.
         */
        fallingsand::CellularMatrix *get_parent() const
        {
            return this->parent;
        }

        /**
         * @brief Get the type of this cell.
         *
         * @return Cell type.
         */
        fallingsand::CellType get_type() const
        {
            return this->type;
        }

        /**
         * @brief Do an update step.
         */
        void update()
        {
            this->get_state()->update();
        }

        /**
         * @brief Get the state of a neighboring cell.
         *
         * @param dx Difference in x-position.
         * @param dy Difference in y-position.
         *
         * @return Cell's state if found, nullptr otherwise.
         */
        fallingsand::CellState *get_neighbor(const int dx, const int dy) const;

        /**
         * @brief Get the state of a neighboring cell.
         *
         * @param dx Difference in x-position.
         * @param dy Difference in y-position.
         * @param cell Cell to set.
         */
        void set_neighbor(const int dx, const int dy, fallingsand::Cell *cell) const;
        void set_neighbor(const int dx, const int dy, fallingsand::CellState *state) const
        {
            this->set_neighbor(dx, dy, state->get_parent());
        };
        void set_neighbor(const int dx, const int dy, fallingsand::CellType type) const
        {
            fallingsand::Cell *new_cell = fallingsand::Cell::create_cell_from_type(type);
            this->set_neighbor(dx, dy, new_cell);
        };

        /**
         * @brief Get the state of the cell.
         *
         * @return Cell's state.
         */
        fallingsand::CellState *get_state() const
        {
            return this->state;
        }

        /**
         * @brief Get the renderable of the cell.
         *
         * @return Cell's renderable.
         */
        sandrenderer::Renderable *get_renderable() const
        {
            return this->renderable;
        }

    private:
        /**
         * @brief Set the state of the cell.
         *
         * @param state New cell state.
         */
        void set_state(fallingsand::CellState *state)
        {
            this->state = state;
            state->set_parent(this);
        }

        /**
         * @brief Set the type of this cell.
         *
         * @param type New cell type.
         */
        void set_type(const fallingsand::CellType type)
        {
            this->type = type;
        }

        /**
         * @brief Set the cell's renderable.
         *
         * @param renderable New renderable.
         */
        void set_renderable(sandrenderer::Renderable *renderable)
        {
            this->renderable = renderable;
        }

        int x;
        int y;
        fallingsand::CellType type;
        fallingsand::CellState *state;
        sandrenderer::Renderable *renderable;

        fallingsand::CellularMatrix *parent;
    };
}

#endif