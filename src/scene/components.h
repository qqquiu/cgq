#pragma once

#include "math/vectors.h"

namespace CGQ
{
    struct TransformComponent
    {
        vec3 Transform;
    };

    struct TextComponent
    {
        //
    };

    struct ColorComponent
    {
        vec4 Color { 1.0f, 1.0f, 1.0f, 1.0f };
    };

    struct ImageComponent
    {
        // todo: image file ptr
    };

    struct ImageSequenceComponent
    {

    };
}
