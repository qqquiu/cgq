#pragma once
#include "scene/manager.h"
#include <vulkan/vulkan.h>

namespace UI
{
	void SetTheme();
	void Render(uint32_t frame, VkPhysicalDevice gpu, CGManager* manager);
	void InitDockspace();
	void DebugWindows();
	void EditorWindow(uint32_t frame);
	void PreviewWindow();
	void GraphicsWindow(CGManager* manager);
	void ElementsWindow(CGManager* manager);
	void PropertiesWindow(CGManager* manager);
	void TimelineWindow();
	void InformationWindow(VkPhysicalDevice gpu);
}