#include <iostream>

#include <vulkan/vulkan.h>
#include <glfw/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

int main(int argc, char* argv[])
{
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	GLFWwindow* window = glfwCreateWindow(1280, 720, "HelloVUlkan", nullptr, nullptr);

	uint32_t extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

	std::cout << extensionCount << std::endl;

	return 0;
}