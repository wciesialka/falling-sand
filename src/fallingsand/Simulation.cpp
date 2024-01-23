/**
 * @file Simulation.cpp
 * @brief Contains definitions for the Simulation class.
 * 
 * @date 2024-01-23
 * @author Willow Ciesialka
*/

#include "Simulation.hpp"

#include <iostream>

void fallingsand::Simulation::initialize_storage() {
    this->storage = new fallingsand::ParticleStorage*[this->chunk_count];
    
    // Generate chunks
    unsigned int num_iterations = this->chunk_count * this->chunk_count;
    unsigned int chunk_i, chunk_offset_x, chunk_offset_y, chunk_x, chunk_y;
    for(chunk_i = 0; chunk_i < num_iterations; chunk_i++){
        chunk_offset_x = chunk_i % this->chunk_count;
        chunk_offset_y = chunk_i / this->chunk_count;
        chunk_x = chunk_offset_x * this->chunk_width;
        chunk_y = chunk_offset_y * this->chunk_height;
        
        fallingsand::ParticleStorage* chunk = new fallingsand::ParticleStorage(this->chunk_width, this->chunk_height, chunk_x, chunk_y);
        storage[chunk_i] = chunk;
    }
};

fallingsand::ParticleStorage* fallingsand::Simulation::get_containing_chunk(const unsigned int x, const unsigned int y) const {
    unsigned int key = (y / this->chunk_height) + (x / this->chunk_width);
    std::cout << x << "," << y << ":\t" << "Chunk #" << key << std::endl;
    return this->storage[key];
}

void fallingsand::Simulation::add_particle(fallingsand::Particle* particle) {
    fallingsand::ParticleStorage *chunk = this->get_containing_chunk(particle->get_x(), particle->get_y());
    chunk->add_particle(particle);
}