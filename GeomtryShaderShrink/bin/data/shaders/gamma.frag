//
//  simpleShade.frag
//  emptyExample
//
//  Created by Kanda Ryo on 12/01/06.
//  Copyright 2012 Kwansei Gakuin. All rights reserved.
//

#version 120

uniform sampler2DRect tex;
uniform float gamma;

void main (void)
{
    vec2 st = gl_TexCoord[0].st;
    vec4 color = texture2DRect(tex,st);
    gl_FragColor = vec4(pow(color.rgb,vec3(gamma)),color.a);
}