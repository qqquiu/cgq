#pragma once
#include "imgui.h"
#include "imgui_internal.h"
#include "imgui_impl_vulkan.h"

#include <vulkan/vulkan.h>

#include "Scene/Element.h"
#include "Scene/Graphic.h"
#include "Scene/Manager.h"
#include "Wrappers/CGQ-imgui.h"

namespace CGQ::UI
{
	void SetTheme();
	void Render(uint32_t frame, VkPhysicalDevice gpu, Manager& manager);

	static void Dockspace();
	static void DebugWindows();
	static void EditorWindow(uint32_t frame);
	static void PreviewWindow();
	static void GraphicsWindow(Manager& manager);
	static void ElementsWindow(Manager& manager);
	static void PropertiesWindow(Manager& manager);
	static void TimelineWindow();
	static void InformationWindow(VkPhysicalDevice gpu);

	static void ElementsWindow_LeftPane(Manager& manager);
	static void ElementsWindow_RightPane(Manager& manager);
}