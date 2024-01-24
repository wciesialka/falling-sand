/**
 * @file MovableCell.hpp
 * @brief Declares a Movable Cell BC, which can be used for objects that move.
 * 
 * @date 2024-01-24
 * @author Willow Ciesialka
*/

#ifndef FALLINGSAND_CELLS_TYPES_MOVABLECELL_H
#define FALLINGSAND_CELLS_TYPES_MOVABLECELL_H

#include "CellState.hpp"

namespace fallingsand {
    namespace elements {
        class ImmovableCell : public fallingsand::CellState {
            public:
                /**
                 * @brief Get the falling speed. A particle will look this far ahead.
                 */
                virtual int get_falling_speed() const {
                    return 0;
                };

                virtual bool fall() {
                    return false;
                }
        };
    }
}

#endif