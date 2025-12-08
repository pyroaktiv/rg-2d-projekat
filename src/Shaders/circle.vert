#version 330 core

layout(location = 0) in vec2 inBasePos;
layout(location = 1) in vec2 inCenter;

uniform float uRadius;

void main(){
	gl_Position = vec4(inBasePos.xy * uRadius + inCenter.xy, 0.0, 1.0);
}