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
        int health = 1;
        unsigned long lifetime = 0;
    };
}

#endif