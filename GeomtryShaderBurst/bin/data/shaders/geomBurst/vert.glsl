#version 120

#pragma include "common/noise3D.glslinc.frag"
#pragma include "common/rand.glslinc.frag"

uniform float time;

varying float vNoise;
varying vec3 vNormal;

void main(){
    
    vec4 newVertex = gl_Vertex;
    float noise = pow(cnoise(gl_Vertex.xyz * 1.0 + time),4.0);
    
    newVertex.xyz += gl_Normal * abs(noise) * 0.0;
    gl_Position = newVertex;

    vNormal = normalize(gl_NormalMatrix * gl_Normal);
    
    vNoise = noise;
}
