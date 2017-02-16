
#version 120

#pragma include "common/noise3D.glslinc.frag"
#pragma include "common/rand.glslinc.frag"

uniform float time;

varying float id;

void main (void)
{
    vec4 newVertex = gl_Vertex;
    
    newVertex.xyz += vec3(srand(gl_Normal.x),
                          srand(gl_Normal.x + 400.0),
                          srand(gl_Normal.x + 200.0)) * sin(time * 0.1);
    
    newVertex.x += (time + 10.0) * rand(gl_Normal.x) * 100.0;
    newVertex.x = mod(newVertex.x, 2000) - 1000;
    
    float offset = step(rand(gl_Normal.x),0.5);
    
    newVertex.y += cnoise(newVertex.yxz * (0.002) + time * 0.01 + offset) * 1000.0;
    newVertex.z += cnoise(newVertex.xzy * (0.002) - time * 0.005 + offset) * 1000.0;
    
    gl_Position = gl_ModelViewProjectionMatrix * newVertex;
    gl_PointSize = (pow(rand(gl_Normal.x + 100),7.0) * 80000) / gl_Position.w;
    
    gl_FrontColor = gl_Color;
    
    id = rand(gl_Normal.x);
}
