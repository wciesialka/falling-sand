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
#include "../../sandrenderer/Pixel.hpp"

namespace fallingsand {
    class Particle : public Cell {
        public:
            Particle(const int r, const int g, const int b) : Cell(new sandrenderer::Pixel(r, g, b)) {};
    };
}

#endif