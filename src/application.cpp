#include "application.h"

namespace HelloVulkan
{
	Application::Application()
		: m_Window(1280, 720, "HelloVulkan")
	{

	}

	void Application::Run()
	{
		while (!m_Window.ShouldClose())
		{
			glfwPollEvents();
		}
	}
}