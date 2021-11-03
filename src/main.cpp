#include <iostream>

#define GLFW_INCLUDE_VULKAN
#include <glfw/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

int main(int argc, char* argv[])
{
	std::cout << "Vulkan" << std::endl;

	glm::vec3 vec = glm::vec3(1.0f, 2.0f, 3.0f);
	std::cout << glm::to_string(vec) << std::endl;

	return 0;
}