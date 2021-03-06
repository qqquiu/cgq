/*
 *  @file   Graphic.h
 *
 *  @brief  todo
 * 
 */

#pragma once

#include "Element.h"

namespace CGQ
{
    class Graphic
    {
    public:
        Graphic() = delete;
        Graphic(GraphicData& data, entt::entity handle, Manager* manager);
        Graphic(const Graphic&) = default;
        ~Graphic() = default;

        std::string Name();
        uint32_t ID();
        std::string Unique();
        const char* c_str();
        uint64_t Duration();
        size_t Elements();
        // todo: thumbnail ?

        operator bool() const;


        // these iterators might not be working gotta test
        std::vector<Element>::iterator begin()
        {
            return m_Elements.begin();
        }

        std::vector<Element>::iterator end()
        {
            return m_Elements.end();
        }

    private:
        friend class Manager;
        Manager* m_Manager = nullptr;
        entt::entity m_GraphicHandle = { entt::null };

        std::vector<Element> m_Elements;
        int m_ElementIndex = { -1 };

        GraphicData& GetData();
    };
}