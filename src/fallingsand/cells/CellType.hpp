/**
 * @file CellType.hpp
 * @brief Contains CellType enum.
 * 
 * @date 2024-01-23
 * @author Willow Ciesialka
*/

#ifndef FALLINGSAND_CELLS_CELLTYPE_H
#define FALLINGSAND_CELLS_CELLTYPE_H

namespace fallingsand {
    /**
     * @brief CellType enum. Each value is the type's color. 
    */
    enum CellType {
        EMPTY = 0,
        SAND = 0xFFC2B280,
        WALL = 0xFFA9A9A9,
        WATER = 0xFF318CE7
    };
}

#endif