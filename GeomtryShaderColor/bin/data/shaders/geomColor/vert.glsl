#version 120

#pragma include "common/noise3D.glslinc.frag"
#pragma include "common/rand.glslinc.frag"

#extension GL_EXT_gpu_shader4 : enable

uniform float time;

varying float vNoise;
varying vec3 vNormal;
varying vec2 vTexCoord;

varying float id;

void main(){
    
    vec4 newVertex = gl_Vertex;
    float noise = smoothstep(0.5,1.0,sin(gl_Vertex.z * 4.0 + time));
    
    newVertex.xyz += gl_Normal * abs(noise) * 0.2;
    gl_Position = newVertex;

    vNormal = normalize(gl_NormalMatrix * gl_Normal);
    
    vTexCoord = gl_MultiTexCoord0.st;
    
    vNoise = noise;
    
    id = float(gl_VertexID);
}
