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
	glUseProgram(g_shader_rect_textured);

	glBindVertexArray(g_VAO_control_board_rect);
	glBindTexture(GL_TEXTURE_2D, g_tex_hud);
	glUniform2f(glGetUniformLocation(g_shader_rect, "uCenter"), 0.4f, -0.8f);
	glUniform4f(glGetUniformLocation(g_shader_rect_textured, "uCol"), 1.0f, 1.0f, 1.0f, 1.0f);

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void drawTextures() {
	glUseProgram(g_shader_rect_textured);

	glBindVertexArray(g_VAO_textures);
	for (int i = 0; i < NUM_BUS_STOPS; i++) {
		glBindTexture(GL_TEXTURE_2D, g_number_tex[i]);
		glUniform2f(glGetUniformLocation(g_shader_rect_textured, "uCenter"), g_vert_texture_centers[i][0], g_vert_texture_centers[i][1]);
		glUniform4f(glGetUniformLocation(g_shader_rect_textured, "uCol"), 1.0f, 1.0f, 1.0f, 1.0f);
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	}

	if (g_fsm_current_bus_stop == -1) {
		glBindTexture(GL_TEXTURE_2D, g_tex_doors_closed);
	}
	else {
		glBindTexture(GL_TEXTURE_2D, g_tex_doors_open);
	}

	glUniform2f(glGetUniformLocation(g_shader_rect_textured, "uCenter"), g_vert_texture_centers[11][0], g_vert_texture_centers[11][1]);
	glUniform4f(glGetUniformLocation(g_shader_rect_textured, "uCol"), 1.0f, 1.0f, 1.0f, 1.0f);
	glDrawArrays(GL_TRIANGLE_FAN, 8, 4);


	if (g_fsm_is_control) {
		glBindTexture(GL_TEXTURE_2D, g_tex_officer);
		glUniform2f(glGetUniformLocation(g_shader_rect_textured, "uCenter"), g_vert_texture_centers[12][0], g_vert_texture_centers[12][1]);
		glUniform4f(glGetUniformLocation(g_shader_rect_textured, "uCol"), 1.0f, 1.0f, 1.0f, 1.0f);
		glDrawArrays(GL_TRIANGLE_FAN, 12, 4);
	}


	glBindTexture(GL_TEXTURE_2D, g_number_tex[g_fsm_num_passengers / 10]);
	glUniform2f(glGetUniformLocation(g_shader_rect_textured, "uCenter"), g_vert_texture_centers[13][0], g_vert_texture_centers[13][1]);
	glUniform4f(glGetUniformLocation(g_shader_rect_textured, "uCol"), 1.0f, 1.0f, 1.0f, 1.0f);
	glDrawArrays(GL_TRIANGLE_FAN, 16, 4);

	glBindTexture(GL_TEXTURE_2D, g_number_tex[g_fsm_num_fines / 10]);
	glUniform2f(glGetUniformLocation(g_shader_rect_textured, "uCenter"), g_vert_texture_centers[14][0], g_vert_texture_centers[14][1]);
	glUniform4f(glGetUniformLocation(g_shader_rect_textured, "uCol"), 1.0f, 0.0f, 0.0f, 1.0f);
	glDrawArrays(GL_TRIANGLE_FAN, 16, 4);

	glBindTexture(GL_TEXTURE_2D, g_number_tex[g_fsm_num_passengers % 10]);
	glUniform2f(glGetUniformLocation(g_shader_rect_textured, "uCenter"), g_vert_texture_centers[15][0], g_vert_texture_centers[15][1]);
	glUniform4f(glGetUniformLocation(g_shader_rect_textured, "uCol"), 1.0f, 1.0f, 1.0f, 1.0f);
	glDrawArrays(GL_TRIANGLE_FAN, 16, 4);

	glBindTexture(GL_TEXTURE_2D, g_number_tex[g_fsm_num_fines % 10]);
	glUniform2f(glGetUniformLocation(g_shader_rect_textured, "uCenter"), g_vert_texture_centers[16][0], g_vert_texture_centers[16][1]);
	glUniform4f(glGetUniformLocation(g_shader_rect_textured, "uCol"), 1.0f, 0.0f, 0.0f, 1.0f);
	glDrawArrays(GL_TRIANGLE_FAN, 16, 4);

	glBindTexture(GL_TEXTURE_2D, g_tex_bus);
	glUniform2f(glGetUniformLocation(g_shader_rect_textured, "uCenter"), g_bus_position[0], g_bus_position[1]);
	glUniform4f(glGetUniformLocation(g_shader_rect_textured, "uCol"), 1.0f, 1.0f, 1.0f, 1.0f);
	glDrawArrays(GL_TRIANGLE_FAN, 20, 4);

	glBindTexture(GL_TEXTURE_2D, g_tex_dogtags);
	glUniform2f(glGetUniformLocation(g_shader_rect_textured, "uCenter"), g_vert_texture_centers[10][0], g_vert_texture_centers[10][1]);
	glUniform4f(glGetUniformLocation(g_shader_rect_textured, "uCol"), 1.0f, 1.0f, 1.0f, 1.0f);
	glDrawArrays(GL_TRIANGLE_FAN, 4, 4);
}