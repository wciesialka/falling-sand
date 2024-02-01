/**
 * @file CellData.hpp
 * @brief Contains data for cells.
 * 
 * @date 2024-01-24
 * @author Willow Ciesialka
*/

#ifndef FALLINGSAND_CELLS_TYPES_CELLDATA_H
#define FALLINGSAND_CELLS_TYPES_CELLDATA_H

namespace fallingsand {
    struct CellData {
        int health; // Health of the cell. When a cell's health hits 0, it is removed from the matrix.
        unsigned long lifetime; // How many updates the cell has gone through.

        CellData() : health(1), lifetime(0) {}
        CellData(int health) : health(health), lifetime(0) {}
    };
}

#endif