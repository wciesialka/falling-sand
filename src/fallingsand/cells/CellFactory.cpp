/**
 * @file CellFactory.cpp
 * @brief Definitions for CellFactory class.
 * 
 * @date 2024-01-23
 * @author Willow Ciesialka
*/

#include "CellFactory.hpp"
#include "../../sandrenderer/Pixel.hpp"
#include "types/Wall.hpp"
#include <iostream>

fallingsand::Cell* fallingsand::CellFactory::create(const fallingsand::CellType type, const int x, const int y) const {
    fallingsand::Cell* cell = fallingsand::Cell::create_cell_from_type(type);
    this->matrix.set(x, y, cell);
    return cell;
}