#include "pch.h"
#include "Manager.h"

namespace CGQ
{
    void Manager::AddGraphic()
    {
        GraphicData g_data {"New Graphic", 0};
        Graphic g = {g_data, m_Registry.create(), this};
        m_Graphics.push_back(g);
        m_SelectedGraphicIndex = m_Graphics.size() - 1;
        m_SelectedGraphic = &m_Graphics[m_SelectedGraphicIndex];
        m_SelectedElement = nullptr;
    }

    void Manager::DuplicateGraphic()
    {
        /*
        Graphic g = *m_SelectedGraphic;
        GraphicData& data = m_Registry.get<GraphicData>(g.m_GraphicHandle);
        g.m_GraphicHandle = m_Registry.create();
        data.name += " (1)";
        m_Graphics.push_back(g);
        */
    }

    void Manager::ImportGraphic()
    {

    }

    void Manager::ExportGraphic()
    {

    }

    void Manager::MoveGraphicUp()
    {
        if (m_SelectedGraphicIndex)
            std::swap(m_Graphics[m_SelectedGraphicIndex], m_Graphics[m_SelectedGraphicIndex-1]);
    }

    void Manager::MoveGraphicDown()
    {
        if (!m_SelectedGraphicIndex)
            std::swap(m_Graphics[m_SelectedGraphicIndex], m_Graphics[m_SelectedGraphicIndex + 1]);
    }

    void Manager::MoveGraphicTop()
    {
        // todo
    }

    void Manager::MoveGraphicBottom()
    {
        // todo
    }

    size_t Manager::GraphicCount()
    {
        return m_Graphics.size();
    }

    int Manager::GraphicIndex()
    {
        return m_SelectedGraphicIndex;
    }

    Graphic* Manager::GetGraphic()
    {
        return m_SelectedGraphic;
    }

    Graphic* Manager::GetGraphic(int i)
    {
        return &m_Graphics[i];
    }

    void Manager::SelectGraphic(int i)
    {
        m_SelectedGraphicIndex = i;
        m_SelectedGraphic = &m_Graphics[m_SelectedGraphicIndex];
    }

    void Manager::RenameGraphic(std::string newname)
    {
        GraphicData& g_data = m_Registry.get<GraphicData>(m_SelectedGraphic->m_GraphicHandle);
        g_data.name = newname;
    }

    void Manager::RemoveGraphic()
    {
        m_Graphics.erase(m_Graphics.begin() + m_SelectedGraphicIndex);
    }

    void Manager::AddElement(Type type)
    {
        std::string name = type.ToString() + " " + std::to_string(m_SelectedGraphic->Elements());
        GraphicData& g_data = m_Registry.get<GraphicData>(m_SelectedGraphic->m_GraphicHandle);
        
        ElementData el_data {type, name, g_data.duration};

        Element el { el_data, m_Registry.create(), this};

        m_SelectedGraphic->m_Elements.push_back(el);
        m_SelectedElement = nullptr;
    }

    void Manager::DuplicateElement()
    {
        // todo
    }

    void Manager::MoveElementUp()
    {
        // todo
    }

    void Manager::MoveElementDown()
    {
        // todo
    }

    void Manager::MoveElementTop()
    {
        // todo
    }

    void Manager::MoveElementBottom()
    {
        // todo
    }

    size_t Manager::ElementCount()
    {
        return m_SelectedGraphic ? m_SelectedGraphic->m_Elements.size() : 0;
    }

    Element* Manager::GetElement()
    {
        return m_SelectedElement;
    }

    entt::registry& Manager::Reg()
    {
        return m_Registry;
    }
}