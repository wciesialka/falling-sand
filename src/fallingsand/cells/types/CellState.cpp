/**
 * @file CellState.cpp
 * @brief Definitions for the Cell State class.
 * 
 * @date 2024-01-24
 * @author Willow Ciesialka
*/

#include "CellState.hpp"
#include "../Cell.hpp"

fallingsand::CellType fallingsand::CellState::get_type() const {
    return this->get_parent()->get_type();
}

fallingsand::CellState* fallingsand::CellState::get_neighbor(const int dx, const int dy) const {
    return this->get_parent()->get_neighbor(dx, dy);
}

void fallingsand::CellState::set_neighbor(const int dx, const int dy, const fallingsand::CellType type) const{
    this->get_parent()->set_neighbor(dx, dy, type);
}

void fallingsand::CellState::set_neighbor(const int dx, const int dy, fallingsand::CellState* state) const {
    this->get_parent()->set_neighbor(dx, dy, state);
}