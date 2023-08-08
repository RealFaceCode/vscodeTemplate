#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <freetype/freetype.h>
 
int main(int, char**)
{
    if(!glfwInit())
        throw std::runtime_error("Failed to init glfw");

    GLFWwindow* win = glfwCreateWindow(400, 400, "test", nullptr, nullptr);
    if(!win)
        throw std::runtime_error("Failed to create window");

    glfwMakeContextCurrent(win);
    auto r = glewInit();
    if(r != GLEW_OK)
        throw std::runtime_error("Failed to init glew");


    glm::vec2 v(12, 23);
    FT_Bool b;
    
    return 0;
}