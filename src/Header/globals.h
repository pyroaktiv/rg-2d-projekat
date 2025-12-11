#ifndef GLOBALS_H_DEFINED
#define GLOBALS_H_DEFINED

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLM/glm.hpp>
#include <vector>
#include <map>
#include "constants.h"

extern GLFWmonitor* g_monitor;
extern const GLFWvidmode* g_monitor_mode;
extern GLFWwindow* g_window;

extern GLFWcursor* g_cursor;
extern GLFWcursor* g_cursorPressed;


// Vertices
extern std::vector<glm::vec2> g_vert_road;
extern std::vector<glm::vec2> g_vert_bus_stop_circle;

extern std::vector<glm::vec2> g_vert_bus_stop_centers;
extern std::vector<glm::vec2> g_vert_texture_centers;

extern std::vector<glm::vec4> g_vert_control_board_rectangle;
extern std::vector<glm::vec4> g_vert_textures;

// Segment lengths
extern std::vector<float> g_len_road_segments;

extern float g_len_road_segments_total;

// VAOs
extern unsigned g_VAO_road;
extern unsigned g_VAO_bus_stops;
extern unsigned g_VAO_control_board_rect;
extern unsigned g_VAO_textures;

// Shaders
extern unsigned g_shader_road;
extern unsigned g_shader_circle;
extern unsigned g_shader_rect;
extern unsigned g_shader_rect_textured;

// Textures
extern unsigned g_tex_0;
extern unsigned g_tex_1;
extern unsigned g_tex_2;
extern unsigned g_tex_3;
extern unsigned g_tex_4;
extern unsigned g_tex_5;
extern unsigned g_tex_6;
extern unsigned g_tex_7;
extern unsigned g_tex_8;
extern unsigned g_tex_9;
extern unsigned g_tex_bus;
extern unsigned g_tex_dogtags;
extern unsigned g_tex_doors_closed;
extern unsigned g_tex_doors_open;
extern unsigned g_tex_man;
extern unsigned g_tex_officer;
extern unsigned g_tex_x;
extern unsigned g_tex_hud;

extern std::vector<unsigned> g_number_tex;

// FSM state variables
extern unsigned g_fsm_total_num_stops;
extern unsigned g_fsm_num_passengers;
extern unsigned g_fsm_num_fines;

extern int g_fsm_current_bus_stop;
extern int g_fsm_next_bus_stop;

extern double g_fsm_start_time;

extern bool g_fsm_is_control;

extern glm::vec2 g_bus_position;


#endif