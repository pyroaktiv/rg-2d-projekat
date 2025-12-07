#include "../Header/fsm.h"
#include "../Header/globals.h"

double wait_start_time;

glm::vec2 parametricCurve(float t) {
	float xt = 0.1f * (pow(2 + cos(t), 2) - 9 * pow(sin(t), 2)) - 0.3;
	float yt = 0.3f * (2 + cos(t)) * sin(t) + 0.2;

	return { xt, yt };
}

bool isInProximity(unsigned station) {
	return glm::distance(g_vert_bus_stop_centers.at(station), g_bus_position) < RADIUS_STATION_CIRCLE;
}

void doFSMLoop() {

	if (g_fsm_current_bus_stop == -1) {
		float t = glfwGetTime() - g_fsm_start_time;
		float dist = fmod((t - g_fsm_total_num_stops * TIME_WAIT_BUS_STOP) * BUS_SPEED, g_len_road_segments_total);

		int seg = 0;
		while (seg < g_len_road_segments.size() - 1 && g_len_road_segments.at(seg + 1) < dist)
			seg++;

		float segStart = g_len_road_segments.at(seg);
		float segEnd = g_len_road_segments.at(seg + 1);
		float alpha = (dist - segStart) / (segEnd - segStart);

		g_bus_position = glm::mix(g_vert_road.at(seg), g_vert_road.at(seg + 1), alpha);
	}

	if (isInProximity(g_fsm_next_bus_stop) && g_fsm_current_bus_stop == -1) {
		g_fsm_current_bus_stop = g_fsm_next_bus_stop;
		g_fsm_next_bus_stop = (g_fsm_next_bus_stop + 1) % NUM_BUS_STOPS;
		wait_start_time = glfwGetTime();
		g_fsm_total_num_stops++;
	}

	if (g_fsm_current_bus_stop != -1 && glfwGetTime() - wait_start_time > TIME_WAIT_BUS_STOP) {
		g_fsm_current_bus_stop = -1;
	}
}