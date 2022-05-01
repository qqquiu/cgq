#include "pch.h"
#include "graphic.h"

CGGraphic::CGGraphic()
    : m_name ("Unnamed graphic ( " + std::to_string(gfx_count) + ")"), c_id(gfx_count)
{
    gfx_count++;
    m_elements.reserve(static_cast<size_t>(8));
    std::cout << "Default constructor called." << std::endl;
}

CGGraphic::CGGraphic(std::string s)
    : m_name( s ), c_id ( gfx_count )
{
    gfx_count++;
    m_elements.reserve(static_cast<size_t>(8));
    std::cout << "String constructor called." << std::endl;
}

CGGraphic::CGGraphic(const CGGraphic& g)
    :
    m_name (g.m_name),
    c_id (gfx_count),
    m_el_idx (g.m_el_idx),
    m_elements(g.m_elements)
{
    gfx_count++;
    std::cout << "Copy constructor called." << std::endl;
}

std::string CGGraphic::name()
{
    return m_name;
}

std::string CGGraphic::unique()
{
    std::string str = m_name;
    str += "###";
    str += std::to_string(c_id);
    return str;
}

const char* CGGraphic::cstr()
{
    return m_name.c_str();
}

size_t CGGraphic::id()
{
    return c_id;
}

size_t CGGraphic::elements()
{
    return m_elements.size();
}

size_t CGGraphic::idx()
{
    return m_el_idx;
}

CGElement* CGGraphic::get()
{
    return elements() ? &m_elements[m_el_idx] : nullptr;
}

CGElement* CGGraphic::get(size_t i)
{
    if (i < 0 || i >= elements())
    {
        return nullptr;
    }
    else
    {
        m_el_idx = i;
        return &m_elements[i];
    }
}

void CGGraphic::pop()
{
    m_elements.erase(m_elements.begin() + m_el_idx);

    if ( elements() )
    {
        if (m_el_idx)
            m_el_idx--;
    }
    else
    {
        m_el_idx = static_cast<size_t>(-1);
    }
}

void CGGraphic::add(CGElement e)
{
    m_elements.push_back(e);
    m_el_idx = elements() - 1;
}
