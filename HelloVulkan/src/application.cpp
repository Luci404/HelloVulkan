#include "application.h"

#include <fstream>
#include <iostream>

namespace HelloVulkan
{
	Application::Application()
		: m_Window(1280, 720, "HelloVulkan")
	{
		// Create vulkan instance
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

		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;
		createInfo.enabledExtensionCount = glfwExtensionCount;
		createInfo.ppEnabledExtensionNames = glfwExtensions;
		createInfo.enabledLayerCount = 0;

		if (vkCreateInstance(&createInfo, nullptr, &m_VulkanInstance) != VK_SUCCESS)
		{
			std::cout << "Failed to create vulkan instance" << std::endl;
			return;
		}

		// Enumerate supported extensions.
		uint32_t extensionCount = 0;
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
		std::vector<VkExtensionProperties> extensions(extensionCount);
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

		std::cout << "available extensions:\n";
		for (const auto& extension : extensions) {
			std::cout << '\t' << extension.extensionName << '\n';
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