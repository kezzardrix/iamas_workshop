#version 120

#pragma include "common/noise3D.glslinc.frag"
#pragma include "common/rand.glslinc.frag"

uniform float time;

varying vec3 vNormal;

void main(){
    
    vec4 newVertex = gl_Vertex;

    gl_Position = newVertex;

    vNormal = normalize(gl_NormalMatrix * gl_Normal);
    
}
