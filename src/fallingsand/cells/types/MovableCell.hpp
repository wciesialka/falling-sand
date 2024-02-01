/**
 * @file MovableCell.hpp
 * @brief Declares a Movable Cell ABC, which can be used for objects that are affected by gravity.
 * 
 * @date 2024-01-24
 * @author Willow Ciesialka
*/

#ifndef FALLINGSAND_CELLS_TYPES_MOVABLECELL_H
#define FALLINGSAND_CELLS_TYPES_MOVABLECELL_H

#include "../CellState.hpp"

namespace fallingsand {
    namespace elements {
        /**
         * @brief ABC for CellTypes affected by gravity.
        */
        class MovableCell : public fallingsand::CellState {
            public:
            
                /**
                 * @brief Abstract constructor. Pass along type and data to base class.
                 * 
                 * @param type Cell type.
                 * @param data Initial cell data.
                */
                MovableCell(const CellType type, const CellData data) : fallingsand::CellState(type, data) {}
                /**
                 * @brief Get the falling speed. A particle will look this far ahead.
                 */
                virtual int get_falling_speed() const = 0;

                /**
                 * @brief Get the falling "x differential." A particle will attempt to move this far ahead for corners.
                 * This can be thought of as viscosity in a way.
                */
                virtual unsigned int get_falling_dx() const = 0;

                bool fall() override;
        };
    }
}

#endif