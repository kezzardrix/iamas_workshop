
#version 120

#pragma include "common/noise3D.glslinc.frag"
#pragma include "common/rand.glslinc.frag"

uniform float time;

varying float id;

void main (void)
{
    vec4 newVertex = gl_Vertex;
    
    newVertex.xyz = vec3(srand(gl_Normal.x),
                          srand(gl_Normal.x + 400.0),
                          srand(gl_Normal.x + 200.0)) * 1000.0;
    

    gl_Position = gl_ModelViewProjectionMatrix * newVertex;
    gl_PointSize = 20000.0 / gl_Position.w;
    
    gl_FrontColor = gl_Color;
    
    id = rand(gl_Normal.x);
}
