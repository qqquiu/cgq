/*
 *  @file   Components.h
 *
 *  @brief  todo
 */

#pragma once

#include "Core/MathLib.h"

namespace CGQ
{
    struct UIComponent
    {
        std::string Name = "Unnamed";
        EElementType Type = EElementType::None;
    };

    struct TagComponent
    {
        std::vector<std::string> Tags;
    };

    struct TransformComponent
    {
        Math::mat4 Transform;

        TransformComponent() = default;
        TransformComponent(const TransformComponent&) = default;
        TransformComponent(const Math::mat4 & transform)
            : Transform(transform) {}

        operator Math::mat4& () { return Transform; }
        operator const Math::mat4& () const { return Transform; }
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
