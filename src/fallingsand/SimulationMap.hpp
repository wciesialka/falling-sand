/**
 * @file SimulationMap.hpp
 * @brief Define the Simulation Map, which contains chunks, containing particles.
 * 
 * @date 2024-01-23
 * @author Willow Ciesialka
*/

#ifndef FALLINGSAND_SIMULATIONMAP_H
#define FALLINGSAND_SIMULATIONMAP_H

// TODO: Optimize to using chunks, etc.

#include "cells/Cell.hpp"
#include <vector>

namespace fallingsand {
    typedef std::vector<fallingsand::Cell*> Cells;

    class SimulationMap {
        public:
            SimulationMap(int width, int height) {
                this->cells = new fallingsand::Cells;
            }

            ~SimulationMap() {
                delete this->cells;
            }

            void add_cell(fallingsand::Cell* cell) {
                this->cells->push_back(cell);
            }

            fallingsand::Cell* get(int x, int y){
                for(fallingsand::Cell* cell : *(this->cells)){
                    if(cell->get_x() == x && cell->get_y() == y){
                        return cell;
                    }
                }
                return nullptr;
            }

            void update();
        private:
            fallingsand::Cells* cells;
    };
}

#endif