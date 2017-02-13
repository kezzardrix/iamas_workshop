#version 120

#pragma include "common/noise2D.glslinc.frag"

uniform float time;
uniform float alpha;

void main()
{
    float col = snoise(gl_FragCoord.xy * 0.0015 + vec2(time * 0.3,0));
    gl_FragColor = vec4(vec3(col),alpha);
}