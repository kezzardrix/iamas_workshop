
#version 120

#pragma include "common/ads.glslinc.frag"
#pragma include "common/rand.glslinc.frag"
#pragma include "common/rgbToLumi.glslinc.frag"

uniform sampler2DRect normalTex;
uniform sampler2DRect colorTex;
uniform vec3 lightPos;
uniform float time;

uniform float vol;

vec3 palette( in float t, in vec3 a, in vec3 b, in vec3 c, in vec3 d )
{
    return a + b*cos( 6.28318*(c*t+d) );
}

void main (void)
{
    vec2 st = gl_TexCoord[0].st;
    vec4 normalColor = texture2DRect(normalTex,st);
    
    vec3 m = normalize(gl_NormalMatrix * normalColor.rgb);
    
    vec3 lightPos = vec3(sin(time) * 0.7,cos(time * 0.75) * 0.7,1.0);
    vec3 lPos = normalize(lightPos);
    float diff = dot(lPos,m);
    float s = pow(clamp(-reflect(lPos, m).z, 0.0, 1.0), 30.0);
    diff = mix(diff,s,0.5);
    
    vec3 paletteColor = palette(diff,vec3(0.5),vec3(0.5),vec3(10,1,0.3),vec3(0.0,0.33,0.67));
    
    vec3 finalColor = vec3(diff);
    finalColor = mix(finalColor,paletteColor,1);
    
    vec4 addColor = texture2DRect(colorTex,st);

    gl_FragColor = vec4(finalColor * addColor.rgb,addColor.a);
}
