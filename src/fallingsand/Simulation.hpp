/**
 * @file SimulationMap.hpp
 * @brief Declares the Simulation, which contains chunks, containing particles, which it does updates on.
 *
 * @date 2024-01-23
 * @author Willow Ciesialka
 */

#ifndef FALLINGSAND_SIMULATION_H
#define FALLINGSAND_SIMULATION_H

// TODO: Optimize to using chunks, etc.

#include <vector>
#include "cells/Particle.hpp"
#include "ParticleStorage.hpp"

namespace fallingsand
{
    typedef std::vector<fallingsand::ParticleStorage *> StorageVector;

    class Simulation
    {
    public:
        // This is exponential. ie 1 = 1, 2 = 4, 3 = 9
        const unsigned int CHUNK_COUNT = 1;

        Simulation(const unsigned int width, const unsigned int height) : width(width), height(height)
        {
            this->chunk_width = this->width / fallingsand::Simulation::CHUNK_COUNT;
            this->chunk_height = this->height / fallingsand::Simulation::CHUNK_COUNT;
            this->storage = this->initialize_storage();
        }
        ~Simulation()
        {
            delete this->storage;
        }

        void render(sf::RenderWindow &window) const
        {
            for (fallingsand::ParticleStorage *storage : *(this->storage))
            {
                storage->render(window);
            }
        }

        /**
         * @brief Get the particle at a certain position.
         *
         * @param x x-coordinate.
         * @param y y-coordinate.
         *
         * @return Particle if found, nullptr otherwise.
         */
        fallingsand::Particle *get_particle(const unsigned int x, const unsigned int y)
        {
            fallingsand::ParticleStorage *chunk = this->get_containing_chunk(x, y);
            return chunk->get_particle(x, y);
        }

        /**
         * @brief Add a particle to the simulation.
         * 
         * @param particle Particle to add.
         */
        void add_particle(fallingsand::Particle *particle)
        {
            fallingsand::ParticleStorage *chunk = this->get_containing_chunk(particle->get_x(), particle->get_y());
            chunk->add_particle(particle);
        }

    private:
        unsigned int width;
        unsigned int height;
        unsigned int chunk_width;
        unsigned int chunk_height;

        /**
         * @brief Initialize a storage vector.
         *
         * @param width Width of the simulation.
         * @param height Height of the simulation.
         *
         * @return Vector containing all the initialized chunks.
         */
        fallingsand::StorageVector *initialize_storage() const;

        /**
         * @brief Get the chunk containing an x-y coordinate.
         *
         * @param x x-coordinate.
         * @param y y-coordinate.
         *
         * @return Chunk containing the x-y coordinate.
         */
        fallingsand::ParticleStorage *get_containing_chunk(const unsigned int x, const unsigned int y) const;

        fallingsand::StorageVector *storage;
    };
}

#endif