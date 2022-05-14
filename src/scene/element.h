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
        uint32_t ID();
        std::string Unique();
        const char* c_str();
        uint64_t Duration();
        bool IsVisible();
        bool IsLocked();

        template<typename T, typename... Args>
        T& AddComponent(Args&&... args);

        template<typename T>
        T& GetComponent();

        template<typename T>
        bool HasComponent();

        template<typename T>
        void RemoveComponent();

        operator bool() const;

    private:
        friend class Manager;
        Manager* m_Manager;

        entt::entity m_ElementHandle = { entt::null };

        ElementData& GetData();
    };
}
