#include "pch.h"
#include "Element.h"

namespace CGQ
{
    extern uint64_t g_ElementCount;

    Element::Element(EElementType type, Graphic* owner)
    {
        m_EntityHandle = m_Registry.create();

        m_Registry.emplace<MetadataComponent>(m_EntityHandle, type, owner);
    }

    std::string Element::Name()
    {
        MetadataComponent& data = m_Registry.get<MetadataComponent>(m_EntityHandle);
        return data.Name;
    }

    std::string Element::Unique()
    {
        MetadataComponent& data = m_Registry.get<MetadataComponent>(m_EntityHandle);
        return data.Name + "###" + std::to_string(data.ID);
    }

    const char* Element::c_str()
    {
        MetadataComponent& data = m_Registry.get<MetadataComponent>(m_EntityHandle);
        return data.Name.c_str();
    }

    uint64_t Element::ID()
    {
        MetadataComponent& data = m_Registry.get<MetadataComponent>(m_EntityHandle);
        return data.ID;
    }

    uint64_t Element::Duration()
    {
        MetadataComponent& data = m_Registry.get<MetadataComponent>(m_EntityHandle);
        return data.Duration;
    }

    bool Element::IsVisible()
    {
        return m_Visible;
    }

    bool Element::IsLocked()
    {
        return m_Locked;
    }
}