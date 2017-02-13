#version 120

#pragma include "common/noise3D.glslinc.frag"
#pragma include "common/rand.glslinc.frag"

uniform float time;

varying in float vNoise[3];
varying in vec3 vNormal[3];

varying out vec3 normal;
varying out vec4 world;
varying out float vNoiseIntensity;

void main(){
    
    vec3 center = vec3(0,0,0);
    
    for(int i = 0; i < gl_VerticesIn; i++){
        center.xyz += gl_PositionIn[i].xyz;
    }
    
    center /= gl_VerticesIn;
    
    
    for(int i = 0; i < gl_VerticesIn; i++){
        
        vec4 pos = gl_PositionIn[i];
        pos.xyz += (center - pos.xyz) * 0.5;
       // pos.xyz += (pos.xyz - center) * vNoise[i] * 10.0;
        
        gl_Position = gl_ModelViewProjectionMatrix * pos;
        world = gl_ModelViewMatrix * gl_PositionIn[i];
        normal = vNormal[i];
        vNoiseIntensity = vNoise[i];
        EmitVertex();
    }
}
