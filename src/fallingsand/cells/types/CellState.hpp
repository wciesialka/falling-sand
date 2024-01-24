/**
 * @file ParticleType.hpp
 * @brief Contains declerations for the ParticleType ABC, which handles simulation details.
 *
 * This is a poorly named state.
 *
 * @date 2024-01-23
 * @author Willow Ciesialka
 */

#ifndef FALLINGSAND_CELLS_TYPES_CELLSTATE_H
#define FALLINGSAND_CELLS_TYPES_CELLSTATE_H

namespace fallingsand
{
    class CellState
    {
    public:
        CellState() : health(1) {}
        CellState(int base_health) : health(base_health) {}

        virtual ~CellState() {};

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
         * 
         * @return True if there was an update this cycle, false otherwise.
         */
        virtual bool update() = 0;

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

        /**
         * @brief Preform freefalling calculations.
         * 
         * @return True if falling, false if now at rest.
        */
        virtual bool fall() = 0;

        /**
         * @brief Set if the particle is in freefall.
         * 
         * @param state State to set.
        */
        void set_is_falling(bool state){
            this->is_falling = state;
        }

        /**
         * @brief Check if the particle is in freefall.
         * 
         * @return True if falling, false if at rest.
        */
        bool get_is_falling() const {
            return this->is_falling;
        }

    private:
        int health;
        int x;
        int y;
        bool is_falling;
    };
}

#endif