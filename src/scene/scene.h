/*
 *  @file   Scene.h
 *
 *  @brief  Definitions and functions for the viewport editor and playback output(s)
 *          such as width, height, fps.
 */

#pragma once

namespace CGQ
{
    class Scene
    {
    public:
        int height = 1920;
        int width = 1080;
        int fps_num = 60;
        int fps_den = 1;
    private:
    };
}