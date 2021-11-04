#pragma once

#include "window.h"

namespace HelloVulkan
{
	class Application
	{
	public:
		Application();

		void Run();

	private:
		Window m_Window;
	};
}