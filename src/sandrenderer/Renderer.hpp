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
#include "sandrenderer/Renderable.hpp"
#include "sandrenderer/Window.hpp"

namespace sandrenderer
{
    class Renderer
    {
    public:
        typedef std::vector<sandrenderer::Renderable *> Renderables;

        Renderer(int width, int height)
        {
            this->window = new sandrenderer::Window(width, height, "Falling Sand");
            this->renderables = new std::vector<sandrenderer::Renderable *>();
        }

        ~Renderer(){
            delete this->window;
            delete this->renderables;
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

        void render() const;

    private:
        sandrenderer::Window *window;
        Renderables *renderables;
    };
}

#endif