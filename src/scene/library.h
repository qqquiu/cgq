/*
 *  @file   library.h
 *
 *  @brief  Collection of CGGraphics currently available to open
 *          in the editor or playback to the outputs.
 */

#pragma once
#include "Graphic.h"

namespace CGQ
{
    class Library
    {
    public:
        Library(const Manager* m);

        size_t Graphics();
        size_t Index();

    private:
        friend class Manager;

        const Manager* c_ManagerPtr;
        size_t m_Index = static_cast<size_t>(-1);

        std::vector<Graphic> m_Graphics;

        Graphic* Get();
        Graphic* Get(size_t);
        void Pop();
        void Add(Graphic);
    };
}