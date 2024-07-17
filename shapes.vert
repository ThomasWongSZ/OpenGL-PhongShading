#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCord;

out vec3 absPos;
out vec3 FragPos;       //use to calculate the light
out vec3 Normal;
out vec2 TexCoord;

uniform mat4 matModel;
uniform mat4 matView;
uniform mat4 matProj;

void main(){

    gl_Position = matProj * matView * matModel * vec4(aPos, 1.0f);  //GLSL will process the "Projection Division" automatically
    //Normal = mat3(transpose(inverse(matModel))) * aNormal;          //using "Normal Matrix" :'the transpose of the inverse of the upper-left 3x3 part of the model matrix'.
    Normal = mat3(matModel) * aNormal;

    vec4 pos = (matModel * vec4(aPos,1.0f));
    FragPos = pos.xyz;

    absPos = aPos;

    TexCoord = aTexCord;

}
