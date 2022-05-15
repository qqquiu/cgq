/*
 *  @file   Components.h
 *
 *  @brief  todo
 * 
 */

#pragma once

#include "Core/MathLib.h"

namespace CGQ
{
    struct GraphicData
    {
        std::string name;
        uint64_t duration;
        
        GraphicData(std::string n, uint64_t d)
            : name(n), duration(d) {}

        GraphicData(const GraphicData&) = default;
    };

    struct ElementData
    {
        Type type;
        std::string name;
        uint64_t duration;
        bool isVisible;
        bool isLocked;

        ElementData(Type t, std::string n, uint64_t d)
            : type(t), name(n), duration(d), isVisible(true), isLocked(false) {}

        ElementData(const ElementData&) = default;
    };

    struct TagComponent
    {
        std::vector<std::string> Tags;
    };

    struct TransformComponent
    {
        Math::mat2 Transform;

        TransformComponent() = default;
        TransformComponent(const TransformComponent&) = default;
        TransformComponent(const Math::mat2 & transform)
            : Transform(transform) {}

        operator Math::mat2& () { return Transform; }
        operator const Math::mat2& () const { return Transform; }
    };

    /*
    struct TextComponent
    {
        // todo: text content and info such as font and size. color should be done in color component
    };
    */

    struct ColorComponent
    {
        Math::vec4 Color { 1.0f, 1.0f, 1.0f, 1.0f };

        ColorComponent() = default;
        ColorComponent(const ColorComponent&) = default;
        ColorComponent(Math::vec4 color)
            : Color(color) {}
    };

    /*
    struct ImgComponent
    {
        // todo: image file ptr
    };

    struct ImgSequenceComponent
    {
        // todo: research how to do this 
    };

    struct AudioComponent
    {
        // todo: audio file ptr
    };
    */
}
