/**
 * @file Wall.hpp
 * @brief Wall element.
 * 
 * @date 2024-01-24
 * @author Willow Ciesialka
*/

#ifndef FALLINGSAND_CELLS_TYPES_WALL_H
#define FALLINGSAND_CELLS_TYPES_WALL_H

#include "ImmovableCell.hpp"

namespace fallingsand {
    namespace elements {
        class Wall : public fallingsand::elements::ImmovableCell {
            virtual bool update() {
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
