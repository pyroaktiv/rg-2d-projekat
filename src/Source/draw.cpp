#include "../Header/draw.h"

#include <GL/glew.h>
#include "../Header/globals.h"

void drawRoad() {
	glUseProgram(g_shader_road);

	glLineWidth(WIDTH_ROAD_LINE);

	glBindVertexArray(g_VAO_road);
	glDrawArrays(GL_LINE_STRIP, 0, NUM_SEGMENTS_ROAD + 1);
}

void drawBusStops() {
	glUseProgram(g_shader_circle);

	glUniform1f(glGetUniformLocation(g_shader_circle, "uRadius"), RADIUS_STATION_CIRCLE);

	glBindVertexArray(g_VAO_bus_stops);
	glDrawArraysInstanced(GL_TRIANGLE_FAN, 0, NUM_SEGMENTS_CIRCLE + 2, 10);
}

void drawControlBoardRectangle() {
	glUseProgram(g_shader_rect);

	glUniform2f(glGetUniformLocation(g_shader_rect, "uCenter"), 1.0f - WIDTH_CONTROL_BOARD_RECTANGLE / 2, -1.0f + HEIGHT_CONTROL_BOARD_RECTANGLE / 2);
	glBindVertexArray(g_VAO_control_board_rect);

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}