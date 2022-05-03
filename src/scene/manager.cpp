#include "pch.h"
#include "Manager.h"

namespace CGQ
{
    uint64_t g_GraphicCount = 0;
    uint64_t g_ElementCount = 0;

    // Create a new Graphic instance and add it to library
    void Manager::AddGraphic()
    {
        m_Library.Add();
        m_Graphic = m_Library.Get();
        m_Element = nullptr;
    }

    // Remove currently selected graphic
    void Manager::RemoveGraphic()
    {
        m_Library.Pop();
        m_Graphic = m_Library.Get();
        m_Element = m_Graphic ? m_Graphic->Get() : nullptr;
    }

    // Duplicate currently selected graphic
    void Manager::DuplicateGraphic()
    {   
        m_Library.Add();
        m_Graphic = m_Library.Get();
        m_Element = m_Graphic->Get();
    }

    // Rename currently selected graphic
    void Manager::RenameGraphic(std::string s)
    {
        m_Graphic->m_Name = s;
    }

    // Number of graphics in library
    size_t Manager::GraphicCount()
    {
        return m_Library.Graphics();
    }

    // Get currently selected graphic
    Graphic* Manager::GetGraphic()
    {
        return m_Graphic;
    }

    // Get graphic by index
    Graphic* Manager::GetGraphic(size_t i)
    {
        return m_Library.Get(i);
    }

    // Get selected graphic index
    size_t Manager::GraphicIndex()
    {
        return m_Library.Index();
    }

    // Select graphic by index
    void Manager::SelectGraphic(size_t i)
    {
        m_Library.m_Index = i;
        m_Graphic = m_Library.Get();
        m_Element = m_Graphic ? m_Graphic->Get() : nullptr;
    }

    void Manager::DeselectGraphic()
    {
        //m_graphic = nullptr;
    }

    // Create new child-of-Element instance and pass it to currently selected graphic
    void Manager::AddElement(EElementType type)
    {
        std::string s = "Element " + std::to_string(g_ElementCount);
        std::string tmp_type; // DEBUG
        switch (type)
        {
        case EElementType::None:
        {

            tmp_type = "(No Type)";

            break;
        }
        case EElementType::Text:
        {
            tmp_type = "(Text)";
            break;
        }
        case EElementType::Img:
        {
            tmp_type = "(Image)";
            break;
        }
        case EElementType::ImgSeq:
        {
            tmp_type = "(Image Sequence)";
            break;
        }
        case EElementType::Audio:
        {
            tmp_type = "(Audio)";
            break;
        }
        default:
        {
            tmp_type = "(Invalid)";
        }
        }
        std::string e_name = s + " " + tmp_type;

        m_Graphic->Add(type);
        m_Element = m_Graphic->Get();
    }

    // Remove element from currently selected graphic
    void Manager::RemoveElement()
    {
        m_Graphic->Pop();
        m_Element = m_Graphic->Get();
    }

    // Duplicate element inside current graphic
    void Manager::DuplicateElement()
    {
        m_Graphic->Add(m_Element->c_Type);
        m_Element = m_Graphic->Get();
    }

    void Manager::RenameElement(std::string s)
    {
        m_Element->m_Name = s;
    }

    size_t Manager::ElementCount()
    {
        return m_Graphic->m_Elements.size();
    }

    Element* Manager::GetElement()
    {
        return m_Element;
    }

    Element* Manager::GetElement(size_t i)
    {
        return &m_Graphic->m_Elements[i];
    }

    size_t Manager::ElementIndex()
    {
        return m_Graphic->Index();
    }

    void Manager::SelectElement(size_t i)
    {
        m_Graphic->m_Index = i;
        m_Element = m_Graphic->Get();
    }

    void Manager::DeselectElement()
    {
        m_Element = nullptr;
    }
}