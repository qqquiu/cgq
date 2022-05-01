/*
 *  @file   library.h
 *
 *  @brief  Collection of CGGraphics currently available to open
 *          in the editor or playback to the outputs.
 */

#pragma once
#include "pch.h"
#include "graphic.h"

class CGLibrary
{
public:
    CGLibrary(const CGManager* m)
        : c_ptr(m)
    {
        m_graphics.reserve(static_cast<size_t>(16));
    }

    size_t graphics();
    size_t idx();

private:
    friend class CGManager;

    const CGManager* c_ptr;
    size_t m_gfx_idx = static_cast<size_t>(-1);
    
    std::vector<CGGraphic> m_graphics;

    CGGraphic* get();
    CGGraphic* get(size_t);
    void pop();
    void add(CGGraphic);
};
