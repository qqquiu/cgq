#pragma once

#include "imgui.h"
#include "imgui_internal.h"
#include "Core/MathLib.h"
#include "Scene/Element.h"
#include "Scene/Graphic.h"
#include "Scene/Manager.h"

// Thanks to volcoma for this helpful DragFloat wrapper which I've used as a base
// https://github.com/ocornut/imgui/issues/1831#issuecomment-391324007

namespace CGQ
{
    void PushMultiItemsWidthsAndLabels(Math::vec3 vector, float w_full);
    
    // DragFloat wrapper for Vec3
    bool DragVector3(std::string label, Math::vec3* vector, float v_speed, float v_min, float v_max, const char* display_format, float power);
    
    // List box wrapper with some style prefaces
    bool ListBox(const char* label, const ImVec2& size);
    
    // Just so we don't get confused
    void EndListBox();

    // Just so we don't get confused
    void PopStyleColor();

    void BeginAssetButtonGroup(float left_space);

    void EndAssetButtonGroup();

    bool AssetButton(const char* label);

    bool ElementTreeNode(Element& el);

    void ElementTreePop(Manager& m, Element& el);
}
