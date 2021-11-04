cmake_minimum_required(VERSION 3.10)
project(VulkanPlayground)
add_executable(VulkanPlayground src/main.cpp)

# GLFW: https://www.glfw.org/docs/3.3/build_guide.html
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)                                # Disable build of glfw docs.
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)                               # Disable build of glfw tests.
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)                            # Disable build of glfw examples.
add_subdirectory(vendor/glfw)                                               # Add the root directory of the GLFW source tree to the project.
target_link_libraries(VulkanPlayground "glfw")                              # Link the application against the glfw target.

# GLM
include_directories("${CMAKE_SOURCE_DIR}/vendor/glm")                       # Add glm to the include directories list.

# Vulkan - NOT WORKING
set(VULKAN_PATH "C:/VulkanSDK/1.2.170.0")                                             
message(STATUS "Using manual specified path: ${VULKAN_PATH}")
include_directories(AFTER ${VULKAN_PATH}/Include)
target_link_libraries(VulkanPlayground ${VULKAN_PATH}/Lib/vulkan-1.lib)