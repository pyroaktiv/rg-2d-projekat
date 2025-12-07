#include "../Header/callbacks.h"
#include "../Header/globals.h"

void exit_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(g_window, GLFW_TRUE);
	}
}