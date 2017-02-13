#version 120

#pragma include "common/pointAlpha.glslinc.frag"

void main()
{
   
    gl_FragColor = gl_Color * vec4(1,1,1,pointAlpha(0.0,0.4));
    
}