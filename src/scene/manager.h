/*
 *  @file   Manager.h
 *
 *  @brief  Singleton to creates and manage instances of graphics and elements.
 *          Any data access should go through this class.
 */

#pragma once

#include "Library.h"

namespace CGQ
{
    class Manager
    {
    public:
        // Graphics
        void        AddGraphic();
        void        RemoveGraphic();
        void        DuplicateGraphic();
        void        RenameGraphic(std::string);
        size_t      GraphicCount();
        Graphic*    GetGraphic();
        Graphic*    GetGraphic(size_t);
        size_t      GraphicIndex();
        void        SelectGraphic(size_t);
        void        DeselectGraphic();

        // Elements
        void        AddElement(EElementType);
        void        RemoveElement();
        void        DuplicateElement();
        void        RenameElement(std::string);
        size_t      ElementCount();
        Element*    GetElement();
        Element*    GetElement(size_t);
        size_t      ElementIndex();
        void        SelectElement(size_t);
        void        DeselectElement();

    private:
        Library  m_Library = { this };
        Graphic* m_Graphic = nullptr;
        Element* m_Element = nullptr;
    };
}