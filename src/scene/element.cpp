#include "pch.h"
#include "element.h"

CGElement::CGElement(EElementType e)
    : c_type{ e }, c_id{ el_count }
{
    el_count++;
}

CGElement::CGElement(EElementType e, std::string s)
    : c_type{ e }, c_id{ el_count }, m_name{ s }
{
    el_count++;
}

CGElement::CGElement(const CGElement& el)
    :
    c_type { el.c_type },
    c_id { el_count },
    m_name { el.m_name },
    m_visible { el.m_visible },
    m_locked { el.m_locked },
    m_duration { el.m_duration }
{
    el_count++;
}

std::string CGElement::name()
{
    return m_name;
}

std::string CGElement::unique()
{
    std::string str = m_name;
    str += "###";
    str += std::to_string(c_id);
    return str;
}

const char* CGElement::c_str()
{
    return m_name.c_str();
}

size_t CGElement::id()
{
    return c_id;
}

int CGElement::duration()
{
    return m_duration;
}

bool CGElement::visible()
{
    return m_visible;
}

bool CGElement::locked()
{
    return m_locked;
}
