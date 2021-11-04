#pragma once

#include <string>
#include <glfw/glfw3.h>

namespace HelloVulkan
{
	class Window
	{
	public:
		Window(int width, int height, std::string title);
		~Window();

		bool ShouldClose();
	private: 
		const int m_Width;
		const int m_Height;

		std::string m_WindowTitle;
		GLFWwindow* m_Window;
	};
}