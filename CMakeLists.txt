cmake_minimum_required(VERSION 3.10)

# HelloVulkan
project(HelloVulkan)
file(GLOB HelloVulkanSource CONFIGURE_DEPENDS "HelloVulkan/src/*.h" "HelloVulkan/src/*.cpp")
set (CMAKE_CXX_STANDARD 17)
add_executable(HelloVulkan ${HelloVulkanSource})

# GLFW: https://www.glfw.org/docs/3.3/build_guide.html
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(HelloVulkan/vendor/glfw)      
target_link_libraries(HelloVulkan glfw)

# GLM
add_subdirectory(HelloVulkan/vendor/glm)            
include_directories("${CMAKE_SOURCE_DIR}/HelloVulkan/vendor/glm")                       

# STB IMAGE
include_directories("${CMAKE_SOURCE_DIR}/HelloVulkan/vendor/stb_image")  

# TINY OBJ LOADER
include_directories("${CMAKE_SOURCE_DIR}/HelloVulkan/vendor/tinyobjloader")  

# Vulkan
set(VULKAN_PATH "C:/VulkanSDK/1.2.170.0")                                             
message(STATUS "Using manual specified path: ${VULKAN_PATH}")
include_directories(AFTER ${VULKAN_PATH}/Include)
target_link_libraries(HelloVulkan ${VULKAN_PATH}/Lib/vulkan-1.lib)