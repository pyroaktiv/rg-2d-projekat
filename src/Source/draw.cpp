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

void drawTemporaryRectangle() {
	glUseProgram(g_shader_rect);

	glUniform2f(glGetUniformLocation(g_shader_rect, "uCenter"), g_bus_position[0], g_bus_position[1]);
	glBindVertexArray(g_VAO_temporary_rect);

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}