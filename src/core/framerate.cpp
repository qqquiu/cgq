#include "pch.h"
#include "framerate.h"

namespace CGQ
{
    // Pass single int such as 60 and constructor will convert to 60000
    Framerate::Framerate(int fps)
        :m_num(fps * 1000), m_den(1000)
    {

    }

    // Pass two ints such as 60 and 1 and constructor will convert to 60000 and 1000 respectively
    Framerate::Framerate(int num, int den)
        : m_num(num * 1000), m_den(den)
    {

    }

    float Framerate::fps()
    {
        return static_cast<float>(m_num / m_den);
    }
}