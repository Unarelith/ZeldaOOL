#version 120

varying vec2 f_texcoord;

uniform sampler2D u_tex;

void main(void) {
	gl_FragColor = texture2D(u_tex, f_texcoord);
}

