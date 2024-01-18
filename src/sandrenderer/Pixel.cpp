/**
 * @file Pixel.cpp
 * @brief Contans definitions for the Pixel renderable class.
 * 
 * @date 2024-01-17
 * @author Willow Ciesialka
*/

#include "sandrenderer/Pixel.hpp"
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>

void sandrenderer::Pixel::render(const sf::Window& window) const{
    sf::Vector2u size = window.getSize();
    sf::Vector2f pos = this->get_position();
    // If OOB, don't bother rendering.
    if(pos.x < 0 || pos.x > size.x || pos.y < 0 || pos.y > size.y){
        return;
    }
    sf::VertexArray pixel(sf::Points, 1);
    pixel[0].position = this->get_position();
    pixel[1].color = this->get_color();
    window.draw(pixel, 1, sf::Points);
}