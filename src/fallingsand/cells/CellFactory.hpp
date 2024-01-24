/**
 * @file CellFactory.hpp
 * @brief Contains declerations for the Cell Factory
 * 
 * The cell factory is responsible for creating @ref Cell ["Cells"] from @ref CellType ["CellTypes"].
 * 
 * @date 2024-01-23
 * @author Willow Ciesialka
*/

#ifndef FALLINGSAND_CELLS_CELLFACTORY_H
#define FALLINGSAND_CELLS_CELLFACTORY_H

#include "CellType.hpp"
#include "Cell.hpp"
#include "CellularMatrix.hpp"

namespace fallingsand {
    class CellFactory {
        public:
            CellFactory(fallingsand::CellularMatrix* matrix) : matrix(matrix) {};

            /**
             * @brief Create a Cell corresponoding to the correct type and add it to the matrix.
             * 
             * @param type Type of cell.
             * @param x x-position of cell
             * @param y y-position of cell
             * 
             * @return Created cell
            */
            fallingsand::Cell* create(const fallingsand::CellType type, const int x, const int y) const;
            fallingsand::Cell* create(const fallingsand::CellType type) const {
                return this->create(type, 0, 0);
            }

        private:
            fallingsand::CellularMatrix* matrix;
    };
}

#endif