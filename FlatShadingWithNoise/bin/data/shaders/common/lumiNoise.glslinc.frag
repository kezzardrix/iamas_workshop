float lumiNoise(vec3 color, float time, float scale){
    
    float lumi = dot(color.rgb,vec3(0.2126,0.7152,0.0722));
    lumi = clamp(lumi,0.0,1.0);
    vec2 co = gl_FragCoord.xy * 0.1 + time;
    float rnd = fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);

    rnd *= (1.0 - lumi);
    rnd *= lumi;
    rnd *= scale;
    
    return rnd;
}

float lumiNoise(float _lumi, float time, float scale){
    
    float lumi = _lumi;
    lumi = clamp(lumi,0.0,1.0);
    vec2 co = gl_FragCoord.xy * 0.1 + time;
    float rnd = fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
    
    rnd *= (1.0 - lumi);
    rnd *= lumi;
    rnd *= scale;
    
    return rnd;
}