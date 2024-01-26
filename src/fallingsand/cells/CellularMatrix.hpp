/**
 * @file CellularMatrix.hpp
 * @brief Contains declerations for the CellularMatrix class.
 *
 * @date 2024-01-24
 * @author Willow Ciesialka
 */

#ifndef FALLINGSAND_CELLS_CELLULARMATRIX_H
#define FALLINGSAND_CELLS_CELLULARMATRIX_H

#include "Cell.hpp"
#include "../Chunk.hpp"
#include <iostream>
#include <mutex>

namespace fallingsand
{

    typedef std::map<unsigned int, fallingsand::Cell *> CellMap;

    class CellularMatrix
    {
    public:
        CellularMatrix(const unsigned int width, const unsigned int height) : width(width), height(height)
        {
            this->current_state = fallingsand::CellMap();
            this->future_state = fallingsand::CellMap();
        }

        ~CellularMatrix()
        {
            this->free_cstate();
            this->free_fstate();
        }

        Cell *get(const unsigned int x, const unsigned int y)
        {
            // Acquire read-lock.
            // std::lock_guard<std::mutex> lock(this->read_lock);
            unsigned int key = this->form_key(x, y);
            try
            {
                return this->future_state.at(key);
            }
            catch (const std::out_of_range &e)
            {
                return nullptr;
            }
        }

        /**
         * @brief Set the specified coordinates to a cell.
         *
         * @param x x-coordinate
         * @param y y-coordinate
         * @param cell Cell
         */
        void set(const unsigned int x, const unsigned int y, fallingsand::Cell *cell)
        {
            // If setting oob, we just return early, killing off the OOB cell.
            unsigned int key;
            try
            {
                key = this->form_key(x, y);
            }
            catch (const std::out_of_range &e)
            {
                return;
            }
            this->future_state[key] = cell;
            cell->set_position(x, y);
        }

        /**
         * @brief Erase the cell at the specified coordinates.
         *
         * @param x x-position of cell.
         * @param y y-position of cell.
         */
        void erase(const unsigned int x, const unsigned int y)
        {
            unsigned int key = this->form_key(x, y);
            delete this->future_state[key];
            this->future_state.erase(key);
        }

        void render(sf::RenderWindow &window)
        {
            // Acquire write-lock
            std::lock_guard<std::mutex> lock(this->write_lock);
            for (auto &kv : (this->current_state))
            {
                kv.second->render(window);
            }
        }

        /**
         * @brief Commit changes to the matrix.
         */
        void commit()
        {
            // Acquire write-lock.
            std::lock_guard<std::mutex> lock(this->write_lock);

            // Copy future state onto current state.
            this->copy_cstate();
        }

        bool update(const fallingsand::Chunk &chunk)
        {
            bool state = false;
            // Update bottom-up
            for (auto kv = this->current_state.rbegin(); kv != this->current_state.rend(); ++kv)
            {
                fallingsand::Cell *cell = kv->second;

                if (chunk.point_within_bounds(cell->get_x(), cell->get_y()))
                {
                    if (cell->update())
                    {
                        state = true;
                    }
                    // Delete empty cells.
                    if (cell->get_state()->is_dead())
                    {
                        this->erase(cell->get_x(), cell->get_y());
                        continue;
                    }
                }
            }
            return state;
        }

        int get_width() const
        {
            return this->width;
        }

        int get_height() const
        {
            return this->height;
        }

    private:
        unsigned int form_key(const unsigned int x, const unsigned int y) const
        {
            if (x >= this->width || y >= this->height)
            {
                throw std::out_of_range("Cannot form key with out-of-bounds coordinates.");
            }
            return (y * this->width) + x;
        }

        /**
         * @brief Free memory occupied by current state.
         */
        void free_cstate()
        {
            for (auto &kv : this->current_state)
            {
                fallingsand::Cell *cell = kv.second;
                if(cell){
                    delete cell;
                }
            }
            this->current_state.clear();
        }

        /**
         * @brief Free memory occupied by future state.
         */
        void free_fstate()
        {
            for (auto &kv : this->future_state)
            {
                fallingsand::Cell *cell = kv.second;
                if(cell){
                    delete cell;
                }
                this->future_state.erase(kv.first);
            }
        }

        /**
         * @brief Copy future state onto current state.
         */
        void copy_cstate()
        {
            this->free_cstate();
            for(auto& kv : this->future_state){
                fallingsand::Cell* clone = kv.second->copy();
                clone->set_parent(this);
                this->current_state.insert({kv.first, clone});
            }
        }

        unsigned int width;
        unsigned int height;
        std::mutex write_lock;
        fallingsand::CellMap current_state;
        fallingsand::CellMap future_state;
    };

}

#endif