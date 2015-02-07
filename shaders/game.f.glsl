#version 120

varying vec2 v_texCoord;
varying vec4 v_colorMod;
varying vec4 v_color;

uniform sampler2D u_tex;

void main() {
	vec4 textureColor = texture2D(u_tex, v_texCoord);
	vec4 colorMod = vec4(1.0, 1.0, 1.0, 1.0) - v_colorMod;
	
	vec4 finalColor;
	if(v_color == vec4(0, 0, 0, 1)) {
		finalColor = textureColor - colorMod;
	} else {
		finalColor = v_color;
	}
	
	gl_FragColor = finalColor;
}

