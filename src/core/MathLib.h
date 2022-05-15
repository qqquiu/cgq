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
        float X = 0.f;
        float Y = 0.f;
    };

    struct vec3
    {
    public:
        float X = 0.f;
        float Y = 0.f;
        float Z = 0.f;
    };

    struct vec4
    {
    public:
        float X = 0.f;
        float Y = 0.f;
        float Z = 0.f;
        float W = 0.f;
    };

    struct mat4
    {
        vec4 Position   = { 0.f, 0.f, 0.f, 0.f };
        vec4 Rotation   = { 0.f, 0.f, 0.f, 0.f };
        vec4 Scale      = { 1.f, 1.f, 1.f, 1.f };
        vec4 Anchor     = { 0.f, 0.f, 0.f, 0.f };
    };

    struct mat2
    {
        vec2 Position   = { 0.f, 0.f };
        vec2 Rotation   = { 0.f, 0.f };
        vec2 Scale      = { 0.f, 0.f };
        vec2 Anchor     = { 0.f, 0.f };
    };

}