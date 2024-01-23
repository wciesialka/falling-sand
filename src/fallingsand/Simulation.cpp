/**
 * @file Simulation.cpp
 * @brief Contains definitions for the Simulation class.
 * 
 * @date 2024-01-23
 * @author Willow Ciesialka
*/

#include "Simulation.hpp"

fallingsand::StorageVector* fallingsand::Simulation::initialize_storage() const {
    fallingsand::StorageVector* storage = new fallingsand::StorageVector;
    
    // Generate chunks
    unsigned int num_iterations = fallingsand::Simulation::CHUNK_COUNT * fallingsand::Simulation::CHUNK_COUNT;
    unsigned int chunk_i, chunk_offset_x, chunk_offset_y, chunk_x, chunk_y;
    for(chunk_i = 0; chunk_i < num_iterations; chunk_i++){
        chunk_offset_x = chunk_i % fallingsand::Simulation::CHUNK_COUNT;
        chunk_offset_y = chunk_i / fallingsand::Simulation::CHUNK_COUNT;
        chunk_x = chunk_offset_x * this->chunk_width;
        chunk_y = chunk_offset_y * this->chunk_height;
        
        fallingsand::ParticleStorage* chunk = new fallingsand::ParticleStorage(this->chunk_width, this->chunk_height, chunk_x, chunk_y);
        storage->push_back(chunk);
    }

    return storage;
};

fallingsand::ParticleStorage* fallingsand::Simulation::get_containing_chunk(const unsigned int x, const unsigned int y) const {
    unsigned int key = (y / this->chunk_height) + (x / this->chunk_width);
    return this->storage->at(key);
}