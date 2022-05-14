#include "pch.h"
#include "Core.h"
#include "UI.h"
#include "Scene/Manager.h"
#include "Scene/Scene.h"
#include <vulkan/vulkan.h>

namespace CGQ
{
	Manager manager;
	
	void SetUITheme()
	{
		CGQ::UI::SetTheme();
	}

	void Run(uint32_t frame, VkPhysicalDevice gpu)
	{
		CGQ::UI::Render(frame, gpu, manager);
	}

	void PrintMessage(std::string msg)
	{
		std::cout << msg << std::endl;
	}
}
