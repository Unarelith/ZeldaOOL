#version 120

varying vec2 f_texCoord;
varying vec4 f_colorMod;

uniform sampler2D u_tex;

void main(void) {
	//gl_FragColor = texture2D(u_tex, f_texCoord) - (vec4(1.0, 1.0, 1.0, 1.0) - f_colorMod);
	gl_FragColor = texture2D(u_tex, f_texCoord) - (f_colorMod - f_colorMod);
}

