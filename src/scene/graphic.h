/*
 *  @file   graphic.h
 *
 *  @brief  Collection of graphic elements or motion created in
 *          the editor and played back to outputs.
 */

#pragma once

#include "Element.h"

namespace CGQ
{
    class Graphic
    {
    public:
        Graphic();
        Graphic(const Graphic&) = default;

        ~Graphic();

        std::string Name();
        std::string Unique();
        const char* CStr();
        size_t ID();
        size_t Elements();
        size_t Index();
        // todo: thumbnail ?

    private:
        friend class Manager;

        entt::registry m_Registry;

        size_t c_ID;
        size_t m_Index = static_cast<size_t>(-1);

        std::string m_Name;
        std::vector<Element> m_Elements;
        int m_Duration = 60;

        Element* Get();
        Element* Get(size_t);
        void Pop();
        void Add(EElementType type);
    };
}