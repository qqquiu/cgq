/*
 *  @file   vectors.h
 *
 *  @brief  Simple vector classes to help implement math vectors
 */

#pragma once

struct mat4
{
    /*
    vec4 pos { 0.f, 0.f, 0.f, 0.f };
    vec4 rot { 0.f, 0.f, 0.f, 0.f };
    vec4 scl { 1.f, 1.f, 1.f, 1.f };
    vec4 anc { 0.f, 0.f, 0.f, 0.f };
    */
};


struct vec4
{
public:
    float f1 = 0.f;
    float f2 = 0.f;
    float f3 = 0.f;
    float f4 = 0.f;
};

struct vec3
{
public:
    float x = 0.f;
    float y = 0.f;
    float z = 0.f;
};

struct vec2
{
public:
    float x = 0.f;
    float y = 0.f;
};
