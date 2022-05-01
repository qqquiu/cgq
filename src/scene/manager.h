/*
 *  @file   manager.h
 *
 *  @brief  Singleton to creates and manage instances of graphics and elements.
 *          Any data access should go through this class.
 */

#pragma once

#include "pch.h"
#include "library.h"

class CGManager
{
public:
    // Graphics
    void        gfx_add();
    void        gfx_remove();
    void        gfx_duplicate();
    void        gfx_rename(std::string);
    size_t      n_gfx();
    CGGraphic*  gfx();
    CGGraphic*  gfx(size_t);
    size_t      gfx_idx();
    void        select_gfx(size_t);
    void        deselect_gfx();

    // Elements
    void        el_add(EElementType);
    void        el_remove();
    void        el_duplicate();
    void        el_rename(std::string);
    size_t      n_el();
    CGElement*  el();
    CGElement*  el(size_t);
    size_t      el_idx();
    void        select_el(size_t);
    void        deselect_el();

private:
    CGLibrary  m_library = { this };
    CGGraphic* m_graphic = nullptr;
    CGElement* m_element = nullptr;
};
