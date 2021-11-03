cmake_minimum_required(VERSION 3.10)

project(VulkanPlayground)

add_executable(VulkanPlayground src/main.cpp)

# GLFW: https://www.glfw.org/docs/3.3/build_guide.html
# Disable build of glfw docs, tests and examples. 
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# Add the root directory of the GLFW source tree to the project.
add_subdirectory(vendor/glfw)

# Link the application against the glfw target.
target_link_libraries(VulkanPlayground glfw)

# GLM
include_directories("${CMAKE_SOURCE_DIR}/vendor/glm")

# Vulkan - NOT WORKING
find_package(Vulkan REQUIRED FATAL_ERROR)
target_include_directories(VulkanPlayground PUBLIC ${VULKAN_INCLUDE_DIRS})
target_link_libraries(VulkanPlayground ${VULKAN_LIB_LIST})