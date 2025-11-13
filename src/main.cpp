#include <GLFW/glfw3.h>
#include <iostream>

// Setting Window Size
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    // 1. GLFW Initialization
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // 2. OpenGL Version Setting (3.3 Core Profile) - Standard setting for Mac/Windows compatibility
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Setting for Mac users
#endif

    // 3. Window Creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "My OpenGL Renderer", NULL, NULL);
    if (window == NULL) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        std::cerr << "NOTE: If you are on Codespaces/Cloud, this is EXPECTED because there is no monitor." << std::endl;
        glfwTerminate();
        return -1;
    }
    
    // Setting the current window as the rendering context
    glfwMakeContextCurrent(window);

    // 4. Render Loop - Keep running until the window is instructed to close
    while (!glfwWindowShouldClose(window)) {
        // (Drawing code will go here later)

        // Double buffering (screen swap)
        glfwSwapBuffers(window);
        // Keyboard/mouse event detection
        glfwPollEvents();
    }

    // 5. Termination and resource release
    glfwTerminate();
    return 0;
}