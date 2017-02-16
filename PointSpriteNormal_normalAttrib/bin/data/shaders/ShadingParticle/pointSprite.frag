
#version 120

#pragma include "common/pointAlpha.glslinc.frag"
#pragma include "common/rand.glslinc.frag"
#pragma include "common/noise2D.glslinc.frag"

#define PI 3.14159265

varying float id;
uniform float time;

void main (void)
{
    
    vec2 st = gl_TexCoord[0].st;
    vec3 n;
    n.xy = gl_PointCoord.xy * 2.0 -1.0;
    n.z = 1.0 - dot(n.xy,n.xy);

    float pAlpha = smoothstep(0.0,1.0,n.z);
    n.z = sqrt(n.z);
    vec3 m = normalize(n);
    
    gl_FragColor = vec4(m,pAlpha);
  
}
