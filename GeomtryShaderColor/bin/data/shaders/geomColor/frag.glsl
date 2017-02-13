#version 120

#pragma include "common/ads.glslinc.frag"

varying float vNoiseIntensity;
varying vec4 world;
varying vec3 normal;

uniform vec3 lightPos;

varying vec2 texCoord;

uniform sampler2D tex;

vec3 calcFlatNormal(vec3 world){
    vec3 dx = dFdx(world.xyz);
    vec3 dy = dFdy(world.xyz);
    vec3 n = normalize(cross(normalize(dx), normalize(dy)));
    
    return n;
}

void main()
{
    vec2 st = texCoord;
    vec4 color = texture2D(tex,st);
    color.rgb = pow(color.rgb,vec3(2.2));
    
    
    vec3 n = calcFlatNormal(world.xyz);
    
    float vNoise = vNoiseIntensity;
    
    float diff = ads(world.xyz, n, lightPos, true, 300.0);
   
    gl_FragColor = vec4(vec3(diff) * color.rgb,1.0);
    
}