#include "../Header/globals.h"
#include "../Header/fsm.h"

GLFWmonitor* g_monitor;
const GLFWvidmode* g_monitor_mode;
GLFWwindow* g_window;

std::map<char, struct character_st> g_characters;

// Vertices
std::vector<glm::vec2> g_vert_road(NUM_SEGMENTS_ROAD + 1);
std::vector<glm::vec2> g_vert_bus_stop_centers(NUM_BUS_STOPS);
std::vector<glm::vec2> g_vert_bus_stop_circle(NUM_SEGMENTS_CIRCLE + 2);
std::vector<glm::vec2> g_vert_control_board_rectangle(4);

// Segment lengths
std::vector<float> g_len_road_segments(NUM_SEGMENTS_ROAD + 1);

float g_len_road_segments_total;

// VAOs
unsigned g_VAO_road;
unsigned g_VAO_bus_stops;

unsigned g_VAO_control_board_rect;


// Shaders
unsigned g_shader_road;
unsigned g_shader_circle;
unsigned g_shader_rect;

// FSM state variables
unsigned g_fsm_total_num_stops = 0;

int g_fsm_current_bus_stop = -1;
int g_fsm_next_bus_stop = 0;

double g_fsm_start_time;

bool g_is_control;

glm::vec2 g_bus_position = parametricCurve(0.0f);