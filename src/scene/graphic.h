/*
 *  @file   graphic.h
 *
 *  @brief  Collection of graphic elements or motion created in
 *          the editor and played back to outputs.
 */

#pragma once

#include "pch.h"
#include "element.h"

static size_t gfx_count = 1;

class CGGraphic
{
public:
    explicit CGGraphic();
    explicit CGGraphic(std::string);
    explicit CGGraphic(const CGGraphic&);

    std::string name();
    std::string unique();
    const char* cstr();
    size_t id();
    size_t elements();
    size_t idx();
    // todo: thumbnail ?

private:
    friend class CGManager;

    size_t c_id;
    size_t m_el_idx = static_cast<size_t>(-1);

    std::string m_name;
    std::vector<CGElement> m_elements;
    int duration = 60;

    CGElement* get();
    CGElement* get(size_t);
    void pop();
    void add(CGElement);
};
