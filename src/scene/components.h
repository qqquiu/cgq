#pragma once

#include "Math/Vectors.h"

namespace CGQ
{
    struct TransformComponent
    {
        vec3 Transform;
    };

    struct TextComponent
    {
        // todo: text content and info such as font and size. color should be done in color component
    };

    struct ColorComponent
    {
        vec4 Color { 1.0f, 1.0f, 1.0f, 1.0f };
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
