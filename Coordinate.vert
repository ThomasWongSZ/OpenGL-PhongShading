#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 matView;
uniform mat4 matProj;

void main(void)
{
    gl_Position = matProj * matView * vec4(aPos, 1.0f);
}
