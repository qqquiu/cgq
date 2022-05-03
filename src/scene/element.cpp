#include "pch.h"
#include "Element.h"

namespace CGQ
{
    extern uint64_t g_ElementCount;

    Element::Element(EElementType type)
        : c_Type{ type }, c_ID{ ++g_ElementCount }
    {
        entt::entity element = m_Registry.create();

        switch (c_Type)
        {
        case EElementType::None:
        default:
            {
                // shouldnt happen ever, so we do nothing
                break;
            }
        case EElementType::Text:
        {
            m_Registry.emplace<TransformComponent>(element);
            m_Registry.emplace<TextComponent>(element);
            m_Registry.emplace<ColorComponent>(element);
            break;
        }
        case EElementType::Img:
        {
            m_Registry.emplace<TransformComponent>(element);
            m_Registry.emplace<ImgComponent>(element);
            break;
        }
        case EElementType::ImgSeq:
        {
            m_Registry.emplace<TransformComponent>(element);
            m_Registry.emplace<ImgSequenceComponent>(element);
            break;
        }
        case EElementType::Audio:
        {
            m_Registry.emplace<AudioComponent>(element);
            break;
        }
        }
    }

    Element::Element(const Element& el)
        :
        c_Type{ el.c_Type },
        c_ID{ g_ElementCount },
        m_Name{ el.m_Name },
        m_Visible{ el.m_Visible },
        m_Locked{ el.m_Locked },
        m_Duration{ el.m_Duration }
        //m_Registry{ el.m_Registry }
    {
        ++g_ElementCount;
    }

    void Element::ConstructorAux()
    {

    }

    std::string Element::Name()
    {
        return m_Name;
    }

    std::string Element::Unique()
    {
        std::string str = m_Name;
        str += "###";
        str += std::to_string(c_ID);
        return str;
    }

    const char* Element::CStr()
    {
        return m_Name.c_str();
    }

    size_t Element::ID()
    {
        return c_ID;
    }

    int Element::Duration()
    {
        return m_Duration;
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