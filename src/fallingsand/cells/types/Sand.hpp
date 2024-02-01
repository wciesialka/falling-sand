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

        /**
         * @brief Sand element. Falls and does not interact with other elements.
        */
        class Sand : public fallingsand::elements::MovableCell {
            public:
            /**
             * @brief Construct a Sand type Cell State.
             * 
             * @param data Initial data.
            */
            Sand(const CellData data = CellData()) : fallingsand::elements::MovableCell(fallingsand::CellType::SAND, data) {}

            int get_falling_speed() const override {
                return 3;
            }

            unsigned int get_falling_dx() const override {
                return 1;
            }
            
            bool step() override {
                return false;
            }

            fallingsand::elements::Sand* clone() const override {
                return new fallingsand::elements::Sand(this->get_data());
            }
        };
    }
}

#endif
