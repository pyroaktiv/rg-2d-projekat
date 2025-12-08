#include "../Header/callbacks.h"
#include "../Header/globals.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

	if (key == GLFW_KEY_K && action == GLFW_PRESS) {
		if (g_fsm_current_bus_stop != -1 && g_fsm_num_passengers < 50 && !g_fsm_is_control) {
			g_fsm_is_control = true;
			g_fsm_num_passengers++;
		}
	}
}

void passenger_mouse_callback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
		if (g_fsm_current_bus_stop != -1 && g_fsm_num_passengers < 50) {
			g_fsm_num_passengers++;
		}
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
		if (g_fsm_current_bus_stop != -1 && g_fsm_num_passengers > (g_fsm_is_control ? 1 : 0)) {
			g_fsm_num_passengers--;
		}
	}
}