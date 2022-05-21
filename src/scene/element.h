/*
 *  @file   Element.h
 *
 *  @brief  todo
 * 
 */

#pragma once

#include "entt.hpp"
#include "Types.h"
#include "Components.h"

namespace CGQ
{
    class Manager;

    class Element
    {
    public:
        Element() = delete;
        Element(ElementData& data, entt::entity handle, Manager* manager);
        Element(const Element& element) = default;
        ~Element() = default;

        std::string Name();
        Type Type();
        uint32_t ID();
        std::string Unique();
        const char* c_str();
        uint64_t Duration();
        bool IsVisible();
        bool IsLocked();

        /*
        template<typename T, typename... Args>
        T& AddComponent(Args&&... args)
        {
            T& component = m_Manager->Reg().emplace<T>(m_ElementHandle, std::forward<Args>(args)...);
            return component;
        }

        template<typename T>
        T& GetComponent()
        {
            return m_Manager->Reg().get<T>(m_ElementHandle);
        }

        template<typename T>
        bool HasComponent()
        {
            return m_Manager->Reg().has<T>(m_ElementHandle);
        }

        template<typename T>
        void RemoveComponent()
        {
            if (HasComponent<T>())
            {
                m_Manager->Reg().remove<T>(m_ElementHandle);
            }
        }
        */

        operator bool() const;

    private:
        friend class Manager;
        Manager* m_Manager = nullptr;

        entt::entity m_ElementHandle = { entt::null };

        ElementData& GetData();
    };
}
