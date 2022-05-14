/*
 *  @file   Manager.h
 *
 *  @brief  todo
 * 
 */

#pragma once

#include "Graphic.h"

namespace CGQ
{
    class Manager
    {
    public:        
        // Graphics management
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