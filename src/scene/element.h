/*
 *  @file   element.h
 *
 *  @brief  (text, shapes, images, audio, etc)
 */

// TODO: create an entity component system

#pragma once

#include "pch.h"
#include "math/vectors.h"
#include "types.h"

static size_t el_count = 1;

class CGElement
{
public:
    CGElement(EElementType);
    CGElement(EElementType, std::string);
    CGElement(const CGElement&);

    std::string name();
    std::string unique();
    const char* c_str();
    size_t id();
    int duration();
    bool visible();
    bool locked();

protected:
    EElementType c_type = EElementType::NoType;
    size_t c_id = 0;

    std::string m_name;
    bool m_visible = true;
    bool m_locked = false;
    int m_duration = 0; // in frames
private:
    friend class CGManager;
};
