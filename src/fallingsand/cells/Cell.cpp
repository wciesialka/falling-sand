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
    fallingsand::CellState* state;
    switch(type){
        case fallingsand::CellType::WALL:
            state = new fallingsand::elements::Wall();
            break;
        case fallingsand::CellType::SAND:
            state = new fallingsand::elements::Sand();
            break;
        case fallingsand::CellType::WATER:
            state = new fallingsand::elements::Water();
            break;
        default:
            throw std::invalid_argument("Cannot create a Cell of undefined CellType.");
    }

    cell = new fallingsand::Cell(state);
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

void fallingsand::Cell::render(sf::RenderWindow &window) const {
    uint32_t rgba = (uint32_t)(this->get_type());
    char a = (rgba >> 24) & 0xFF;
    char r = (rgba >> 16) & 0xFF;
    char g = (rgba >> 8) & 0xFF;
    char b = (rgba) & 0xFF;
    sf::Color sf_color(r, g, b, a);
    sandrenderer::Pixel pixel(this->get_x(), this->get_y(), sf_color);
    pixel.render(window);
}