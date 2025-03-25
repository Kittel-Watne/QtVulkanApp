#version 450

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;

layout(location = 0) out vec3 v_color;

layout(push_constant) uniform mod {
    mat4 model;
} model;

layout(set = 0, binding = 0) uniform cam {
    mat4 view;
    mat4 projection;
    vec3 extracolor;
} camera;

out gl_PerVertex { vec4 gl_Position; };

void main()
{
    v_color = camera.extracolor;
    gl_Position =   camera.projection * camera.view * model.model * vec4(position, 1.0);
}

