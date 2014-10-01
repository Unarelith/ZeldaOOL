#version 120

varying vec2 f_texCoord;

uniform sampler2D u_tex;

void main(void) {
	gl_FragColor = texture2D(u_tex, f_texCoord);
}

