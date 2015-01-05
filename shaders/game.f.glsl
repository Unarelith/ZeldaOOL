#version 120

varying vec2 v_texCoord;
varying vec4 v_colorMod;
varying vec4 v_color;

uniform sampler2D u_tex;
uniform int u_paletteID;

vec4 colorInPalette(int paletteID, vec4 color);

void main() {
	vec4 textureColor = texture2D(u_tex, v_texCoord);
	vec4 colorMod = vec4(1.0, 1.0, 1.0, 1.0) - v_colorMod;
	
	vec4 finalColor;
	if(v_color == vec4(0, 0, 0, 1)) {
		finalColor = textureColor - colorMod;
	} else {
		finalColor = v_color;
	}
	
	if(u_paletteID > 0) {
		finalColor = colorInPalette(u_paletteID, finalColor);
	}
	
	gl_FragColor = finalColor;
}

vec4 Color(int r, int g, int b) {
	return vec4(r / 255.0, g / 255.0, b / 255.0, 1.0);
}

vec4 palettes[2 * 4] = vec4[](
	vec4(1.0, 1.0, 1.0, 0.0),
		Color(248, 208, 136),
		Color(16, 168, 64),
		Color(0, 0, 0),
	vec4(1.0, 1.0, 1.0, 0.0),
		Color(0, 0, 0),
		Color(216, 0, 0),
		Color(248, 176, 48)
);

int colorIDinPalette(int paletteID, vec4 color) {
	for(int i = paletteID * 4 ; i < paletteID * 4 + 4 ; i++) {
		if(floor(palettes[i] + 0.5) == floor(color + 0.5)) {
			return i;
		}
	}
	
	return 0;
}

vec4 colorInPalette(int paletteID, vec4 color) {
	return palettes[paletteID * 4 + colorIDinPalette(0, color)];
}

