#version 120

varying vec2 v_texCoord;
varying vec4 v_color;

uniform sampler2D u_tex;
uniform int u_paletteID;

vec4 colorInPalette(int paletteID, vec4 color);

void main() {
	/* vec4 textureColor = texture2D(u_tex, v_texCoord); */
	/* vec4 colorMod = vec4(1.0, 1.0, 1.0, 1.0) - v_color; */
    /*  */
	/* vec4 finalColor; */
	/* if(v_texCoord.x == -1 && v_texCoord.y == -1) { */
	/* 	finalColor = v_color; */
	/* } else { */
	/* 	/* finalColor = textureColor - colorMod; */
	/* 	/* finalColor = textureColor; */
	/* } */

	vec4 color = v_color;
	if (v_texCoord.x != -1 && v_texCoord.y != -1) {
		vec4 texColor = texture2D(u_tex, v_texCoord);
		color = vec4(texColor.rgb - (1 - color.rgb), min(texColor.a, color.a));
	}

	if(u_paletteID > 0) {
		color = colorInPalette(u_paletteID, color);
	}

	gl_FragColor = color;
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

// vim:ft=glsl
