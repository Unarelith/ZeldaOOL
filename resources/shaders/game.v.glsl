#version 120

attribute vec4 coord3d;
attribute vec2 texCoord;
attribute vec4 color;

varying vec2 v_texCoord;
varying vec4 v_color;

uniform mat4 u_modelMatrix;
uniform mat4 u_projectionMatrix;
uniform mat4 u_viewMatrix;
uniform vec2 u_viewPosition;

void main() {
	v_texCoord = texCoord;
	v_color = color;

	vec4 coord = u_modelMatrix * vec4(coord3d.xy + u_viewPosition, 0.0, 1.0);

	gl_Position = u_projectionMatrix * u_viewMatrix * coord;
}

// vim:ft=glsl
