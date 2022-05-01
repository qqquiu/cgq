#include "pch.h"
#include "manager.h"

// Create a new CGGraphic instance and add it to library
void CGManager::gfx_add()
{
    std::string s = "Graphic " + std::to_string(gfx_count);

    m_library.add(CGGraphic{s});
    m_graphic = m_library.get();
    m_element = nullptr;
}

// Remove currently selected graphic
void CGManager::gfx_remove()
{
    m_library.pop();
    m_graphic = m_library.get();
    m_element = m_graphic ? m_graphic->get() : nullptr;
}

// Duplicate currently selected graphic
void CGManager::gfx_duplicate()
{
    m_library.add(CGGraphic{*m_graphic});
    m_graphic = m_library.get();
    m_element = m_graphic->get();
}

// Rename currently selected graphic
void CGManager::gfx_rename(std::string s)
{
    m_graphic->m_name = s;
}

// Number of graphics in library
size_t CGManager::n_gfx()
{
    return m_library.graphics();
}

// Get currently selected graphic
CGGraphic* CGManager::gfx()
{
    return m_graphic;
}

// Get graphic by index
CGGraphic* CGManager::gfx(size_t i)
{
    return m_library.get(i);
}

// Get selected graphic index
size_t CGManager::gfx_idx()
{
    return m_library.idx();
}

// Select graphic by index
void CGManager::select_gfx(size_t i)
{
    m_library.m_gfx_idx = i;
    m_graphic = m_library.get();
    m_element = m_graphic ? m_graphic->get() : nullptr;
}

void CGManager::deselect_gfx()
{
    //m_graphic = nullptr;
}

// Create new child-of-CGElement instance and pass it to currently selected graphic
void CGManager::el_add(EElementType type)
{
    std::string s = "Element " + std::to_string(el_count);
    std::string tmp_type; // DEBUG
    switch (type)
    {
    case EElementType::NoType:
    {
        
        tmp_type = "(No Type)";
        
        break;
    }
    case EElementType::Text:
    {
        tmp_type = "(Text)";
        break;
    }
    case EElementType::Img:
    {
        tmp_type = "(Image)";
        break;
    }
    case EElementType::ImgSeq:
    {
        tmp_type = "(Image Sequence)";
        break;
    }
    case EElementType::Audio:
    {
        tmp_type = "(Audio)";
        break;
    }
    default:
    {
        tmp_type = "(Invalid)";
    }
    }
    std::string e_name = s + " " + tmp_type;
    CGElement e = { type, e_name };

    m_graphic->add(e);
    m_element = m_graphic->get();
}

// Remove element from currently selected graphic
void CGManager::el_remove()
{
    m_graphic->pop();
    m_element = m_graphic->get();
}

// Duplicate element inside current graphic
void CGManager::el_duplicate()
{
    CGElement e{ *m_element };
    m_graphic->add(e);
    m_element = m_graphic->get();
}

void CGManager::el_rename(std::string s)
{
    m_element->m_name = s;
}

size_t CGManager::n_el()
{
    return m_graphic->m_elements.size();
}

CGElement* CGManager::el()
{
    return m_element;
}

CGElement* CGManager::el(size_t i)
{
    return &m_graphic->m_elements[i];
}

size_t CGManager::el_idx()
{
    return m_graphic->idx();
}

void CGManager::select_el(size_t i)
{
    m_graphic->m_el_idx = i;
    m_element = m_graphic->get();
}

void CGManager::deselect_el()
{
    m_element = nullptr;
}
