//
//  simpleShade.frag
//  emptyExample
//
//  Created by Kanda Ryo on 12/01/06.
//  Copyright 2012 Kwansei Gakuin. All rights reserved.
//

#version 120

#pragma include "common/rgbToLumi.glslinc.frag"
#pragma include "common/rand.glslinc.frag"

uniform sampler2DRect tex;
uniform sampler2D gradationMap;
uniform float gamma;
uniform float time;

void main (void)
{
    vec2 st = gl_TexCoord[0].st;
    vec4 color = texture2DRect(tex,st);
    

    float lumi = rgbToLumi(color.rgb);
    lumi = max(lumi,0.0);
    
    float ramp = clamp(lumi,0.0,1.0);
    vec4 mapColor = pow(texture2D(gradationMap,vec2(0, 1.0 - ramp)), vec4(2.2));
    
    vec3 finalColor = mapColor.rgb;
    
    float rnd = rand(gl_FragCoord.xy * 0.2 + time);
    
    rnd = (1.0 - lumi) * rnd;
    rnd *= lumi;
    
    gl_FragColor = vec4(pow(finalColor.rgb,vec3(gamma)) + rnd * 0.3,color.a);
}