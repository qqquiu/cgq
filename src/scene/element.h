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
        Element(EElementType type);
        Element(const Element& element) = default;

        std::string Name();
        std::string Unique();
        const char* CStr();
        size_t ID();
        int Duration();
        bool IsVisible();
        bool IsLocked();

        template<typename T, typename... Args>
        T& AddComponent(Args&&... args)
        {
            if (!HasComponent<T>)
            {
                T& component = m_Registry.emplace<T>(std::forward<Args>(args)...);
                return component;
            }
        }

    protected:
        EElementType c_Type = EElementType::None;
        size_t c_ID = 0;

        std::string m_Name;
        bool m_Visible = true;
        bool m_Locked = false;
        int m_Duration = 0; // in frames
    private:
        entt::entity m_EntityHandle = { entt::null };
        friend class Manager;

        void ConstructorAux();

        entt::registry m_Registry;
    };
}
