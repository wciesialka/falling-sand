/**
 * @file CellState.hpp
 * @brief Contains declerations for the CellState ABC, which handles simulation details.
 *
 * This is a poorly named state.
 *
 * @date 2024-01-23
 * @author Willow Ciesialka
 */

#ifndef FALLINGSAND_CELLS_TYPES_CELLSTATE_H
#define FALLINGSAND_CELLS_TYPES_CELLSTATE_H

#include "CellType.hpp"
#include "CellData.hpp"
#include <exception>

namespace fallingsand
{
    class Cell;

    class CellState
    {
    public:
        CellState(const fallingsand::CellType type, const fallingsand::CellData initial_data) : type(type), data(initial_data) {}

        virtual ~CellState() {}

        /**
         * @brief Move the cell by a certain amount.
         * 
         * @param dx Change in x-position
         * @param dy Change in y-position
        */
        void move(const int dx, const int dy) const;

        /**
         * @brief Clone the current state. This is a necessary function.
         * 
         * @return Clone of the current state.
        */
        virtual CellState* clone() const = 0;

        /**
         * @brief Get cell's data.
         * 
         * @return Cell's data.
        */
        fallingsand::CellData get_data() const {
            return this->data;
        }

        fallingsand::CellType get_type() const {
            return this->type;
        }

        /**
         * @brief Set the cell's data directly.
         * 
         * @param data New data.
        */
        void set_data(const fallingsand::CellData data) {
            this->data = data;
        }

        /**
         * @brief Set the health of the particle.
         *
         * @param health New health.
         */
        void set_health(int health)
        {
            this->data.health = health;
        }

        /**
         * @brief Get the health of the particle.
         *
         * @return Particle's health.
         */
        int get_health() const
        {
            return this->data.health;
        }

        /**
         * @brief Kill the particle.
         */
        void kill()
        {
            this->set_health(0);
        }

        /**
         * @brief Damage the particle by a certain amount.
         * 
         * @param damage_amount Amount to damage by.
        */
        void damage(int damage_amount) {
            this->set_health(this->get_health() - damage_amount);
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
        bool update() {
            this->data.lifetime++;
            // First, step. Then, fall.
            bool change_on_step = this->step();
            this->set_is_falling(this->fall());
            return change_on_step || this->get_is_falling();
        };

        /**
         * @brief Idle update step. Customizable by different state types.
         * 
         * @return True if there was a change this step, false otherwise.
        */
        virtual bool step() = 0;

        /**
         * PROPERTIES
         */

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

        /**
         * @brief Set parent cell.
         * 
         * @param parent New parent.
        */
        void set_parent(fallingsand::Cell* parent){
            this->parent = parent;
        }

        /**
         * @brief Get parent cell.
         * 
         * @return Parent cell.
        */
        fallingsand::Cell* get_parent() const {
            return this->parent;
        }

        /**
         * @brief Get type of cell.
         * 
         * @return Cell type.
        */
        fallingsand::CellType get_type() const;

        /**
         * @brief Get a neighboring cell's state.
         * 
         * @param dx Difference of x values.
         * @param dy Difference of y values.
         * 
         * @return State of neighboring cell if found, nullptr otherwise.
        */
        fallingsand::CellState* get_neighbor(const int dx, const int dy) const;

        /**
         * @brief Set the neighboring cell.
         * 
         * @param dx Difference in x-position.
         * @param dy Difference in y-position.
         * @param type New cell type.
         * @param state New cell state.
        */
        void set_neighbor(const int dx, const int dy, const fallingsand::CellType type) const;
        void set_neighbor(const int dx, const int dy, fallingsand::CellState* state) const;

        /**
         * @brief Do nothing.
        */
        void do_nothing() const { return; }

    private:
        int health;
        bool is_falling;

        fallingsand::Cell* parent;
        fallingsand::CellData data;
        fallingsand::CellType type;
    };
}

#endif