#version 120

varying vec2 f_texCoord;

uniform sampler2D u_tex;
uniform vec3 u_color;

void main(void) {
	vec4 finalColor = texture2D(u_tex, f_texCoord);
	
	if(finalColor == vec4(0.0, 0.0, 0.0, 1.0)) {
		finalColor = vec4(u_color, 1.0);
	}
	
	gl_FragColor = finalColor;
}

