#version 120

varying vec2 f_texCoord;
varying vec4 f_colorMod;

uniform sampler2D u_tex;

void main(void) {
	vec4 textureColor = texture2D(u_tex, f_texCoord);
	
	if(f_colorMod != vec4(1.0, 1.0, 1.0, 1.0)) {
		textureColor -= vec4(1.0, 1.0, 1.0, 1.0) - f_colorMod;
	}
	
	gl_FragColor = textureColor;
}

