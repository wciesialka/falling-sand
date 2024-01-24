/**
 * @file MovableCell.cpp
 * @brief Contains definitions for the MovableCell class.
 * 
 * @date 2024-01-24
 * @author Willow Ciesialka
*/

#include "MovableCell.hpp"

bool fallingsand::elements::MovableCell::fall() {
    bool in_freefall = false;
    // First, look straight down.
    int dy = this->get_falling_speed();
    int i = dy;
    // di is zero if i==0, -1 if i > 0, 1 if i < 0.
    // Basically: iterate through all the cells in front of us,
    // and get close to it.
    int di = (i > 0) ? ((i == 0) ? 0 : 1) : -1;
    for(int i = dy; i != 0; i += di){
        // Check if cell is filled. If it is,
        // then we need to set our dy to the cell before it.
        if(this->get_neighbor(0, i)){
            dy = i + di;
            in_freefall = true;
        }
    }

    // Falling straight down
    if(in_freefall){
        this->set_neighbor(0, dy, this);
        this->kill();
        return true;
    }
    // Falling off corners
    for(int i = 0; i < this->get_falling_dx(); i++){
        if(this->get_neighbor(i, di)){
            if(this->get_neighbor(-i, di)){
                continue;
            }
            // Left side neighbor
            this->set_neighbor(-i, di, this);
            this->kill();
            return true;
        }
        // Right side neighbor
        this->set_neighbor(i, di, this);
        this->kill();
        return true;
    }
    return false;
}