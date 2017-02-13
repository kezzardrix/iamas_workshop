uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 modelViewProjectionMatrix;
uniform mat4 textureMatrix;

uniform vec4 globalColor;

uniform float time;
uniform float frame;

uniform vec2 resolution;

in vec4 colorVarying;
in vec2 texCoordVarying;

in vec4 vert;
in vec4 world;

out vec4 outputColor;