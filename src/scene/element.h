/*
 *  @file   Element.h
 *
 *  @brief  (text, shapes, images, audio, etc)
 */

#pragma once

#include "Core/MathLib.h"
#include "Types.h"
#include "Components.h"
#include "entt.hpp"

namespace CGQ
{
    class Element
    {
    public:
        Element(EElementType type, Graphic* owner);
        Element(const Element& element) = default;

        ~Element() = default;

        std::string Name();
        std::string Unique();
        const char* c_str();
        uint64_t ID();
        uint64_t Duration();
        bool IsVisible();
        bool IsLocked();

    protected:
        bool m_Visible = true;
        bool m_Locked = false;
    private:
        friend class Manager;
        
        entt::entity m_EntityHandle = { entt::null };
        entt::registry m_Registry;
    };
}
