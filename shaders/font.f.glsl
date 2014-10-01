#version 120

varying vec2 f_texCoord;
//varying vec3 f_color;

uniform sampler2D u_tex;

void main(void) {
	/*vec4 finalColor = texture2D(u_tex, f_texCoord);
	
	if(finalColor == vec4(0.0, 0.0, 0.0, 1.0)) {
		finalColor = vec4(f_color, 1.0);
	}
	
	gl_FragColor = finalColor;*/
	gl_FragColor = texture2D(u_tex, f_texCoord);
}

