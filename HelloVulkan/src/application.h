#pragma once

#include <vector>
#include <string>

#include "window.h"

namespace HelloVulkan
{
	class Application
	{
	public:
		Application();

		void Run();

	private:
		std::vector<char> ReadFile(const std::string& filepath);

	private:
		Window m_Window;
	};
}