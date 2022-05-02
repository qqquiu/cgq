#include "pch.h"
#include "Graphic.h"

namespace CGQ
{
    extern uint64_t g_GraphicCount;

    Graphic::Graphic()
        : m_Name("Unnamed graphic ( " + std::to_string(g_GraphicCount) + ")"), c_ID(g_GraphicCount)
    {
        ++g_GraphicCount;
        m_Elements.reserve(static_cast<size_t>(8));
        std::cout << "Default constructor called." << std::endl;
    }

    Graphic::Graphic(std::string s)
        : m_Name(s), c_ID(g_GraphicCount)
    {
        ++g_GraphicCount;
        m_Elements.reserve(static_cast<size_t>(8));
        std::cout << "String constructor called." << std::endl;
    }

    Graphic::Graphic(const Graphic& g)
        :
        m_Name(g.m_Name),
        c_ID(g_GraphicCount),
        m_Index(g.m_Index),
        m_Elements(g.m_Elements)
    {
        ++g_GraphicCount;
        std::cout << "Copy constructor called." << std::endl;
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

    void Graphic::Add(Element e)
    {
        m_Elements.push_back(e);
        m_Index = Elements() - 1;
    }
}