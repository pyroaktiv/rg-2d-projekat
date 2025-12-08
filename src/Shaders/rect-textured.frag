#version 330 core

in vec2 chTex;

out vec4 outCol;

uniform vec4 uCol;
uniform sampler2D sTex;

void main(){
	outCol = texture(sTex, chTex) * uCol;
}