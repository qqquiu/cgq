#include "pch.h"
#include "library.h"

size_t CGLibrary::idx()
{
    return m_gfx_idx;
}

size_t CGLibrary::graphics()
{
    return m_graphics.size();
}

CGGraphic* CGLibrary::get()
{
    return graphics() ? &m_graphics[m_gfx_idx] : nullptr;
}

CGGraphic* CGLibrary::get(size_t i)
{
    if (i < 0 || i >= graphics())
    {
        return nullptr;
    }
    else
    {
        m_gfx_idx = i;
        return &m_graphics[i];
    }
}

void CGLibrary::pop()
{
    m_graphics.erase(m_graphics.begin() + m_gfx_idx);

    if ( graphics() )
    {
        if (m_gfx_idx)
            m_gfx_idx--;
    }
    else
    {
        m_gfx_idx = static_cast<size_t>(-1);
    }
}

void CGLibrary::add(CGGraphic g)
{
    m_graphics.push_back(g);
    m_gfx_idx = graphics() - 1;
}
