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
#include <iostream>

namespace fallingsand {

    typedef std::map<unsigned int, fallingsand::Cell*> CellMap;

    class CellularMatrix : public sandrenderer::Renderable {
        public:
            CellularMatrix(const unsigned int width, const unsigned int height) : width(width), height(height)
            {
                this->current_state = new fallingsand::CellMap;
                this->future_state = new fallingsand::CellMap;
            } 

            ~CellularMatrix() {
                delete this->current_state;
                delete this->future_state;
            }

            Cell* get(const unsigned int x, const unsigned int y) const {
                unsigned int key = this->form_key(x, y);
                try {
                    return this->future_state->at(key);
                } catch (const std::out_of_range &e){
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
            void set(const unsigned int x, const unsigned int y, Cell* cell) {
                unsigned int key = this->form_key(x, y);
                (*(this->future_state))[key] = cell;
                cell->set_parent(this);
            }

            virtual void render(sf::RenderWindow &window) const
            {
                for(auto &kv : *(this->current_state)){
                    kv.second->render(window);
                }
            }

            /**
             * @brief Commit changes to the matrix.
            */
            void commit() {
                *(this->current_state) = *(this->future_state);
                delete this->future_state;
                this->future_state = new CellMap;
                *(this->future_state) = *(this->current_state);
            }

        private:
            unsigned int form_key(const unsigned int x, const unsigned int y) const{
                if(x >= this->width || y >= this->height){
                    throw std::out_of_range("Cannot form key with out-of-bounds coordinates.");
                }
                return (y * this->width) + x;
            }

            unsigned int width;
            unsigned int height;
            fallingsand::CellMap* current_state;
            fallingsand::CellMap* future_state;
    };

}

#endif