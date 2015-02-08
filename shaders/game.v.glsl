#version 120

attribute vec2 coord2d;
attribute vec2 texCoord;
attribute vec4 color;

varying vec2 v_texCoord;
varying vec4 v_color;

uniform mat4 u_projectionMatrix;
uniform vec2 u_viewPosition;

void main() {
	gl_Position = u_projectionMatrix * vec4(coord2d + u_viewPosition, 0.0, 1.0);
	
	v_texCoord = texCoord;
	v_color = color;
}

