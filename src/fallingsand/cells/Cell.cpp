/**
 * @file Cell.cpp
 * @brief Contains definitions for the Cell class.
 * 
 * @date 2024-01-24
 * @author Willow Ciesialka
*/

#include <exception>
#include <iostream>
#include "Cell.hpp"
#include "CellularMatrix.hpp"
#include "../../sandrenderer/Pixel.hpp"

#include "types/AllTypes.hpp"

fallingsand::Cell* fallingsand::Cell::create_cell_from_type(const fallingsand::CellType type) {
    fallingsand::Cell* cell;
    sandrenderer::Pixel* pixel;
    fallingsand::CellState* state;
    switch(type){
        case fallingsand::CellType::WALL:
            pixel = new sandrenderer::Pixel(169, 169, 169);
            state = new fallingsand::elements::Wall();
            break;
        case fallingsand::CellType::SAND:
            pixel = new sandrenderer::Pixel(194, 178, 128);
            state = new fallingsand::elements::Sand();
            break;
        case fallingsand::CellType::WATER:
            pixel = new sandrenderer::Pixel(49, 140, 231);
            state = new fallingsand::elements::Water();
            break;
        default:
            throw std::invalid_argument("Cannot create a Cell of undefined CellType.");
    }

    cell = new fallingsand::Cell(state, pixel);
    return cell;
}

fallingsand::CellState* fallingsand::Cell::get_neighbor(const int dx, const int dy) const 
{
    fallingsand::Cell* neighbor_cell;
    try {
        unsigned int x = this->get_x() + dx;
        unsigned int y = this->get_y() + dy;
        neighbor_cell = this->get_parent()->get(x, y);
    } catch(std::out_of_range& e) {
        return nullptr;
    }
    if(neighbor_cell){
        return neighbor_cell->get_state();
    }
    return nullptr;
} 

void fallingsand::Cell::set_neighbor(const int dx, const int dy, fallingsand::Cell* cell) const {
    try {
        unsigned int x = this->get_x() + dx;
        unsigned int y = this->get_y() + dy;
        this->get_parent()->set(x, y, cell);
    } catch(std::out_of_range& e) {
        return;
    }
}