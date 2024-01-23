/**
 * @file ParticleStorage.cpp
 * @brief Contain definitions for the Particle Storage class.
 * 
 * @date 2024-01-23
 * @author Willow Ciesialka
*/

#include "ParticleStorage.hpp"

void fallingsand::ParticleStorage::add_particle(fallingsand::Particle* particle) {
    unsigned int x_in_chunk = particle->get_x() % this->get_x();
    unsigned int y_in_chunk = particle->get_y() % this->get_y();

    unsigned int key = this->form_key(x_in_chunk, y_in_chunk);
    this->particles->insert({key, particle});
}

fallingsand::Particle* fallingsand::ParticleStorage::get_particle(const unsigned int x, const unsigned int y) const {
    unsigned int x_in_chunk = x % this->get_x();
    unsigned int y_in_chunk = y % this->get_y();

    unsigned int key = this->form_key(x_in_chunk, y_in_chunk);
    fallingsand::Particle* particle;
    try {
        particle = this->particles->at(key);
    } catch( const std::out_of_range& e ){
        // Particle was not found.
        particle = nullptr;
    }
    return particle;
}