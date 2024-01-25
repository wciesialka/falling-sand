/**
 * @file MovableCell.cpp
 * @brief Contains definitions for the MovableCell class.
 * 
 * @date 2024-01-24
 * @author Willow Ciesialka
*/

#include "MovableCell.hpp"
#include <iostream>
 
bool fallingsand::elements::MovableCell::fall() {
    bool stopped = false;
    // First, look straight down.
    int fall_speed = this->get_falling_speed();
    int dy = 0;
    // di is zero if i==0, -1 if i > 0, 1 if i < 0.
    // Basically: iterate through all the cells in front of us,
    // and get close to it.
    int di = (fall_speed > 0) ? 1 : ((fall_speed == 0) ? 0 : -1);
    for(int i = 1; i <= fall_speed; i++){
        // Check if cell is filled. If it is,
        // then we need to set our dy to the cell before it.
        if(this->get_neighbor(0, i*di)){
            dy = (i-1)*di;
            stopped = true;
            break;
        }
    }

    if(!stopped){
        dy = fall_speed;
    }

    // Freefalling
    if(dy != 0){
        this->move(0, dy);
        return true;
    }
    // Falling off corners
    for(unsigned int i = 1; i <= this->get_falling_dx(); i++){
        if(this->get_neighbor(i, di)){
            if(this->get_neighbor(-i, di)){
                continue;
            }
            // Left side neighbor
            this->move(-i, di);
            return true;
        }
        // Right side neighbor
        this->move(i, di);
        return true;
    }
    return false;
}