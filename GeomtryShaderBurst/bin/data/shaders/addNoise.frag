#version 120

#pragma include "common/rgbToLumi.glslinc.frag"
#pragma include "common/rand.glslinc.frag"

uniform sampler2DRect tex;
uniform float time;

void main()
{
    vec2 st = gl_TexCoord[0].st;
    vec4 color = texture2DRect(tex,st);
    
    float lumi = rgbToLumi(color.rgb);
    lumi = clamp(lumi,0.0,1.0);
    float rnd = rand(gl_FragCoord.xy * 0.2 + time);
    
    rnd = (1.0 - lumi) * rnd;
    rnd *= lumi;
    
    gl_FragColor = color + vec4(vec3(rnd) * 0.3,0.0);
}