#version 120

#pragma include "common/ads.glslinc.frag"

varying float vNoise;
varying vec4 world;
varying vec3 normal;

uniform vec3 lightPos;

vec3 calcFlatNormal(vec3 world){
    vec3 dx = dFdx(world.xyz);
    vec3 dy = dFdy(world.xyz);
    vec3 n = normalize(cross(normalize(dx), normalize(dy)));
    
    return n;
}

void main()
{
    vec3 n = normal;
    
    //n = calcFlatNormal(world.xyz);
 
    float diff = ads(world.xyz, n, lightPos, true, 300.0);
   
    gl_FragColor = vec4(vec3(diff),1.0);
    
}