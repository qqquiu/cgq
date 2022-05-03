/*
 *  @file   Element.h
 *
 *  @brief  (text, shapes, images, audio, etc)
 */

// TODO: create an entity component system

#pragma once

#include "Math.h"
#include "Types.h"
#include "Components.h"
#include "entt.hpp"

namespace CGQ
{
    class Element
    {
    public:
        Element(EElementType);
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
//        std::vector<Component> m_Components;
        size_t c_ID = 0;

        std::string m_Name;
        bool m_Visible = true;
        bool m_Locked = false;
        int m_Duration = 0; // in frames
    private:
        friend class Manager;

        void ConstructorAux();

        entt::registry m_Registry;
    };
}
