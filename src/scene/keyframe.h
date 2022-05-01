/*
 *  @file   keyframe.h
 *
 *  @brief  Keyframe template class for elements' animations.
 */

#pragma once

#include <variant>


template <class T>
class CGKeyframe
{
public:
    CGKeyframe(T item, int frame) : item(item), frame(frame) {}
private:
    T item;
    int frame;
    // todo: ease function enum?
};
