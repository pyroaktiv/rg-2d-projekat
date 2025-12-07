#define _USE_MATH_DEFINES
#include "../Header/setup.h"
#include "../Header/Util.h"
#include "../Header/callbacks.h"
#include "../Header/globals.h"
#include "../Header/fsm.h"
#include <cmath>
#include <GLM/glm.hpp>

// Program setup
void setupGlfw() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void setupScreen() {
	g_monitor = glfwGetPrimaryMonitor();
	g_monitor_mode = glfwGetVideoMode(g_monitor);

	g_window = glfwCreateWindow(g_monitor_mode->width, g_monitor_mode->height, "Bus tracker", g_monitor, NULL);
}

void setupCallbacks() {
	glfwSetKeyCallback(g_window, exit_callback);
}

void preprocessTextures() {

}



// Vertex setup
void setupRoadVertices() {
	const float delta = 2 * M_PI / NUM_SEGMENTS_ROAD;

	for (int i = 0; i <= NUM_SEGMENTS_ROAD; i++) {
		g_vert_road.at(i) = parametricCurve(i * delta);
	}
}

void setupBusStopCenterVertices() {
	g_vert_bus_stop_centers.at(0) = parametricCurve(-6.28);
	g_vert_bus_stop_centers.at(1) = parametricCurve(-5.68);
	g_vert_bus_stop_centers.at(2) = parametricCurve(-5.38);
	g_vert_bus_stop_centers.at(3) = parametricCurve(-5.18);
	g_vert_bus_stop_centers.at(4) = parametricCurve(-4.18);
	g_vert_bus_stop_centers.at(5) = parametricCurve(-2.98);
	g_vert_bus_stop_centers.at(6) = parametricCurve(-1.88);
	g_vert_bus_stop_centers.at(7) = parametricCurve(-0.98);
	g_vert_bus_stop_centers.at(8) = parametricCurve(-0.58);
	g_vert_bus_stop_centers.at(9) = parametricCurve(-0.38);
}

void setupBusStopCircleVertices() {
	const float delta = 2 * M_PI / NUM_SEGMENTS_CIRCLE;

	g_vert_bus_stop_circle.at(0) = { 0.0f, 0.0f };

	for (int i = 1; i <= NUM_SEGMENTS_CIRCLE + 1; i++) {
		g_vert_bus_stop_circle.at(i) = { cos(i * delta), sin(i * delta) };
	}
}


void setupControlBoardRectangleVertices() {
	g_vert_control_board_rectangle = {
		{-WIDTH_CONTROL_BOARD_RECTANGLE / 2, -HEIGHT_CONTROL_BOARD_RECTANGLE / 2},
		{WIDTH_CONTROL_BOARD_RECTANGLE / 2, -HEIGHT_CONTROL_BOARD_RECTANGLE / 2},
		{WIDTH_CONTROL_BOARD_RECTANGLE / 2, HEIGHT_CONTROL_BOARD_RECTANGLE / 2},
		{-WIDTH_CONTROL_BOARD_RECTANGLE / 2, HEIGHT_CONTROL_BOARD_RECTANGLE / 2}
	};
}

// Road length setup
void setupRoadSegmentLengths() {
	g_len_road_segments.at(0) = 0.0f;

	for (int i = 1; i < g_vert_road.size(); i++) {
		float segLen = glm::distance(g_vert_road.at(i), g_vert_road.at(i - 1));
		g_len_road_segments.at(i) = g_len_road_segments.at(i - 1) + segLen;
	}

	g_len_road_segments_total = g_len_road_segments.back();
}


// VAO setup
void setupRoadVAO() {
	unsigned VBO;

	glGenVertexArrays(1, &g_VAO_road);
	glBindVertexArray(g_VAO_road);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, g_vert_road.size() * sizeof(glm::vec2), g_vert_road.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void setupBusStopVAO() {
	unsigned VBOcircle;
	unsigned VBOcenters;

	glGenVertexArrays(1, &g_VAO_bus_stops);
	glBindVertexArray(g_VAO_bus_stops);

	glGenBuffers(1, &VBOcircle);
	glBindBuffer(GL_ARRAY_BUFFER, VBOcircle);
	glBufferData(GL_ARRAY_BUFFER, g_vert_bus_stop_circle.size() * sizeof(glm::vec2), g_vert_bus_stop_circle.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &VBOcenters);
	glBindBuffer(GL_ARRAY_BUFFER, VBOcenters);
	glBufferData(GL_ARRAY_BUFFER, g_vert_bus_stop_centers.size() * sizeof(glm::vec2), g_vert_bus_stop_centers.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribDivisor(1, 1);
}

void setupControlBoardRectangleVAO() {
	unsigned VBOrect;

	glGenVertexArrays(1, &g_VAO_control_board_rect);
	glBindVertexArray(g_VAO_control_board_rect);

	glGenBuffers(1, &VBOrect);
	glBindBuffer(GL_ARRAY_BUFFER, VBOrect);
	glBufferData(GL_ARRAY_BUFFER, g_vert_control_board_rectangle.size() * sizeof(glm::vec2), g_vert_control_board_rectangle.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

// Shader setup
void setupShaders() {
	g_shader_road = createShader("Shaders/road.vert", "Shaders/road.frag");
	g_shader_circle = createShader("Shaders/circle.vert", "Shaders/circle.frag");
	g_shader_rect = createShader("Shaders/rect.vert", "Shaders/rect.frag");
}