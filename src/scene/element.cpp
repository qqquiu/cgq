#include "pch.h"
#include "Element.h"

namespace CGQ
{
    extern uint64_t g_ElementCount;

    Element::Element(EElementType e)
        : c_Type{ e }, c_ID{ g_ElementCount }
    {
        ++g_ElementCount;
    }

    Element::Element(EElementType e, std::string s)
        : c_Type{ e }, c_ID{ g_ElementCount }, m_Name{ s }
    {
        ++g_ElementCount;
    }

    Element::Element(const Element& el)
        :
        c_Type{ el.c_Type },
        c_ID{ g_ElementCount },
        m_Name{ el.m_Name },
        m_Visible{ el.m_Visible },
        m_Locked{ el.m_Locked },
        m_Duration{ el.m_Duration }
    {
        ++g_ElementCount;
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