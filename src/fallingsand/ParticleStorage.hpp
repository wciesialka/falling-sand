/**
 * @file ParticleStorage.hpp
 * @brief Declares the data structure for storing Particles.
 *
 * @date 2024-01-23
 * @author Willow Ciesialka
 */

#ifndef FALLINGSAND_PARTICLESTORAGE_H
#define FALLINGSAND_PARTICLESTORAGE_H

#include <map>
#include <exception>
#include "cells/Particle.hpp"
#include "../sandrenderer/Renderable.hpp"

namespace fallingsand
{
    typedef std::map<unsigned int, fallingsand::Particle *> ParticleMap;

    class ParticleStorage : public sandrenderer::Renderable
    {
    public:
        ParticleStorage(const unsigned int width, const unsigned int height, unsigned int x, unsigned int y) : width(width), height(height), x(x), y(y)
        {
            this->particles = new ParticleMap();
            this->buffer = nullptr;
        };

        ~ParticleStorage()
        {
            delete this->particles;
            if (this->buffer)
            {
                delete this->buffer;
            }
        }

        /**
         * @brief Update the particle list with the buffer.
         */
        void commit_changes()
        {
            delete this->particles;
            this->particles = this->buffer;
            delete this->buffer;
        }

        /**
         * @brief Add a particle to the map.
         *
         * @param particle Particle to add.
         */
        void add_particle(fallingsand::Particle *particle);

        /**
         * @brief Get a particle from a position.
         *
         * @param x x-coordinate of particle.
         * @param y y-coordinate of particle.
         *
         * @return Particle if found, nullptr if nothing found.
         */
        fallingsand::Particle *get_particle(const unsigned int x, const unsigned int y) const;

        virtual void render(sf::RenderWindow &window) const
        {
            for (const auto &kv : *(this->particles))
            {
                fallingsand::Particle *particle = kv.second;
                particle->render(window);
            }
        }

        /**
         * @brief Get the width of the chunk.
         *
         * @return Chunk width.
         */
        unsigned int get_width() const
        {
            return this->width;
        }

        /**
         * @brief Get the height of the chunk.
         *
         * @return Chunk height.
         */
        unsigned int get_height() const
        {
            return this->height;
        }

        /**
         * @brief Get the x-position of the chunk.
         *
         * @return Chunk's x-position.
         */
        unsigned int get_x() const
        {
            return this->x;
        }

        /**
         * @brief Get the y-position of the chunk.
         *
         * @return Chunk's y-position.
         */
        unsigned int get_y() const
        {
            return this->y;
        }

    private:
        unsigned int width;
        unsigned int height;

        unsigned int x;
        unsigned int y;

        fallingsand::ParticleMap *particles;
        fallingsand::ParticleMap *buffer;

        /**
         * @brief Return the key form of the x-y coordinate pair.
         *
         * @param x x-coordinate.
         * @param y y-coordinate.
         * @returns Map key.
         */
        unsigned int form_key(const unsigned int x, const unsigned int y) const
        {
            if (x > this->width || y > this->height)
            {
                throw std::domain_error("Cannot form key for position out of bounds.");
            }
            return (y * width) + x;
        }
    };
}

#endif