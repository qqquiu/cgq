/*
 *  @file   MathLib.h
 *
 *  @brief  Simple vector and matrix classes to help implementation
 */

#pragma once

namespace CGQ::Math
{
    struct vec2
    {
    public:
        float x = 0.f;
        float y = 0.f;
    };

    struct vec3
    {
    public:
        float x = 0.f;
        float y = 0.f;
        float z = 0.f;
    };

    struct vec4
    {
    public:
        float x = 0.f;
        float y = 0.f;
        float z = 0.f;
        float w = 0.f;
    };

    struct mat4
    {
        vec4 Position   = { 0.f, 0.f, 0.f, 0.f };
        vec4 Rotation   = { 0.f, 0.f, 0.f, 0.f };
        vec4 Scale      = { 1.f, 1.f, 1.f, 1.f };
        vec4 Anchor     = { 0.f, 0.f, 0.f, 0.f };
    };

}