/**
 * @file Simulation.cpp
 * @brief Contains definitions for the Simulation class.
 * 
 * @date 2024-01-23
 * @author Willow Ciesialka
*/

#include "Simulation.hpp"

#include <iostream>

void fallingsand::Simulation::initialize_chunks() {
    this->chunks = new fallingsand::Chunk[this->chunk_count];
    
    int chunk_count = this->get_chunk_count();
    int chunk_width = this->get_chunk_width();
    int chunk_height = this->get_chunk_height();

    // Generate chunks
    unsigned int num_iterations = chunk_count * chunk_count;
    unsigned int chunk_i, chunk_offset_x, chunk_offset_y, chunk_x, chunk_y;
    for(chunk_i = 0; chunk_i < num_iterations; chunk_i++){
        chunk_offset_x = chunk_i % chunk_count;
        chunk_offset_y = chunk_i / chunk_count;
        chunk_x = chunk_offset_x * chunk_width;
        chunk_y = chunk_offset_y * chunk_height;
        
        fallingsand::Chunk chunk(chunk_width, chunk_height, chunk_x, chunk_y);
        this->chunks[chunk_i] = chunk;
    }
};

fallingsand::Chunk& fallingsand::Simulation::get_containing_chunk(const unsigned int x, const unsigned int y) const {
    unsigned int key = (y / this->get_chunk_height()) + x;
    return this->chunks[key];
}