#version 330 core

layout(location = 0) in vec2 inPos;

uniform vec2 uCenter;

void main(){
	gl_Position = vec4(inPos.xy + uCenter.xy, 0.0f, 1.0f);
}