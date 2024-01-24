/**
 * @file Cell.cpp
 * @brief Contains definitions for the Cell class.
 * 
 * @date 2024-01-24
 * @author Willow Ciesialka
*/

#include <exception>
#include "Cell.hpp"
#include "../../sandrenderer/Pixel.hpp"

#include "types/Wall.hpp"

fallingsand::Cell* fallingsand::Cell::create_cell_from_type(const fallingsand::CellType type) {
    fallingsand::Cell* cell;
    sandrenderer::Pixel* pixel;
    fallingsand::CellState* state;
    switch(type){
        case fallingsand::CellType::WALL:
            pixel = new sandrenderer::Pixel(169, 169, 169);
            state = new fallingsand::elements::Wall();
            break;
        default:
            throw std::invalid_argument("Cannot create a Cell of undefined CellType.");
    }

    cell = new fallingsand::Cell(type, state, pixel);
    return cell;
}