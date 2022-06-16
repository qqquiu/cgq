#include "pch.h"
#include "CGQ-imgui.h"
#include "Scene/Element.h"
#include "Scene/Graphic.h"
#include "Scene/Manager.h"

namespace CGQ
{
    void PushMultiItemsWidthsAndLabels(Math::vec3 vector, float w_full)
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
    bool DragVector3(std::string label, Math::vec3* vector, float v_speed, float v_min, float v_max, const char* display_format, float power)
    {
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        if (window->SkipItems)
            return false;

        ImGuiContext& g = *GImGui;
        bool value_changed = false;
        ImGui::BeginGroup();

        float* v[3] = {&vector->X, &vector->Y, &vector->Z};
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

    // List box wrapper with some style prefaces
    bool ListBox(const char* label, const ImVec2& size)
    {
        ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.f, 0.f, 0.f, 0.f));
        return ImGui::BeginListBox(label, size);
    }
    
    // Just so we don't get confused
    void EndListBox()
    {
        ImGui::PopStyleColor();
        ImGui::EndListBox();
    }

    // Just so we don't get confused
    void PopStyleColor()
    {
        ImGui::PopStyleColor();
    }

    void BeginAssetButtonGroup(float left_space)
    {
        ImGui::SameLine(0, left_space);
        ImGui::BeginGroup();
    }

    void EndAssetButtonGroup()
    {
        ImGui::EndGroup();
    }

    bool AssetButton(const char* label)
    {
        ImGui::SameLine();
        return ImGui::Button(label, ImVec2(20.f, 20.f));
    }

    bool ElementTreeNode(Element& el)
    {
        ImGuiTreeNodeFlags flags = 0;
        flags |= ImGuiTreeNodeFlags_SpanAvailWidth;
        flags |= ImGuiTreeNodeFlags_OpenOnArrow;
        flags |= ImGuiTreeNodeFlags_AllowItemOverlap;
        flags |= ImGuiTreeNodeFlags_Framed;
        return ImGui::TreeNodeEx(el.Unique().c_str(), flags);
    }

    void ElementTreePop(Manager& m, Element& el)
    {
        ElementData& data = m.GetComponent<ElementData>(el); 
        ImGui::TextDisabled("%s duration: %d", data.name.c_str(), data.duration);
        ImGui::TableNextColumn();
        ImGui::TextDisabled("%d", data.isVisible);
        ImGui::TableNextColumn();
        ImGui::TextDisabled("%d", data.isLocked);
        //TransformComponent& transform = m.GetComponent<TransformComponent>(el);
        ImGui::TreePop();
    }
}
