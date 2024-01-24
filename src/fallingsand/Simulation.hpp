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

#include <map>
#include <vector>
#include <exception>
#include "cells/Cell.hpp"
#include "cells/CellFactory.hpp"
#include "Chunk.hpp"
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
        Simulation(const unsigned int chunk_count, const unsigned int width, const unsigned int height) : chunk_count(chunk_count)
        {
            this->matrix = new fallingsand::CellularMatrix(width, height);
            this->factory = new fallingsand::CellFactory(this->matrix);
            this->initialize_chunks();
        }
        ~Simulation()
        {
            delete this->factory;
            delete[] this->chunks;
            delete this->matrix;
        }

        virtual void render(sf::RenderWindow &window) const
        {
            this->matrix->render(window);
        }

        int get_width() const {
            return this->matrix->get_width();
        }

        int get_height() const {
            return this->matrix->get_height();
        }

        int get_chunk_count() const {
            return this->chunk_count;
        }

        int get_chunk_width() const {
            return this->get_width() / this->get_chunk_count();
        }

        int get_chunk_height() const {
            return this->get_height() / this->get_chunk_count();
        }

        /**
         * @brief Get the cell at a certain position.
         *
         * @param x x-coordinate.
         * @param y y-coordinate.
         *
         * @return Cell if found, nullptr otherwise.
         */
        fallingsand::Cell *get_cell(const unsigned int x, const unsigned int y) const
        {
            return this->matrix->get(x, y);
        }

        /**
         * @brief Get a factory that generates cells for this simulation.
         *
         * @return Factory for the simulation.
         */
        fallingsand::CellFactory* get_factory() const
        {
            return this->factory;
        }

        /**
         * @brief Preform a chunk update.
         *
         * @param chunk Chunk to update on.
         */
        void update(const fallingsand::Chunk &chunk)
        {
            this->matrix->update(chunk);
        }

        /**
         * @brief Commit changes to the simulation after an update.
         */
        void commit()
        {
            this->matrix->commit();
        }

        /**
         * @brief Update all necessary chunks.
         */
        void update_all()
        {
            for(unsigned int i = 0; i < this->chunk_count; i++){
                fallingsand::Chunk& chunk = this->chunks[i];
                if(chunk.shift_update_state()){
                    this->update(chunk);
                }
                // For now, always update every chunk.
                chunk.queue_update();
            }
            this->commit();
        }

    private:
        unsigned int chunk_count;

        CellularMatrix *matrix;

        /**
         * @brief Initialize chunks.
         */
        void initialize_chunks();

        /**
         * @brief Get the chunk containing an x-y coordinate.
         *
         * @param x x-coordinate.
         * @param y y-coordinate.
         *
         * @return Chunk containing the x-y coordinate.
         */
        fallingsand::Chunk& get_containing_chunk(const unsigned int x, const unsigned int y) const;

        fallingsand::Chunk *chunks;

        fallingsand::CellFactory *factory;
    };
}

#endif