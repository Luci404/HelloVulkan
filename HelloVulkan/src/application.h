#pragma once

#include <vector>
#include <string>
#include <optional>

#include "window.h"
#include "vulkan/vulkan.h"

namespace HelloVulkan
{
	struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;
	
		bool isComplete() {
			return graphicsFamily.has_value();
		}
	};


	class Application
	{
	public:
		Application();
		~Application();
		void Run();

	private:
		bool CheckValidationLayerSupport();
		
		QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);

		bool IsDeviceSuitable(VkPhysicalDevice device);

		void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
		VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
		void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
		static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);
		
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
		VkDebugUtilsMessengerEXT m_DebugMessenger;
	};
}