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
    
    vec3 center = vec3(0,0,0);
    
    for(int i = 0; i < gl_VerticesIn; i++){
        center.xyz += gl_PositionIn[i].xyz;
    }
    
    center /= gl_VerticesIn;
    
    vec3 faceNormal = cross(gl_PositionIn[2].xyz - gl_PositionIn[0].xyz,
                            gl_PositionIn[1].xyz - gl_PositionIn[0].xyz);
    
    faceNormal = normalize(faceNormal);
    
    for(int i = 0; i < gl_VerticesIn; i++){
        
        vec4 pos = gl_PositionIn[i];
        pos.xyz += faceNormal * 1.0;
        
        gl_Position = gl_ModelViewProjectionMatrix * pos;
        world = gl_ModelViewMatrix * gl_PositionIn[i];
        normal = vNormal[i];
        vNoiseIntensity = vNoise[i];
        EmitVertex();
    }
}
