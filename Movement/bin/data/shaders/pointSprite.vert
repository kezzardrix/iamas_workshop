#version 120

#pragma include "common/rand.glslinc.frag"

#extension GL_EXT_gpu_shader4 : enable
uniform vec3 progress;

void main(){
    
    int id = gl_VertexID;
    
    vec4 newPos = gl_Vertex;
   
    float scale = rand(id + 1000) * 0.7 + 0.3;
    
    newPos.x += srand(id + 100) * 1000.0 + scale * progress.x;
    newPos.y += srand(id + 300) * 1000.0 + scale * progress.y;
    newPos.z += srand(id + 200) * 1000.0 + scale * progress.z;
    
    newPos.xyz = mod(vec3(newPos.xyz),vec3(2000)) - vec3(1000);
    //newPos.y *= 0.005;
    
	gl_Position = gl_ModelViewProjectionMatrix * newPos;
    
    float acsent = step(0.997, rand(gl_VertexID));

    gl_PointSize = (1300 + acsent * 20000) / gl_Position.w;
    
    gl_FrontColor = mix(vec4(1,1,1,0.5),vec4(2,0.5,0.5,0.5),acsent);
}
