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
    
    for(int i = 0; i < gl_VerticesIn; i++){
        gl_Position = gl_ModelViewProjectionMatrix * gl_PositionIn[i];
        world = gl_ModelViewMatrix * gl_PositionIn[i];
        normal = vNormal[i];
        vNoiseIntensity = vNoise[i];
        EmitVertex();
    }
}
