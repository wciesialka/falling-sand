/**
 * @file Pixel.cpp
 * @brief Contans definitions for the Pixel renderable class.
 * 
 * @date 2024-01-17
 * @author Willow Ciesialka
*/

#include "Pixel.hpp"
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>

void sandrenderer::Pixel::render(sf::RenderWindow& window) const{
    sf::Vector2u size = window.getSize();
    sf::Vector2f pos = this->get_render_position();
    int x = pos.x * sandrenderer::Pixel::ACTUAL_SIZE;
    int y = pos.y * sandrenderer::Pixel::ACTUAL_SIZE;
    int width = (int)(size.x);
    int height = (int)(size.y);
    // If OOB, don't bother rendering.
    if(x < 0 || x > width || y < 0 || y > height){
        return;
    }
    sf::RectangleShape rect(sf::Vector2f(sandrenderer::Pixel::ACTUAL_SIZE, sandrenderer::Pixel::ACTUAL_SIZE));
    rect.setFillColor(this->get_color());
    rect.setPosition(sf::Vector2f(x, y));
    window.draw(rect);
}