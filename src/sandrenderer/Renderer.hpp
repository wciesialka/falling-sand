/**
 * @file Renderer.hpp
 * @brief Contains declerations for the Renderer class.
 *
 * @date 2024-01-17
 * @author Willow Ciesialka
 */

#ifndef SANDRENDERER_RENDERER_H
#define SANDRENDERER_RENDERER_H

#include <vector>
#include <algorithm>
#include "Renderable.hpp"
#include "Window.hpp"

namespace sandrenderer
{
    /**
     * @brief Renderer, responsible for creating a window and handling events. 
    */
    class Renderer
    {
    public:
        typedef std::vector<sandrenderer::Renderable *> Renderables;

        /**
         * @brief Create a renderer and window.
         * 
         * @param width Width of renderer window (in px).
         * @param height height of renderer window (in px).
        */
        Renderer(int width, int height)
        {
            this->window = new sandrenderer::Window(width, height, "Falling Sand");
            this->renderables = new std::vector<sandrenderer::Renderable *>();
        }

        /**
         * @brief Destructor.
        */
        ~Renderer(){
            delete this->window;
        }

        /**
         * @brief Add renderable to inner renderables list.
         */
        void add_renderable(sandrenderer::Renderable *renderable)
        {
            this->renderables->push_back(renderable);
        }

        /**
         * @brief Remove renderable from renderables list.
         * 
         * @return True if the remove was successful, false if not (element was not found).
         */
        bool remove_renderable(sandrenderer::Renderable* renderable){
            auto it = std::find(this->renderables->begin(), this->renderables->end(), renderable);
            if(it == this->renderables->end()){
                return false;
            }
            this->renderables->erase(it);
            return true;
        }

        /**
         * @brief Get the renderer's window.
         * 
         * @returns The renderer's window.
        */
        sandrenderer::Window* get_window() const{
            return this->window;
        }

        /**
         * @brief Begin the rendering process.
        */
        void begin_rendering();

        /**
         * @brief Check if the window is open or not.
         * 
         * @return True if the window is open, false otherwise.
        */
        bool is_open() const {
            return this->get_window()->get_render_window().isOpen();
        }

    private:
        sandrenderer::Window *window;
        Renderables *renderables;
    };
}

#endif