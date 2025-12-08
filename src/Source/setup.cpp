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
	glfwSetKeyCallback(g_window, key_callback);
	glfwSetMouseButtonCallback(g_window, passenger_mouse_callback);
}

void preprocessTextures() {
	preprocessTexture(g_number_tex[0], "Resources/Images/0.png");
	preprocessTexture(g_number_tex[1], "Resources/Images/1.png");
	preprocessTexture(g_number_tex[2], "Resources/Images/2.png");
	preprocessTexture(g_number_tex[3], "Resources/Images/3.png");
	preprocessTexture(g_number_tex[4], "Resources/Images/4.png");
	preprocessTexture(g_number_tex[5], "Resources/Images/5.png");
	preprocessTexture(g_number_tex[6], "Resources/Images/6.png");
	preprocessTexture(g_number_tex[7], "Resources/Images/7.png");
	preprocessTexture(g_number_tex[8], "Resources/Images/8.png");
	preprocessTexture(g_number_tex[9], "Resources/Images/9.png");
	preprocessTexture(g_tex_bus, "Resources/Images/bus.png");
	preprocessTexture(g_tex_dogtags, "Resources/Images/dogtags.png");
	preprocessTexture(g_tex_doors_closed, "Resources/Images/doors-closed.png");
	preprocessTexture(g_tex_doors_open, "Resources/Images/doors-open.png");
	preprocessTexture(g_tex_man, "Resources/Images/man.png");
	preprocessTexture(g_tex_officer, "Resources/Images/officer.png");
	preprocessTexture(g_tex_x, "Resources/Images/x.png");
	preprocessTexture(g_tex_hud, "Resources/Images/HUD.png");
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
		{-0.6f, -0.2f, 0.0f, 0.0f},
		{0.6f, -0.2f, 1.0f, 0.0f},
		{0.6f, 0.2f, 1.0f, 1.0f},
		{-0.6f, 0.2f, 0.0f, 1.0f}
	};
}


void setupTextureVertices() {
	g_vert_textures = {
		// 1. Grupa - brojevi stanice
		{-RADIUS_STATION_CIRCLE, -RADIUS_STATION_CIRCLE, 0.0f, 0.0f},
		{RADIUS_STATION_CIRCLE, -RADIUS_STATION_CIRCLE, 1.0f, 0.0f},
		{RADIUS_STATION_CIRCLE, RADIUS_STATION_CIRCLE, 1.0f, 1.0f},
		{-RADIUS_STATION_CIRCLE, RADIUS_STATION_CIRCLE, 0.0f, 1.0f},

		// 2. Grupa - watermark
		{-WIDTH_CONTROL_BOARD_RECTANGLE / 4, -HEIGHT_CONTROL_BOARD_RECTANGLE / 4, 0.0f, 0.0f},
		{WIDTH_CONTROL_BOARD_RECTANGLE / 4, -HEIGHT_CONTROL_BOARD_RECTANGLE / 4, 1.0f, 0.0f},
		{WIDTH_CONTROL_BOARD_RECTANGLE / 4, HEIGHT_CONTROL_BOARD_RECTANGLE / 4, 1.0f, 1.0f},
		{-WIDTH_CONTROL_BOARD_RECTANGLE / 4, HEIGHT_CONTROL_BOARD_RECTANGLE / 4, 0.0f, 1.0f},

		// 3. Grupa - vrata
		{ -0.06f, -0.1f, 0.0f, 0.0f },
		{0.06f, -0.1f, 1.0f, 0.0f},
		{0.06f, 0.1f, 1.0f, 1.0f},
		{-0.06f, 0.1f, 0.0f, 1.0f},

		// 4. Grupa - kontrolor
		{ -0.06f, -0.1f, 0.0f, 0.0f },
		{0.06f, -0.1f, 1.0f, 0.0f},
		{0.06f, 0.1f, 1.0f, 1.0f},
		{-0.06f, 0.1f, 0.0f, 1.0f},
		
		// 5. Grupa - brojevi na kontrolnoj tabli
		{ -0.04f, -0.07f, 0.0f, 0.0f },
		{0.04f, -0.07f, 1.0f, 0.0f},
		{0.04f, 0.07f, 1.0f, 1.0f},
		{-0.04f, 0.07f, 0.0f, 1.0f},

		// 6. Grupa - autobus
		{-WIDTH_CONTROL_BOARD_RECTANGLE / 6, -HEIGHT_CONTROL_BOARD_RECTANGLE / 6, 0.0f, 0.0f},
		{WIDTH_CONTROL_BOARD_RECTANGLE / 6, -HEIGHT_CONTROL_BOARD_RECTANGLE / 6, 1.0f, 0.0f},
		{WIDTH_CONTROL_BOARD_RECTANGLE / 6, HEIGHT_CONTROL_BOARD_RECTANGLE / 6, 1.0f, 1.0f},
		{-WIDTH_CONTROL_BOARD_RECTANGLE / 6, HEIGHT_CONTROL_BOARD_RECTANGLE / 6, 0.0f, 1.0f},
	};
}

void setupTextureCenterVertices() {
	// 1. Grupa - brojevi stanice
	for (int i = 0; i < g_vert_bus_stop_centers.size(); i++) {
		g_vert_texture_centers.at(i) = g_vert_bus_stop_centers.at(i);
	}

	// 2. Watermark
	g_vert_texture_centers.at(10) = { -0.75f, 0.85f };

	// 3. vrata
	g_vert_texture_centers.at(11) = { 0.85f, -0.83f };

	// 4. kontrolor
	g_vert_texture_centers.at(12) = { 0.64f, -0.82f };

	// desetica broja ljudi
	g_vert_texture_centers.at(13) = { -0.04f, -0.8f };

	// desetica kazni
	g_vert_texture_centers.at(14) = { 0.22f, -0.8f };

	// jedinica broja ljudi
	g_vert_texture_centers.at(15) = { 0.02f, -0.8f };

	// jedinica kazni
	g_vert_texture_centers.at(16) = { 0.28f, -0.8f };
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
	glBufferData(GL_ARRAY_BUFFER, g_vert_control_board_rectangle.size() * sizeof(glm::vec4), g_vert_control_board_rectangle.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void setupTextureVAO() {
	unsigned VBOtex;

	glGenVertexArrays(1, &g_VAO_textures);
	glBindVertexArray(g_VAO_textures);

	glGenBuffers(1, &VBOtex);
	glBindBuffer(GL_ARRAY_BUFFER, VBOtex);
	glBufferData(GL_ARRAY_BUFFER, g_vert_textures.size() * sizeof(glm::vec4), g_vert_textures.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

// Shader setup
void setupShaders() {
	g_shader_road = createShader("Shaders/road.vert", "Shaders/road.frag");
	g_shader_circle = createShader("Shaders/circle.vert", "Shaders/circle.frag");
	g_shader_rect = createShader("Shaders/rect.vert", "Shaders/rect.frag");
	g_shader_rect_textured = createShader("Shaders/rect-textured.vert", "Shaders/rect-textured.frag");

	glUseProgram(g_shader_rect_textured);
	glUniform1i(glGetUniformLocation(g_shader_rect_textured, "sTex"), 0);
}