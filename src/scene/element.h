/*
 *  @file   Element.h
 *
 *  @brief  (text, shapes, images, audio, etc)
 */

// TODO: create an entity component system

#pragma once

#include "Math/Vectors.h"
#include "Types.h"

namespace CGQ
{
    class Element
    {
    public:
        Element(EElementType);
        Element(EElementType, std::string);
        Element(const Element&);

        std::string Name();
        std::string Unique();
        const char* CStr();
        size_t ID();
        int Duration();
        bool IsVisible();
        bool IsLocked();

    protected:
        EElementType c_Type = EElementType::None;
        size_t c_ID = 0;

        std::string m_Name;
        bool m_Visible = true;
        bool m_Locked = false;
        int m_Duration = 0; // in frames
    private:
        friend class Manager;
    };
}
