uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 modelViewProjectionMatrix;
uniform mat4 textureMatrix;

uniform vec4 globalColor;

uniform float time;
uniform float frame;

in vec4 position;
in vec2 texcoord;
in vec4 color;
in vec3 normal;

out vec4 colorVarying;
out vec2 texCoordVarying;

out vec4 vert;
out vec4 world;