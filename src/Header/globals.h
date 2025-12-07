#ifndef GLOBALS_H_DEFINED
#define GLOBALS_H_DEFINED

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>
#include <vector>
#include <map>
#include "constants.h"

#include "defs.h"

extern GLFWmonitor* g_monitor;
extern const GLFWvidmode* g_monitor_mode;
extern GLFWwindow* g_window;

extern std::map<char, struct character_st> g_characters;


// Vertices
extern std::vector<glm::vec2> g_vert_road;
extern std::vector<glm::vec2> g_vert_bus_stop_centers;
extern std::vector<glm::vec2> g_vert_bus_stop_circle;
extern std::vector<glm::vec2> g_vert_control_board_rectangle;

// Segment lengths
extern std::vector<float> g_len_road_segments;

extern float g_len_road_segments_total;

// VAOs
extern unsigned g_VAO_road;
extern unsigned g_VAO_bus_stops;

extern unsigned g_VAO_control_board_rect;

// Shaders
extern unsigned g_shader_road;
extern unsigned g_shader_circle;
extern unsigned g_shader_rect;

// FSM state variables
extern unsigned g_fsm_total_num_stops;

extern int g_fsm_current_bus_stop;
extern int g_fsm_next_bus_stop;

extern double g_fsm_start_time;

extern bool g_is_control;

extern glm::vec2 g_bus_position;


#endif