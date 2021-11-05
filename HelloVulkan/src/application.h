#pragma once

#include <vector>
#include <string>

#include "window.h"
#include "vulkan/vulkan.h"

namespace HelloVulkan
{
	class Application
	{
	public:
		Application();
		~Application();
		void Run();

	private:
		std::vector<char> ReadFile(const std::string& filepath);

	private:
		VkInstance m_VulkanInstance;
		Window m_Window;
	};
}