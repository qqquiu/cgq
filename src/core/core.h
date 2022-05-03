#pragma once
#include <vulkan/vulkan.h>
#include "entt.hpp"
#include "imgui.h"

namespace CGQ
{
	void SetUITheme();
	void Run(uint32_t frame, VkPhysicalDevice gpu);
	void PrintMessage(std::string msg);
}