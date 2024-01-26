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
            public:
            Wall(const CellData data = CellData()) : fallingsand::elements::ImmovableCell(data) {}

            virtual bool step() {
                return false;
            }

            virtual fallingsand::elements::Wall* clone() const {
                return new fallingsand::elements::Wall(this->get_data());
            }
        };
    }
}

#endif
