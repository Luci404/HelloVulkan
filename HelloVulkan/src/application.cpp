#include "application.h"

#include <fstream>
#include <iostream>

namespace HelloVulkan
{
	Application::Application()
		: m_Window(1280, 720, "HelloVulkan")
	{

		// Enumerate supported extensions.
		uint32_t extensionCount = 0;
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
		std::vector<VkExtensionProperties> supportedExtensions(extensionCount);
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, supportedExtensions.data());

		std::cout << "available extensions:\n";
		for (const auto& extension : supportedExtensions) {
			std::cout << '\t' << extension.extensionName << '\n';
		}

		// Enumerate available layers.
		uint32_t layerCount;
		vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
		std::vector<VkLayerProperties> availableLayers(layerCount);
		vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

		std::cout << "available layers:\n";
		for (const auto& layer : availableLayers) {
			std::cout << '\t' << layer.layerName << '\n';
		}

		// Create vulkan instance
		if (enableValidationLayers && !CheckValidationLayerSupport())
		{
			std::cout << "validation layers requested, but not available!" << std::endl;
			return;
		}

		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "Hello Triangle";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "No Engine";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;

		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions;
		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);
		if (enableValidationLayers) extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);

		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;
		createInfo.enabledExtensionCount = extensions.size();
		createInfo.ppEnabledExtensionNames = extensions.data();
		createInfo.enabledLayerCount = 0;

		if (enableValidationLayers) 
		{
			createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
			createInfo.ppEnabledLayerNames = validationLayers.data();
		}
		else
		{
			createInfo.enabledLayerCount = 0;
		}

		if (vkCreateInstance(&createInfo, nullptr, &m_VulkanInstance) != VK_SUCCESS)
		{
			std::cout << "Failed to create vulkan instance" << std::endl;
			return;
		}

		// Get shader source
		const std::vector<char> fragSource = ReadFile("C:/Dev/HelloVulkan/HelloVulkan/assets/shaders/shader.frag.spv");
		const std::vector<char> vertSource = ReadFile("C:/Dev/HelloVulkan/HelloVulkan/assets/shaders/shader.vert.spv");
		std::cout << "Fragment shader source size: " << fragSource.size() << std::endl;
		std::cout << "Vertex shader source size: " << vertSource.size() << std::endl;
	}
	
	Application::~Application()
	{
		vkDestroyInstance(m_VulkanInstance, nullptr);
	}

	void Application::Run()
	{
		while (!m_Window.ShouldClose())
		{
			glfwPollEvents();
		}
	}

	bool Application::CheckValidationLayerSupport() {
		uint32_t layerCount;
		vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

		std::vector<VkLayerProperties> availableLayers(layerCount);
		vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

		for (const char* layerName : validationLayers) {
			bool layerFound = false;

			for (const auto& layerProperties : availableLayers) {
				if (strcmp(layerName, layerProperties.layerName) == 0) {
					layerFound = true;
					break;
				}
			}

			if (!layerFound) {
				return false;
			}
		}

		return true;
	}


	std::vector<char> Application::ReadFile(const std::string& filepath)
	{
		std::ifstream file(filepath, std::ios::ate | std::ios::binary);

		if (!file.is_open())
		{
			std::cout << "Failed to open file: " << filepath << std::endl;
			return std::vector<char>(0);
		}

		size_t fileSize = static_cast<size_t>(file.tellg());
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();
		return buffer;
	}
}