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
#include "../sandrenderer/Renderable.hpp"

namespace fallingsand
{
    class Simulation : public sandrenderer::Renderable
    {
    public:
        /**
         * @brief Construct a Simulation.
         * 
         * @param chunk_count log2 number of chunks (1 = 1, 2 = 4, 3 = 9, etc.),
         * @param width Width of simulation.
         * @param height Height of simulation. 
        */
        Simulation(const unsigned int chunk_count, const unsigned int width, const unsigned int height) : chunk_count(chunk_count), width(width), height(height)
        {
            this->chunk_width = this->width / this->chunk_count;
            this->chunk_height = this->height / this->chunk_count;
            this->initialize_storage();
        }
        ~Simulation()
        {
            delete this->storage;
        }

        virtual void render(sf::RenderWindow &window) const
        {
            for (unsigned int i = 0; i < this->chunk_count; i++)
            {
                this->storage[i]->render(window);
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
        void add_particle(fallingsand::Particle *particle);

    private:
        unsigned int chunk_count;
        unsigned int width;
        unsigned int height;
        unsigned int chunk_width;
        unsigned int chunk_height;

        /**
         * @brief Initialize storage buffer.
         */
        void initialize_storage();

        /**
         * @brief Get the chunk containing an x-y coordinate.
         *
         * @param x x-coordinate.
         * @param y y-coordinate.
         *
         * @return Chunk containing the x-y coordinate.
         */
        fallingsand::ParticleStorage *get_containing_chunk(const unsigned int x, const unsigned int y) const;

        fallingsand::ParticleStorage **storage;
    };
}

#endif