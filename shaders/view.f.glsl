#version 120

varying vec2 f_texCoord;
varying vec4 f_colorMod;

uniform sampler2D u_tex;
uniform int u_paletteID;

vec4 colorInPalette(int paletteID, vec4 color);

void main(void) {
	vec4 finalColor;
	
	finalColor = texture2D(u_tex, f_texCoord) - (vec4(1.0, 1.0, 1.0, 1.0) - f_colorMod);
	
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
		if(round(palettes[i]) == round(color)) {
			return i;
		}
	}
	
	return 0;
}

vec4 colorInPalette(int paletteID, vec4 color) {
	return palettes[paletteID * 4 + colorIDinPalette(0, color)];
}

