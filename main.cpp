#include <GLFW/glfw3.h>
#include <iostream>

// Callback function for error handling
void errorCallback(int error, const char* description) {
    std::cerr << "Error: " << description << std::endl;
}

class Renderer
{
    public:
    
    void Triangle
    {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
    }
};
Renderer renderer;
int main() {
    // Set the error callback
    glfwSetErrorCallback(errorCallback);

    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
    renderer.Triangle();
    // Specify OpenGL version and profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Major version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // Minor version
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Use core profile

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "Cassie Engine", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Set viewport size
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Render here
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Set clear color
        glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

        // Swap front and back buffers
        glfwSwapBuffers(window);
        // Poll for and process events
        glfwPollEvents();
    }

    // Clean up
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
