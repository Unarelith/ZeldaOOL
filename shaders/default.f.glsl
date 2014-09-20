#version 120

varying vec2 f_texcoord;

uniform sampler2D tex;

void main(void) {
  gl_FragColor = texture2D(tex, f_texcoord);
}

