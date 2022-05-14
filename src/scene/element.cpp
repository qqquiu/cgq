#include "pch.h"
#include "Manager.h"

namespace CGQ
{
    Element::Element(ElementData& data, entt::entity handle, Manager* manager)
        : m_ElementHandle(handle), m_Manager(manager)
    {
        m_Manager->Reg().emplace<ElementData>(m_ElementHandle, data);
    }

    std::string Element::Name()
    {
        return GetData().name;
    }

    uint32_t Element::ID()
    {
        return static_cast<uint32_t>(m_ElementHandle);
    }

    std::string Element::Unique()
    {
        return GetData().name + "###" + std::to_string(ID());
    }

    const char* Element::c_str()
    {
        return GetData().name.c_str();
    }

    uint64_t Element::Duration()
    {
        return GetData().duration;
    }

    bool Element::IsVisible()
    {
        return GetData().isVisible;
    }

    bool Element::IsLocked()
    {
        return GetData().isLocked;
    }

    template<typename T, typename... Args>
    T& Element::AddComponent(Args&&... args)
    {
        T& component = m_Manager->Reg().emplace<T>(m_ElementHandle, std::forward<Args>(args)...);
        return component;
    }

    template<typename T>
    T& Element::GetComponent()
    {
        return m_Manager->Reg().get<T>(m_ElementHandle);
    }

    template<typename T>
    bool Element::HasComponent()
    {
        return m_Manager->Reg().has<T>(m_ElementHandle);
    }

    template<typename T>
    void Element::RemoveComponent()
    {
        if (HasComponent<T>())
        {
            m_Manager->Reg().remove<T>(m_ElementHandle);
        }
    }

    ElementData& Element::GetData()
    {
        return m_Manager->Reg().get<ElementData>(m_ElementHandle);
    }

    Element::operator bool() const
    {
        return m_ElementHandle != entt::null;
    }
}