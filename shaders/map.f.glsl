#version 120

varying vec2 f_texCoord;

uniform sampler2D tex;

void main(void) {
  gl_FragColor = texture2D(tex, f_texCoord);
}

