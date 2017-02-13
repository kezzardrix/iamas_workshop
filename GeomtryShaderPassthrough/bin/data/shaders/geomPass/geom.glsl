#version 120

#pragma include "common/noise3D.glslinc.frag"
#pragma include "common/rand.glslinc.frag"

uniform float time;

in varying float vNoise[3];
in varying vec3 vNormal[3];

out varying vec3 normal;
out varying vec4 world;
out varying float vNoiseIntensity;

void main(){
    
    for(int i = 0; i < gl_VerticesIn; i++){
        gl_Position = gl_ModelViewProjectionMatrix * gl_PositionIn[i];
        world = gl_ModelViewMatrix * gl_PositionIn[i];
        normal = vNormal[i];
        vNoiseIntensity = vNoise[i];
        EmitVertex();
    }
}
