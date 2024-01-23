/**
 * @file Particle.hpp
 * @brief Declares a particle, which is a type of cell.
 *
 * Basically, just a cell with a color and simulations!
 *
 * @date 2024-01-23
 * @author Willow Ciesialka
 */

#ifndef FALLINGSAND_CELLS_PARTICLE_H
#define FALLINGSAND_CELLS_PARTICLE_H

#include "Cell.hpp"
#include "types/ParticleState.hpp"
#include "../../sandrenderer/Pixel.hpp"

namespace fallingsand
{
    class Particle : public Cell
    {
    public:
        Particle(const int r, const int g, const int b, fallingsand::ParticleState *type, fallingsand::ParticleState *next_state) : Cell(new sandrenderer::Pixel(r, g, b)), state(type), new_state(next_state)
        {
            this->begin_new_state();
        };

        ~Particle()
        {
            delete this->state;
            delete this->new_state;
        }

        /**
         * @brief Get the particle's state.
         *
         * @return Particle's state.
         */
        fallingsand::ParticleState *get_state() const
        {
            return this->state;
        }

        /**
         * @brief Get the proposed state to do operations on.
         *
         * @return Particle's new state.
         */
        fallingsand::ParticleState *get_proposed_state() const
        {
            return this->new_state;
        }

        /**
         * @brief Handle collision details.
         *
         * @param other Particle collided with.
         */
        void on_collide(fallingsand::Particle *other)
        {
            this->get_state()->on_collision(other->get_state(), this->get_proposed_state(), other->get_proposed_state());
        }

        /**
         * @brief Commit changes to the state.
         */
        void commit()
        {
            *(this->state) = *(this->new_state);
            this->begin_new_state();
        }

        /**
         * @brief Set the position of the cell.
         *
         * @param x New x-coordinate.
         * @param y New y-coordinate.
         */
        void set_position(int x, int y)
        {
            this->set_x(x);
            this->set_y(y);
        }

        virtual int get_x() const {
            return this->get_state()->get_x();
        }
        virtual int get_y() const {
            return this->get_state()->get_y();
        }
        virtual void set_x(const int x) {
            this->get_proposed_state()->set_x(x);
        }
        virtual void set_y(const int y) {
            this->get_proposed_state()->set_y(y);
        }

    private:
        /**
         * @brief Set the new state to a copy of the current state.
         */
        void begin_new_state()
        {
            *(this->new_state) = *(this->get_state());
        }

        fallingsand::ParticleState *state;
        fallingsand::ParticleState *new_state;
    };
}

#endif