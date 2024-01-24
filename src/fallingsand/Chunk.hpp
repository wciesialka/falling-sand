/**
 * @file Chunk.hpp
 * @brief Declares the Chunk storage.
 *
 * @date 2024-01-23
 * @author Willow Ciesialka
 */

#ifndef FALLINGSAND_CHUNK_H
#define FALLINGSAND_CHUNK_H

namespace fallingsand
{
    class Chunk
    {
    public:
        Chunk() : width(0), height(0), x(0), y(0), update_this_frame(false), update_next_frame(false){};
        Chunk(const unsigned int width, const unsigned int height, unsigned int x, unsigned int y)
            : width(width), height(height), x(x), y(y), update_this_frame(true), update_next_frame(false){};

        /**
         * @brief Get the width of the chunk.
         *
         * @return Chunk width.
         */
        unsigned int get_width() const
        {
            return this->width;
        }

        /**
         * @brief Get the height of the chunk.
         *
         * @return Chunk height.
         */
        unsigned int get_height() const
        {
            return this->height;
        }

        /**
         * @brief Get the x-position of the chunk.
         *
         * @return Chunk's x-position.
         */
        unsigned int get_x() const
        {
            return this->x;
        }

        /**
         * @brief Get the y-position of the chunk.
         *
         * @return Chunk's y-position.
         */
        unsigned int get_y() const
        {
            return this->y;
        }

        /**
         * @brief Shift the update states.
         *
         * @return True if the chunk should update this frame, false otherwise.
         */
        bool shift_update_state()
        {
            bool update = this->update_this_frame;
            this->update_this_frame = this->update_next_frame;
            this->update_next_frame = false;
            return update;
        }

        /**
         * @brief Report that we should update next frame.
         */
        void queue_update()
        {
            this->update_next_frame = true;
        }

        /**
         * @brief Check if a point (x,y) is within chunk bounds.
         * 
         * @param x x-coordinate
         * @param y y-coordinate
         * 
         * @return True if point is in bounds, false otherwise.
        */
        bool point_within_bounds(unsigned int x, unsigned int y) const {
            return (x >= this->x && y >= this->y && x < (this->width + this->x) && y < (this->height + this->y));
        }

    private:
        unsigned int width;
        unsigned int height;

        unsigned int x;
        unsigned int y;

        bool update_this_frame;
        bool update_next_frame;
    };
}

#endif