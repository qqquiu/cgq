#include "pch.h"
#include "imgui.h"
#include "imgui_internal.h"
#include "math/vectors.h"
#include "cgq-wrappers.h"

namespace CGQ
{
    static void PushMultiItemsWidthsAndLabels(vec3 vector, float w_full)
    {
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        const ImGuiStyle& style = GImGui->Style;
        if (w_full <= 0.0f)
            w_full = ImGui::GetWindowContentRegionWidth() - 30;

        const float w_item_one = ImMax(1.0f, (w_full - (style.ItemInnerSpacing.x * 2.0f) * (3 - 1)) / (float)3) - style.ItemInnerSpacing.x;
        window->DC.ItemWidthStack.push_back(w_item_one - ImGui::CalcTextSize("X").x);
        window->DC.ItemWidthStack.push_back(w_item_one - ImGui::CalcTextSize("Y").x);
        window->DC.ItemWidthStack.push_back(w_item_one - ImGui::CalcTextSize("Z").x);
        window->DC.ItemWidth = window->DC.ItemWidthStack.back();
    }

    // DragFloat wrapper itself
    bool DragVector(std::string label, vec3* vector, float v_speed, float v_min, float v_max, const char* display_format, float power)
    {
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        if (window->SkipItems)
            return false;

        ImGuiContext& g = *GImGui;
        bool value_changed = false;
        ImGui::BeginGroup();

        float* v[3] = {&vector->x, &vector->y, &vector->z};
        PushMultiItemsWidthsAndLabels(*vector, 0.0f);

        char c = 'X'; // wtf am i doing
        for (int i = 0; i < 3; i++)
        {
            c += i;
            char s[2] = {c, '\0'};
            ImGui::PushID(label.c_str());
            ImGui::PushID(i);
            value_changed |= ImGui::DragFloat("", v[i], v_speed, v_min, v_max, display_format, power);
            ImGui::SameLine(0, g.Style.ItemInnerSpacing.x);
            ImGui::TextUnformatted((const char*)s, ImGui::FindRenderedTextEnd(&c));
            ImGui::SameLine();
            ImGui::PopID();
            ImGui::PopID();
            ImGui::PopItemWidth();
        }

        ImGui::EndGroup();

        return value_changed;
    }
}
