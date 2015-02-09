#version 120

varying vec2 v_texCoord;
varying vec4 v_color;

uniform sampler2D u_tex;

void main() {
	vec4 finalColor;
	if(v_texCoord != vec2(0.0, 0.0)) {
		finalColor = texture2D(u_tex, v_texCoord);
		
		if(v_color != vec4(0.0, 0.0, 0.0, 1.0)) {
			finalColor -= vec4(1.0, 1.0, 1.0, 1.0) - vec4(v_color.xyz, 1.0);
		}
	} else {
		finalColor = v_color;
	}
	
	gl_FragColor = finalColor;
}

