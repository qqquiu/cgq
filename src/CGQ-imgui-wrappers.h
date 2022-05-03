#pragma once

#include "imgui.h"
#include "imgui_internal.h"
#include "Core/MathLib.h"

// Thanks to volcoma for this helpful DragFloat wrapper which I've used as a base
// https://github.com/ocornut/imgui/issues/1831#issuecomment-391324007

namespace CGQ::IMGUI
{
    void PushMultiItemsWidthsAndLabels(Math::vec3 vector, float w_full);
    bool DragVector(std::string label, Math::vec3* vector, float v_speed, float v_min, float v_max, const char* display_format, float power);
}
