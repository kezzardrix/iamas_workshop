#version 120

#pragma include "common/noise3D.glslinc.frag"
#pragma include "common/rand.glslinc.frag"

uniform float time;

varying vec4 world;
varying vec3 normal;

void main(){
    
    vec4 newVertex = gl_Vertex;
    
    gl_Position = gl_ModelViewProjectionMatrix * newVertex;
    
    world = gl_ModelViewMatrix * newVertex;
    
    normal = normalize(gl_NormalMatrix * gl_Normal);
    
}
