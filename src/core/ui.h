#pragma once
#include "imgui.h"
#include "imgui_internal.h"
#include "imgui_impl_vulkan.h"

#include <vulkan/vulkan.h>

#include "Scene/Manager.h"
#include "Wrappers/CGQ-imgui.h"

namespace CGQ::UI
{
	void SetTheme();
	void Render(uint32_t frame, VkPhysicalDevice gpu, Manager& manager);
	void InitDockspace();
	void DebugWindows();
	void EditorWindow(uint32_t frame);
	void PreviewWindow();
	void GraphicsWindow(Manager& manager);
	void ElementsWindow(Manager& manager);
	void PropertiesWindow(Manager& manager);
	void TimelineWindow();
	void InformationWindow(VkPhysicalDevice gpu);
}