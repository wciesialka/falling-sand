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
        /**
         * @brief Wall element. Does not interact with other elements.
        */
        class Wall : public fallingsand::elements::ImmovableCell {
            public:
            /**
             * @brief Construct a Wall CellState.
             * 
             * @param data Initial data.
            */
            Wall(const CellData data = CellData()) : fallingsand::elements::ImmovableCell(fallingsand::CellType::WALL, data) {}

            bool step() override {
                return false;
            }

            fallingsand::elements::Wall* clone() const override {
                return new fallingsand::elements::Wall(this->get_data());
            }
        };
    }
}

#endif
