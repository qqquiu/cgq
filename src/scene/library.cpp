#include "pch.h"
#include "Library.h"

namespace CGQ
{
    Library::Library(const Manager* m)
        : c_ManagerPtr(m)
    {
        m_Graphics.reserve(static_cast<size_t>(16));
    }

    size_t Library::Index()
    {
        return m_Index;
    }

    size_t Library::Graphics()
    {
        return m_Graphics.size();
    }

    Graphic* Library::Get()
    {
        return Graphics() ? &m_Graphics[m_Index] : nullptr;
    }

    Graphic* Library::Get(size_t i)
    {
        if (i < 0 || i >= Graphics())
        {
            return nullptr;
        }
        else
        {
            m_Index = i;
            return &m_Graphics[i];
        }
    }

    void Library::Pop()
    {
        m_Graphics.erase(m_Graphics.begin() + m_Index);

        if (Graphics())
        {
            if (m_Index)
                m_Index--;
        }
        else
        {
            m_Index = static_cast<size_t>(-1);
        }
    }

    void Library::Add(Graphic g)
    {
        m_Graphics.push_back(g);
        m_Index = Graphics() - 1;
    }
}