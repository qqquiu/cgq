#include "pch.h"
#include "Graphic.h"

namespace CGQ
{
    extern uint64_t g_GraphicCount;
    extern uint64_t g_ElementCount;

    Graphic::Graphic()
    {
        entt::entity element = m_Registry.create();
    }

    Graphic::~Graphic()
    {

    }

    std::string Graphic::Name()
    {
        return m_Name;
    }

    std::string Graphic::Unique()
    {
        std::string str = m_Name;
        str += "###";
        str += std::to_string(c_ID);
        return str;
    }

    const char* Graphic::CStr()
    {
        return m_Name.c_str();
    }

    size_t Graphic::ID()
    {
        return c_ID;
    }

    size_t Graphic::Elements()
    {
        return m_Elements.size();
    }

    size_t Graphic::Index()
    {
        return m_Index;
    }

    Element* Graphic::Get()
    {
        return Elements() ? &m_Elements[m_Index] : nullptr;
    }

    Element* Graphic::Get(size_t i)
    {
        if (i < 0 || i >= Elements())
        {
            return nullptr;
        }
        else
        {
            m_Index = i;
            return &m_Elements[i];
        }
    }

    void Graphic::Pop()
    {
        m_Elements.erase(m_Elements.begin() + m_Index);

        if (Elements())
        {
            if (m_Index)
                m_Index--;
        }
        else
        {
            m_Index = static_cast<size_t>(-1);
        }
    }

    void Graphic::Add(EElementType type)
    {
        std::string str = "Element " + std::to_string(g_ElementCount);
        m_Elements.emplace_back(type);
        m_Index = Elements() - 1;
    }
}