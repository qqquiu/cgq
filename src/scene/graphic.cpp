#include "pch.h"
#include "Manager.h"

namespace CGQ
{
    Graphic::Graphic(GraphicData& data, entt::entity handle, Manager* manager)
        : m_GraphicHandle(handle), m_Manager(manager)
    {
        m_Manager->Reg().emplace<GraphicData>(m_GraphicHandle, data);
    }

    std::string Graphic::Name()
    {
        return GetData().name;
    }

    uint32_t Graphic::ID()
    {
        return static_cast<uint32_t>(m_GraphicHandle);
    }

    std::string Graphic::Unique()
    {
        return GetData().name + "###" + std::to_string(ID());
    }

    const char* Graphic::c_str()
    {
        return GetData().name.c_str();
    }

    uint64_t Graphic::Duration()
    {
        return GetData().duration;
    }

    size_t Graphic::Elements()
    {
        return m_Elements.size();
    }

    GraphicData& Graphic::GetData()
    {
        return m_Manager->Reg().get<GraphicData>(m_GraphicHandle);
    }

    Graphic::operator bool() const
    {
        return m_GraphicHandle != entt::null;
    }
}