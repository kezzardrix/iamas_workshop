float rgbToLumi(in vec3 color){
    return dot(color.rgb,vec3(0.2126,0.7152,0.0722));
}