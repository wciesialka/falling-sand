/**
 * @file ParticleType.hpp
 * @brief Contains declerations for the ParticleType ABC, which handles simulation details.
 *
 * This is a poorly named state.
 *
 * @date 2024-01-23
 * @author Willow Ciesialka
 */

#ifndef FALLINGSAND_CELLS_TYPES_PARTICLESTATE_H
#define FALLINGSAND_CELLS_TYPES_PARTICLESTATE_H

namespace fallingsand
{
    class ParticleState
    {
    public:
        ParticleState() : health(1) {}
        ParticleState(int base_health) : health(base_health) {}

        virtual ~ParticleState() {};

        /**
         * @brief Set the health of the particle.
         *
         * @param health New health.
         */
        void set_health(int health)
        {
            this->health = health;
        }

        /**
         * @brief Get the health of the particle.
         *
         * @return Particle's health.
         */
        int get_health() const
        {
            return this->health;
        }

        /**
         * @brief Kill the particle.
         */
        void kill()
        {
            this->set_health(0);
        }

        /**
         * @brief Check if the particle is dead.
         *
         * @return True if particle is dead, false otherwise.
         */
        bool is_dead()
        {
            return this->get_health() <= 0;
        }

        /**
         * @brief Idle update. This should only change the state of THIS PARTICLE!
         */
        virtual void update(){};

        /**
         * @brief Do collision checking on the particle type.
         *
         * @param[in] other The other state.
         * @param[out] my_new_state My new state, that I do operations on!
         * @param[out] their_new_state Their new state, that I do operations on!
         */
        virtual void on_collision(const ParticleState *other, ParticleState *my_new_state, ParticleState *their_new_state) const = 0;

        /**
         * PROPERTIES
         */

        /**
         * @brief Get the state's x-position.
         *
         * @return State's x-coordinate.
         */
        int get_x() const
        {
            return this->x;
        }

        /**
         * @brief Get the state's y-position.
         *
         * @return State's y-coordinate.
         */
        int get_y() const
        {
            return this->y;
        }

        /**
         * @brief Set the state's x-position.
         *
         * @param x New x-position.
         */
        void set_x(const int x)
        {
            this->x = x;
        }

        /**
         * @brief Set the state's y-position.
         *
         * @param y New y-position.
         */
        void set_y(const int y)
        {
            this->y = y;
        }

        /**
         * @brief Get the falling speed. A particle will look this far ahead.
         */
        virtual int get_falling_speed() const = 0;

    private:
        int health;
        int x;
        int y;
    };
}

#endif