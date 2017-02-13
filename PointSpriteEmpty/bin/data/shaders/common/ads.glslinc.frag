float ads(vec3 position, vec3 normal, vec3 lightPos, bool isDirectional, float spec){
    
    vec3 n = normalize(normal.xyz);
    
    vec3 s = vec3(0,0,0);
    
    if(isDirectional == true)s = normalize(lightPos);
    else s = normalize(lightPos - position.xyz);
    
    vec3 v = normalize(vec3(-position));
    vec3 r = reflect(-s,n);
    
    float diffuse = max(dot(s,n), 0.0);
    float specular = pow(max(dot(r,v),0.0),spec);
    
    if(dot(normal,s) > 0.0)return diffuse + specular;
    else 0.0;
}
