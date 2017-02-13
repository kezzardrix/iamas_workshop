#version 120

#pragma include "common/ads.glslinc.frag"

varying vec4 world;
varying vec3 normal;

uniform vec3 lightPos;

void main()
{
  
    float diff = ads(world.xyz, normal, lightPos, true, 300.0);
   
    gl_FragColor = vec4(vec3(diff),1.0);
    
}