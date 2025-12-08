#version 330 core

layout(location = 0) in vec2 inPos;
layout(location = 1) in vec2 inTex;

out vec2 chTex;

uniform vec2 uCenter;

void main(){
	gl_Position = vec4(inPos.xy + uCenter, 0.0f, 1.0f);
	chTex = inTex;
}