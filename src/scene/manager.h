/*
 *  @file   Manager.h
 *
 *  @brief  todo
 * 
 */

#pragma once

#include "Element.h"
#include "Graphic.h"

namespace CGQ
{
    class Manager
    {
    public:        
        // Graphic management
        void        AddGraphic();
        void        DuplicateGraphic();
        void        ImportGraphic();
        void        ExportGraphic();
        void        MoveGraphicUp();
        void        MoveGraphicDown();
        void        MoveGraphicTop();
        void        MoveGraphicBottom();
        size_t      GraphicCount();
        int         GraphicIndex();
        Graphic*    GetGraphic();
        Graphic*    GetGraphic(int i);
        void        SelectGraphic(int i);
        void        RenameGraphic(std::string newname);
        void        RemoveGraphic();

        // Element management
        void        AddElement(Type);
        void        DuplicateElement();
        void        MoveElementUp();
        void        MoveElementDown();
        void        MoveElementTop();
        void        MoveElementBottom();
        size_t      ElementCount();
        Element*    GetElement();
        Element*    GetElement(int i);
        void        SelectElement(int i);

        // Component templates
        template<typename T>
        T& GetComponent(Element& el)
        {
            return m_Registry.get<T>(el.m_ElementHandle);
        }

        template<typename T>
        T& GetComponent(Graphic& g)
        {
            return m_Registry.get<T>(g.m_GraphicHandle);
        }

        /*
        template<typename T>
        bool HasComponent(Element& el)
        {
            return m_Registry.has<T>(el.m_ElementHandle);
        }
        */

    private:
        friend class Element;
        friend class Graphic;

        std::vector<Graphic> m_Graphics;
        Graphic* m_SelectedGraphic = nullptr;
        int m_SelectedGraphicIndex = -1;

        Element* m_SelectedElement = nullptr;

        entt::registry m_Registry;
        entt::registry& Reg();
    };
}