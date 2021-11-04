#include "application.h"

#include <fstream>
#include <iostream>

namespace HelloVulkan
{
	Application::Application()
		: m_Window(1280, 720, "HelloVulkan")
	{
		const std::vector<char> fragSource = ReadFile("C:/Dev/HelloVulkan/HelloVulkan/assets/shaders/shader.frag.spv");
		const std::vector<char> vertSource = ReadFile("C:/Dev/HelloVulkan/HelloVulkan/assets/shaders/shader.vert.spv");
		
		std::cout << "Fragment shader source size: " << fragSource.size() << std::endl;
		std::cout << "Vertex shader source size: " << vertSource.size() << std::endl;
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