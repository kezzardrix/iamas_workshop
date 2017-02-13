
#version 120

#pragma include "common/noise3D.glslinc.frag"
#pragma include "common/rand.glslinc.frag"

#extension GL_EXT_gpu_shader4 : enable

uniform float time;

varying float id;

void main (void)
{
    vec4 newVertex = gl_Vertex;
    
    newVertex.xyz = vec3(srand(gl_VertexID),
                          srand(gl_VertexID + 400.0),
                          srand(gl_VertexID + 200.0)) * 1000.0;
    

    gl_Position = gl_ModelViewProjectionMatrix * newVertex;
    gl_PointSize = 20000.0 / gl_Position.w;
    
    gl_FrontColor = gl_Color;
    
    id = rand(gl_VertexID);
}
