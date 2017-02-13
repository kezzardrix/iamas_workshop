#version 120

#pragma include "common/rand.glslinc.frag"

uniform sampler2DRect tex;
uniform float reverse;
uniform vec2 resolution;
uniform float frame;

void main()
{
    vec2 st = gl_TexCoord[0].st;
    vec4 color = texture2DRect(tex,gl_TexCoord[0].st);
    
    float vig = smoothstep(1000,0,length(st.xy - resolution * 0.5));
    
    float rnd = rand(frame * 1.0 + gl_FragCoord.yx * 1.1) * 0.1;
    
    color.rgb = mix(color.rgb, 1.0 - color.rgb, reverse * vig + rnd);
    
    gl_FragColor = color;
    
}