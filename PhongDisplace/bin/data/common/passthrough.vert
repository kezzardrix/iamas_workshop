#version 150

#pragma include "commonVertInput3.glslinc.frag"

uniform sampler2D tex;

void main()
{
    
    gl_Position = modelViewProjectionMatrix * position;
    texCoordVarying = texcoord;
    colorVarying = globalColor;
    
}