#include "pch.h"
#include "ui.h"

namespace CGQ::UI
{
    const char* window_editor = "Viewport###Viewport";
    const char* window_preview = "Preview###Preview";
    const char* window_assets = "Assets###Assets";
    const char* window_gfx_lib = "Graphics###Graphics";
    const char* window_gfx_el = "Elements###GraphicElements";
    const char* window_item_prop = "Properties###Properties";
    const char* window_timeline = "Timeline###Timeline";
    const char* window_stats = "Stats###Stats";

    void SetTheme()
    {
        ImGuiStyle* style = &ImGui::GetStyle();
        ImVec4* colors = ImGui::GetStyle().Colors;

        colors[ImGuiCol_WindowBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
        colors[ImGuiCol_PopupBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
        colors[ImGuiCol_Border] = ImVec4(0.07f, 0.07f, 0.07f, 0.00f);
        colors[ImGuiCol_BorderShadow] = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
        colors[ImGuiCol_FrameBg] = ImVec4(0.24f, 0.24f, 0.24f, 0.71f);
        colors[ImGuiCol_TitleBg] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
        colors[ImGuiCol_TitleBgActive] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
        colors[ImGuiCol_MenuBarBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.12f);
        colors[ImGuiCol_ScrollbarBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.53f);
        colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
        colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.75f, 0.75f, 0.75f, 1.00f);
        colors[ImGuiCol_Button] = ImVec4(0.24f, 0.24f, 0.24f, 1.00f);
        colors[ImGuiCol_ButtonHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.44f);
        colors[ImGuiCol_Header] = ImVec4(1.00f, 1.00f, 1.00f, 0.16f);
        colors[ImGuiCol_HeaderHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.16f);
        colors[ImGuiCol_HeaderActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
        colors[ImGuiCol_Separator] = ImVec4(1.00f, 1.00f, 1.00f, 0.03f);
        colors[ImGuiCol_SeparatorHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.12f);
        colors[ImGuiCol_SeparatorActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.35f);
        colors[ImGuiCol_Tab] = ImVec4(1.00f, 1.00f, 1.00f, 0.12f);
        colors[ImGuiCol_TabHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.31f);
        colors[ImGuiCol_TabActive] = ImVec4(0.21f, 0.40f, 0.61f, 1.00f);
        colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.10f, 0.15f, 0.00f);
        colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
        colors[ImGuiCol_DockingPreview] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
        colors[ImGuiCol_TextSelectedBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.32f);
        colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 1.00f, 0.71f);
        colors[ImGuiCol_Border] = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);

        style->WindowMenuButtonPosition = ImGuiDir_None;

