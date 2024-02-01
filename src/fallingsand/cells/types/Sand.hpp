/**
 * @file Sand.hpp
 * @brief Sand element.
 * 
 * @date 2024-01-24
 * @author Willow Ciesialka
*/

#ifndef FALLINGSAND_CELLS_TYPES_SAND_H
#define FALLINGSAND_CELLS_TYPES_SAND_H

#include "MovableCell.hpp"

namespace fallingsand {
    namespace elements {
        class Sand : public fallingsand::elements::MovableCell {
            public:
            Sand(const CellData data = CellData()) : fallingsand::elements::MovableCell(fallingsand::CellType::SAND, data) {}

            virtual int get_falling_speed() const {
                return 3;
            }

            virtual unsigned int get_falling_dx() const {
                return 1;
            }
            
            virtual bool step() {
                return false;
            }

            virtual fallingsand::elements::Sand* clone() const {
                return new fallingsand::elements::Sand(this->get_data());
            }
        };
    }
}

#endif
