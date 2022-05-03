/*
 *  @file   Components.h
 *
 *  @brief  todo
 */

#pragma once

#include "Core/MathLib.h"

namespace CGQ
{
    struct TransformComponent
    {
        Math::mat4 Transform;
    };

    struct TextComponent
    {
        // todo: text content and info such as font and size. color should be done in color component
    };

    struct ColorComponent
    {
        Math::vec4 Color { 1.0f, 1.0f, 1.0f, 1.0f };
        float Opacity = 1.f; // not necessary?
    };

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
}
