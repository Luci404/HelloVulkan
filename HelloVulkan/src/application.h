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
		bool CheckValidationLayerSupport();
		
		std::vector<char> ReadFile(const std::string& filepath);

	private:
		const std::vector<const char*> validationLayers = {
			"VK_LAYER_KHRONOS_validation"
		};


		#ifdef NDEBUG
		const bool enableValidationLayers = false;
		#else
		const bool enableValidationLayers = true;
		#endif

		Window m_Window;
		VkInstance m_VulkanInstance;
	};
}