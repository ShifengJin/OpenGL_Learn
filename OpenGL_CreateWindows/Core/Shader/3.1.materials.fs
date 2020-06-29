#version 330 core

out vec4 FragColor;

struct Material{
    vec3 ambient;   // 材质的颜色
    vec3 diffuse;   // 材质漫反射的颜色
    vec3 specular;  // 材质镜面反射的颜色
    float shininess;// 影响镜面高光的散射/半径
};

struct Light{
    vec3 position;   // 灯光的位置
    vec3 ambient;    // 环境光照的颜色
    vec3 diffuse;    // 漫反射的颜色
    vec3 specular;   // 镜面反射的颜色
};

in vec3 FragPos;
in vec3 Normal;

uniform vec3 viewPos;       // 相机的位置
uniform Material material;
uniform Light light;

void main(){
    // 环境光照
    vec3 ambient = light.ambient * material.ambient;     // 环境光照在材质上,材质漫反射出的颜色
    
    // 漫反射光照
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);  // 物体指向光源的向量
    float diff = max(dot(norm, lightDir), 0.f);           // a*b = |a||b|cos(\theta)
    vec3 diffuse = light.diffuse * (diff * material.diffuse);  // 漫反射光源的颜色*材质漫反射的颜色*diff

    // 镜面反射
    vec3 viewDir = normalize(viewPos - FragPos);   // 物体到相机的向量
    vec3 reflectDir = reflect(-lightDir, norm);    // 反射向量
    float spec = pow(max(dot(viewDir, reflectDir), 0.f), material.shininess);  // 反射向量 与 物体到相机向量的夹角
    vec3 specular = light.specular * (spec * material.specular); // 镜面反射光源的颜色*材质镜面反射的颜色*spec

    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
}