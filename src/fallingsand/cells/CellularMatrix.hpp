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

    /**
     * @brief Class responsible for holding the current and future state
     * of the cellular matrix.
     * 
     * Internally, it actually uses a sparse map for both to conserve memory.
    */
    class CellularMatrix
    {
    public:
        /**
         * @brief Construct a CellularMatrix
         * 
         * @param width Width of matrix.
         * @param height Height of matrix.
        */
        CellularMatrix(const unsigned int width, const unsigned int height) : width(width), height(height)
        {
            this->current_state = fallingsand::CellMap();
            this->future_state = fallingsand::CellMap();
        }

        /**
         * @brief Destruct the matrix.
        */
        ~CellularMatrix()
        {
            this->free_cstate();
            this->free_fstate();
        }

        /**
         * @brief Get the cell at the specific location in the current state.
         * 
         * @param x Cell x-coordinate.
         * @param y Cell y-coordinate.
         * 
         * @return Cell at location.
        */
        Cell *get(const unsigned int x, const unsigned int y) const
        {
            unsigned int key = this->form_key(x, y);
            try
            {
                return this->current_state.at(key);
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
            cell->set_position(x, y);
            unsigned int key = this->form_key(x, y);
            this->future_state[key] = cell;
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

        /**
         * @brief Render the current state onto a window.
         * 
         * @param window SFML RenderWindow to render onto.
        */
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
            this->free_cstate();
            this->copy_cstate();
        }

        bool update(const fallingsand::Chunk chunk);

        /**
         * @brief Get the width of the matrix.
         * 
         * @return Matrix's width.
        */
        int get_width() const
        {
            return this->width;
        }

        /**
         * @brief Get the height of the matrix.
         * 
         * @return Matrix's height.
        */
        int get_height() const
        {
            return this->height;
        }

    private:

        /**
         * @brief Form the key (index) for a cell given coordinates.
         * 
         * @param x Cell x-coordinate
         * @param y Cell y-coordinate
         * 
         * @return Index key
        */
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
            }
            this->future_state.clear();
        }

        /**
         * @brief Copy future state onto current state.
         */
        void copy_cstate()
        {
            for(auto& kv : this->future_state){
                fallingsand::Cell* original = kv.second;
                fallingsand::Cell* clone = original->copy();
                clone->set_position(original->get_x(), original->get_y());
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