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
        /**
         * @brief Water element. Basic fluid, flows but does not interact with other elements.
        */
        class Water : public fallingsand::elements::MovableCell {
            public:
            /**
             * @brief Construct a water type cell state.
             * 
             * @param data Initial data.
            */
            Water(const CellData data = CellData()) : fallingsand::elements::MovableCell(fallingsand::CellType::WATER, data) {}

            int get_falling_speed() const override {
                return 10;
            }

            unsigned int get_falling_dx() const override {
                return 5;
            }
            
            bool step() override {
                return false;
            }

            fallingsand::elements::Water* clone() const override {
                return new fallingsand::elements::Water(this->get_data());
            }

        };
    }
}

#endif