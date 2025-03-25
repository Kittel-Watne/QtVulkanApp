#version 450

layout(location = 0) in vec3 v_color;
layout(location = 1) in vec2 v_texCoord;

layout(location = 0) out vec4 fragColor;

layout(set = 1, binding = 0) uniform sampler2D textureSampler;

void main()
{
    fragColor = texture(textureSampler, v_texCoord );
}
