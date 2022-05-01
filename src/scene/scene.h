/*
 *  @file   scene.h
 *
 *  @brief  Definitions and functions for the viewport editor and playback output(s)
 *          such as width, height, fps. External output instance classes should
 *          also include this class.
 */

#pragma once

namespace cgq
{
    class Scene
    {
    public:
        int height = 1920;
        int width = 1080;
        int fps_num = 60;
        int fps_den = 1;
    };
}