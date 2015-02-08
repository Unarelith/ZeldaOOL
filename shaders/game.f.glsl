#version 120

varying vec2 v_texCoord;
varying vec4 v_color;

uniform sampler2D u_tex;

void main() {
	vec4 finalColor;
	if(v_texCoord != vec2(0.0, 0.0)) {
		finalColor = texture2D(u_tex, v_texCoord);
	} else {
		finalColor = v_color;
	}
	
	gl_FragColor = finalColor;
}

