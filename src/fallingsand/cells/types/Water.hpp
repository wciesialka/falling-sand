/**
 * @file Water.hpp
 * @brief Water Element
 * 
 * @date 2024-01-25
 * @author Willow Ciesialka
*/

#ifndef FALLINGSAND_CELLS_TYPES_WATER_H
#define FALLINGSAND_CELLS_TYPES_WATER_H

#include "MovableCell.hpp"

namespace fallingsand {
    namespace elements {
        class Water : public fallingsand::elements::MovableCell {
            public:
            Water(const CellData data = CellData()) : fallingsand::elements::MovableCell(data) {}

            virtual int get_falling_speed() const {
                return 10;
            }

            virtual unsigned int get_falling_dx() const {
                return 5;
            }
            
            virtual bool step() {
                return false;
            }

            virtual fallingsand::elements::Water* clone() const {
                return new fallingsand::elements::Water(this->get_data());
            }

        };
    }
}

#endif