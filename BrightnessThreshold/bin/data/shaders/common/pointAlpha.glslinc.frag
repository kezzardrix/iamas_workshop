float pointAlpha(float a, float b){
    
    vec3 n;
    n.xy = gl_PointCoord.xy * 2.0 -1.0;
    n.z = 1.0 - dot(n.xy,n.xy);
    float alpha = smoothstep(a,b,n.z);
    
    return alpha;
    
}