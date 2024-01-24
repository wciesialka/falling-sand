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

            virtual int get_falling_speed() const {
                return 1;
            }

            virtual unsigned int get_falling_dx() const {
                return 3;
            }
            
            virtual bool step() {
                return false;
            }

            virtual bool act_upon(fallingsand::CellState* other) {
                other->do_nothing();
                return false;
            }
        };
    }
}

#endif
