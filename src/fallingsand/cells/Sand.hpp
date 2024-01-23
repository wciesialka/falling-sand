/**
 * @file Sand.hpp
 * @brief Contains declerations for the Sand particle.
 * 
 * @date 2024-01-23
 * @author Willow Ciesialka
*/

#ifndef FALLINGSAND_CELLS_SAND_H
#define FALLINGSAND_CELLS_SAND_H

#include "Particle.hpp"
#include "types/SandType.hpp"

namespace fallingsand {
    class Sand : public fallingsand::Particle {
        public:
            Sand() : Particle(205, 170, 109, new fallingsand::SandType(), new fallingsand::SandType()) {}
    };
}

#endif