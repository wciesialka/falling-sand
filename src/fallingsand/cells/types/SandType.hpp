/**
 * @file Sand.hpp
 * @brief Contains declerations for the Sand particle type.
 * 
 * @date 2024-01-23
 * @author Willow Ciesialka
*/

#ifndef FALLINGSAND_CELLS_TYPES_SAND_H
#define FALLINGSAND_CELLS_TYPES_SAND_H

#include "ParticleState.hpp"

namespace fallingsand {
    class SandType: public fallingsand::ParticleState {
        public:
            SandType() : fallingsand::ParticleState(1) {};
            virtual int get_falling_speed() const { return 3; }

            virtual void on_collision(const ParticleState *other, ParticleState *my_new_state, ParticleState *their_new_state) const {
                other->get_health();
                my_new_state->get_health();
                their_new_state->get_health();
                return;
            }
    };
}

#endif