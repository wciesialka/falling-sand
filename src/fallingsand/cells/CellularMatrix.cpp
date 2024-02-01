/**
 * @file CellularMatrix.cpp
 * @brief Contains definitions for the \ref fallingsand::CellularMatrix class.
 * 
 * @date 2024-01-31
 * @author Willow Ciesialka
*/

#include "CellularMatrix.hpp"

bool fallingsand::CellularMatrix::update(const fallingsand::Chunk chunk){
    bool state = false;
    // Update bottom-up
    for (auto kv = this->current_state.rbegin(); kv != this->current_state.rend(); ++kv)
    {
        fallingsand::Cell *cell = kv->second;

        if (chunk.point_within_bounds(cell->get_x(), cell->get_y()))
        {
            if (cell->update())
            {
                state = true;
            }
            // Delete empty cells.
            if (cell->get_state()->is_dead())
            {
                this->erase(cell->get_x(), cell->get_y());
                continue;
            }
        }
    }
    return state;
}