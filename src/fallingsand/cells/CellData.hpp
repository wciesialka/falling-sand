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
        int health;
        unsigned long lifetime;

        CellData() : health(1), lifetime(0) {}
        CellData(int health) : health(health), lifetime(0) {}
    };
}

#endif