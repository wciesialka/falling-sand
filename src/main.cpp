/**
 * @file main.cpp
 * @brief Main driver file.
 * 
 * Establish screen rendering, run simulation, etc.
 * 
 * @date 2024-01-17
 * @author Willow Ciesialka
*/

#include "sandrenderer/Renderer.hpp"
#include "sandrenderer/Pixel.hpp"
#include <thread>

#define WIDTH 640
#define HEIGHT 360

int main(){
    sandrenderer::Renderer* renderer = new sandrenderer::Renderer(WIDTH, HEIGHT);
    sandrenderer::Pixel* pixel = new sandrenderer::Pixel(100, 100, 200, 100, 0);
    renderer->add_renderable(pixel);

    renderer->render();

    return 0;
}