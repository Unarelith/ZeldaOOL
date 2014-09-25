#version 120

attribute vec2 coord2d;
attribute vec2 texcoord;

varying vec2 f_texcoord;

uniform mat4 u_projectionMatrix;

uniform vec2 u_mapPosition;

void main(void) {
	gl_Position = u_projectionMatrix * vec4(coord2d - u_mapPosition, 0.0, 1.0);
	
	f_texcoord = texcoord;
}

