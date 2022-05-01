#include "pch.h"
#include "core.h"
#include "ui.h"
#include "scene/manager.h"
#include "scene/scene.h"
#include <vulkan/vulkan.h>

namespace CGQ
{
	CGManager manager;

	void SetUITheme()
	{
		UI::SetTheme();
	}

	void Run(uint32_t frame, VkPhysicalDevice gpu)
	{
		UI::Render(frame, gpu, &manager);
	}

	void PrintMessage(std::string msg)
	{
		std::cout << msg << std::endl;
	}
}