        style->WindowPadding = { 4, 4 };
        style->FramePadding = { 2, 2 };
        style->ItemSpacing = { 4, 4 };
        style->ScrollbarSize = { 14 };
        style->GrabMinSize = { 12 };
        style->WindowBorderSize = { 1 };
        style->FrameBorderSize = { 0 };
        style->FrameRounding = { 0 };
        style->TabBorderSize = { 0 };
        style->WindowRounding = { 0 };
        style->GrabRounding = { 0 };
        style->TabRounding = { 0 };
        style->WindowTitleAlign = { 0.005f, 0.5f };
    }

    // Called every frame to render the windows
    void Render(uint32_t frame, VkPhysicalDevice gpu, Manager* manager)
    {
        InitDockspace();
        DebugWindows();
        EditorWindow(frame);
        PreviewWindow();
        GraphicsWindow(manager);
        ElementsWindow(manager);
        PropertiesWindow(manager);
        //TimelineWindow();
        //InformationWindow(gpu);
    }

    // Initialize the main dockspace with the proper flags
    void InitDockspace()
    {
        static bool opt_fullscreen = true;
        static bool opt_padding = false;
        static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;
        //static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_NoTabBar;

        // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
        // because it would be confusing to have two docking targets within each others.
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar;
        //ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
        if (opt_fullscreen)
        {
            const ImGuiViewport* viewport = ImGui::GetMainViewport();
            ImGui::SetNextWindowPos(viewport->WorkPos);
            ImGui::SetNextWindowSize(viewport->WorkSize);
            ImGui::SetNextWindowViewport(viewport->ID);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
            window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
            window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
        }
        else
        {
            dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
        }

        // When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
        // and handle the pass-thru hole, so we ask Begin() to not render a background.
        if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
            window_flags |= ImGuiWindowFlags_NoBackground;

        // Important: note that we proceed even if Begin() returns false (aka window is collapsed).
        // This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
        // all active windows docked into it will lose their parent and become undocked.
        // We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
        // any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
        if (!opt_padding)
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
        ImGui::Begin("CGQ Dockspace", nullptr, window_flags);
        if (!opt_padding)
            ImGui::PopStyleVar();

        if (opt_fullscreen)
            ImGui::PopStyleVar(2);

        // Submit the DockSpace
        ImGuiIO& io = ImGui::GetIO();
        if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
        {
            ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
            ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
        }

        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("New")) { /* new project code */ };
                if (ImGui::MenuItem("Open")) { /* open project code */ };
                ImGui::Separator();
                if (ImGui::MenuItem("Save")) { /* save current project */ };
                if (ImGui::MenuItem("Save as...")) { /* save as another file */ };
                ImGui::Separator();
                if (ImGui::MenuItem("Exit")) { /* quit program */ };
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Edit"))
            {
                if (ImGui::MenuItem("Undo")) { /* going to be hard */ };
                if (ImGui::MenuItem("Redo")) { /* going to be hard */ };
                ImGui::Separator();
                if (ImGui::MenuItem("Copy")) { /* going to be hard */ };
                if (ImGui::MenuItem("Paste")) { /* going to be hard */ };
                ImGui::Separator();
                if (ImGui::MenuItem("Project settings...")) { /* project settings - resolution, framerate, etc */ }
                if (ImGui::MenuItem("Output settings...")) { /* total outputs and select devices: sdi / ndi */ }
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Options"))
            {
                // Disabling fullscreen would allow the window to be moved to the front of other windows,
                // which we can't undo at the moment without finer window depth/z control.
                ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen);
                ImGui::MenuItem("Padding", NULL, &opt_padding);
                ImGui::Separator();

                if (ImGui::MenuItem("Flag: NoSplit", "", (dockspace_flags & ImGuiDockNodeFlags_NoSplit) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_NoSplit; }
                if (ImGui::MenuItem("Flag: NoResize", "", (dockspace_flags & ImGuiDockNodeFlags_NoResize) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_NoResize; }
                if (ImGui::MenuItem("Flag: NoDockingInCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_NoDockingInCentralNode) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_NoDockingInCentralNode; }
                if (ImGui::MenuItem("Flag: AutoHideTabBar", "", (dockspace_flags & ImGuiDockNodeFlags_AutoHideTabBar) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_AutoHideTabBar; }
                if (ImGui::MenuItem("Flag: PassthruCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode) != 0, opt_fullscreen)) { dockspace_flags ^= ImGuiDockNodeFlags_PassthruCentralNode; }
                ImGui::Separator();
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Window"))
            {
                if (ImGui::MenuItem("Reset layout")) { /* stuff here */ };
                if (ImGui::MenuItem("Enable window 1")) { /* stuff here */ };
                if (ImGui::MenuItem("Enable window 2")) { /* stuff here */ };
                if (ImGui::MenuItem("Enable window 3")) { /* stuff here */ };
                if (ImGui::MenuItem("Enable window 4")) { /* stuff here */ };
                ImGui::Separator();
                if (ImGui::MenuItem("Preview Output")) { /* stuff here */ };
                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("Help"))
            {
                if (ImGui::MenuItem("About")) { /* stuff here */ };
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }

        ImGui::End();
    }

    // TODO: remove when shipping
    // Some debug windows from ImGui
    void DebugWindows()
    {
        ImGui::ShowDemoWindow();
    }

    // Graphics Editor viewport
    void EditorWindow(uint32_t f)
    {
        ImGui::Begin(window_editor);
        {
            //ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
            //uint32_t textureID = f;
            //ImGui::Image(textureID, ImVec2{ 1280, 720 }, ImVec2{ 0, 1 }, ImVec2{ 1, 0 });
        }
        ImGui::End();
    }

    // Preview Output viewport
    void PreviewWindow()
    {
        ImGui::Begin(window_preview);
        ImGui::End();
    }

    // Current project's graphics library
    void GraphicsWindow(Manager* m)
    {
        size_t total_gfx = m->GraphicCount();

        if (ImGui::Begin(window_gfx_lib))
        {
            ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.f, 0.f, 0.f, 0.f));
            if (ImGui::BeginListBox("###LibraryList", ImVec2(-FLT_MIN, -FLT_MIN)))
            {
                if (ImGui::BeginPopupContextWindow("##Popup"))
                {
                    if (ImGui::MenuItem("New graphic###AddGraphicButton"))
                    {
                        m->AddGraphic();
                    }
                    ImGui::EndPopup();
                }
                for (int i = 0; i < total_gfx; i++)
                {
                    const bool selected = (m->GraphicIndex() == i);
                    Graphic* g = m->GetGraphic(i);
                    if (ImGui::Selectable(g->Unique().c_str(), selected))
                    {
                        m->SelectGraphic(i);
                    }

                    if (ImGui::BeginPopupContextItem())
                    {
                        m->SelectGraphic(i);
                        ImGui::MenuItem(g->Unique().c_str(), NULL, false, false);
                        ImGui::Separator();
                        if (ImGui::MenuItem("Rename###RenameGraphic", "F2"))
                        {
                            m->RenameGraphic("Renamed!");
                        }
                        if (ImGui::MenuItem("Duplicate###DuplicateGraphic", "Ctrl+D"))
                        {
                            m->DuplicateGraphic();
                        }
                        if (ImGui::MenuItem("Delete###DeleteGraphic", "Del"))
                        {
                            m->RemoveGraphic();
                            total_gfx = m->GraphicCount();
                        }
                        ImGui::EndPopup();
                    }
                }
                ImGui::EndListBox();
            }
            ImGui::PopStyleColor();
        }
        ImGui::End();
    }

    // Selected graphic's elements window & timeline
    void ElementsWindow(Manager* m)
    {
        std::string WindowTitle = m->GetGraphic() ? m->GetGraphic()->Name() + "###ElementsWindow" : "Elements###ElementsWindow";
        if (ImGui::Begin(WindowTitle.c_str()))
        {
            float p_w = ImGui::GetWindowWidth();
            float p_h = ImGui::GetWindowHeight();

            if (!m->GetGraphic())
            {
                ImGui::TextDisabled("Select a graphic to edit its properties and elements."); // todo: center to screen
            }
            else
            {
                ImGui::BeginChild("ElementsTopPane", { -FLT_MIN, 30 });
                {
                    ImGui::TextDisabled("Top");
                }
                ImGui::EndChild();
                ImGui::Separator();
                ImGui::BeginChild("ElementsLeftPane");
                {
                    if (ImGui::BeginTable("table3", 2))
                    {
                        for (int item = 0; item < 14; item++)
                        {
                            ImGui::TableNextColumn();
                            ImGui::Text("Item %d", item);
                        }
                        ImGui::EndTable();
                    }
                }
                ImGui::EndChild();
            }
        }
        ImGui::End();
    }

    // Property editor of the currently selected asset
    void PropertiesWindow(Manager* m)
    {
        ImGui::Begin(window_item_prop);

        if (!m->GetElement())   // No element selected
        {
            ImGui::TextDisabled("No element selected.");
            // show graphics stuff instead?
        }
        else
        {
            Element* el = m->GetElement();
            if (ImGui::CollapsingHeader("Information", ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_OpenOnArrow))
            {
                ImGui::TextDisabled("Name:\t");
                ImGui::SameLine();
                ImGui::TextDisabled(el->Name().c_str());
                ImGui::TextDisabled("ID:\t");
                ImGui::SameLine();
                ImGui::TextDisabled("%d", el->ID());
            }
            ImGui::Spacing();
            // test if element is of type visual or audio
            if (ImGui::CollapsingHeader("Transform", ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_OpenOnArrow))
            {
                ImGui::TextDisabled("\tPosition");
                ImGui::Button("+##PositionKeyframe");
                ImGui::SameLine();
                //CGQ_W::DragVector("Position###ItemPosition", el->pos(), 1.f, false, false, "%.1f", 1);
                ImGui::NewLine();
                ImGui::TextDisabled("\tRotation");
                ImGui::Button("+##RotationKeyframe");
                ImGui::SameLine();
                //CGQ_W::DragVector("Rotation###ItemRotation", el->rot(), 1.f, false, false, "%.1f", 1);
                ImGui::NewLine();
                ImGui::TextDisabled("\tScale");
                ImGui::Button("+##ScaleKeyframe");
                ImGui::SameLine();
                //CGQ_W::DragVector("Scale###ItemScale", el->scale(), 0.005f, 0.f, false, "%.2f", 1);
                ImGui::NewLine();
                ImGui::TextDisabled("\tAnchor");
                ImGui::Button("+##AnchorKeyframe");
                ImGui::SameLine();
                //CGQ_W::DragVector("Anchor###ItemAnchor", el->anchor(), 1.f, false, false, "%.1f", 1);
            }
        }
        ImGui::End();
    }

    // Timeline editor for the currently selected asset
    void TimelineWindow()
    {
        if (ImGui::Begin(window_timeline))
        {

        }
        ImGui::End();
    }

    // Performance/stats and potentially toggle framebuffer external output(s)
    void InformationWindow(VkPhysicalDevice gpu)
    {
        VkPhysicalDeviceProperties prop;
        vkGetPhysicalDeviceProperties(gpu, &prop);
        //bool flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration;
        ImGui::Begin(window_stats);
        ImGui::Text(prop.deviceName);
        ImGui::PushItemWidth(-FLT_MIN);
        char buf[128];
        sprintf_s(buf, "%d FPS\nFrametime: %.2fms", (int)ImGui::GetIO().Framerate, (ImGui::GetIO().DeltaTime) * 1000.f);
        ImGui::Text(buf);
        ImGui::End();
    }
}
