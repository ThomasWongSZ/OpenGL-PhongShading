#version 330 core

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoord;
in vec3 absPos;
out vec4 FragColor;

struct LightPoint{
    vec3 position;

    //可以直接用color计算光照，但光照强度会很强，推荐用ambient diffuse 和specular计算光照
    vec3 color;
    vec3 ambient;       // usually set to a low intensity
    vec3 diffuse;       // set to the exact color we'd like a light to have. often a bright white color
    vec3 specular;      // usually kept at vec3(1.0) shining at full intensity
};

struct Material{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

uniform sampler2D texSurface;           //默认对应纹理单元0
uniform LightPoint lightPoint;          //点光源
uniform Material material;              //材质
uniform vec3 cameraPos;                 //摄像机中心位置

vec3 diffuse;
vec3 ambient;
vec3 specular;

vec3 objectColor;
vec3 textureColor;
float ambientStrength = 0.2;
float specularStrength = 0.6;

vec3 calcLightDirect(LightPoint light, vec3 unitNormal);

void main(){
    vec3 result = vec3(0,0,0);
    vec3 unitNormal = normalize(Normal);

    result += calcLightDirect(lightPoint, unitNormal);
    FragColor = vec4(result, 1.0);

}

/**
  * 计算点光源的影响
  */
vec3 calcLightDirect(LightPoint light, vec3 unitNormal){

    // Ambient
    ambient = material.ambient * light.ambient;

    // Diffuse
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(unitNormal, lightDir), 0.0);
    diffuse = (diff * material.diffuse) * light.diffuse;

    // Specular
    vec3 dirToCamera = normalize(cameraPos - FragPos);      //片段指向摄像机
    vec3 dirReflect = reflect(-lightDir, unitNormal);
    float spec = pow(max(dot(dirToCamera, dirReflect), 0.0), material.shininess);
    specular = (material.specular * spec) * light.specular;

    objectColor = mix(textureColor,objectColor, 0.3);
    vec3 result = (ambient + diffuse + specular);
    return result;
}

