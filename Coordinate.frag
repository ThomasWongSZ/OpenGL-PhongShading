#version 330 core
out vec4 FragColor;
uniform int axisType;
void main(void)
{
    if(axisType == 0)
        FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);   //x
    else if(axisType == 1)
        FragColor = vec4(0.0f, 1.0f, 0.0f, 1.0f);   //y
    else
        FragColor = vec4(0.0f, 0.0f, 1.0f, 1.0f);   //z
}
