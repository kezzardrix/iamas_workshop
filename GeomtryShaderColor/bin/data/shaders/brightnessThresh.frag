#version 120

uniform sampler2DRect tex;
uniform float thresh;

void main() {
    vec2 st = gl_TexCoord[0].st;
	gl_FragColor = max(texture2DRect(tex, st) - vec4(vec3(thresh), 0.0), vec4(0.0));
}
