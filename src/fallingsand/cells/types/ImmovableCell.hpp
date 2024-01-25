/**
 * @file ImmovableCell.hpp
 * @brief Declares a Immovable Cell ABC, which can be used for objects that don't move.
 * 
 * @date 2024-01-24
 * @author Willow Ciesialka
*/

#ifndef FALLINGSAND_CELLS_TYPES_IMMOVABLECELL_H
#define FALLINGSAND_CELLS_TYPES_IMMOVABLECELL_H

#include "../CellState.hpp"

namespace fallingsand {
    namespace elements {
        class ImmovableCell : public fallingsand::CellState {
            public:
                virtual bool fall() {
                    return false;
                }
        };
    }
}

#endif