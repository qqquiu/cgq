/*
 *  @file   framerate.h
 *
 *  @brief  Simple framerate data class to help implementation of framerates
 *          due to numerator/denominator requirements.
 * 
 *          Small cheat sheet example:
 *              29.97fps    m_num = 30000    m_den = 1001;
 *              30fps       m_num = 30000    m_den = 1000;
 *              59.94fps    m_num = 60000    m_den = 1001;
 *              60fps       m_num = 60000    m_den = 1000;
 */

#pragma once

namespace CGQ
{
    class Framerate
    {
    public:
        float fps();

        Framerate(int, int);
        Framerate(int);
    private:
        int m_num;
        int m_den;
    };
}