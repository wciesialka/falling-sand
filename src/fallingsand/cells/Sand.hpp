/**
 * @file Sand.hpp
 * @brief Contains declerations for the Sand particle type.
 * 
 * @date 2024-01-23
 * @author Willow Ciesialka
*/

#ifndef FALLINGSAND_CELLS_SAND_H
#define FALLINGSAND_CELLS_SAND_H

#include "Particle.hpp"

namespace fallingsand {
    class Sand : public fallingsand::Particle {
        public:
            Sand() : fallingsand::Particle(205, 170, 109) {};
    };
}

#endif