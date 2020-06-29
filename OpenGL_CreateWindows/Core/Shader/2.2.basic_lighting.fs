#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

void main(){
    float ambientStrength = 0.1f;
    vec3 ambient = ambientStrength * lightColor;   // 模拟自然光

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);  // 光线的方向  漫反射
    float diff = max(dot(norm, lightDir), 0.);
    vec3 diffuse = diff * lightColor;

    float specularStrength = 0.5;  // 镜面反射
    vec3 viewDir = normalize(viewPos - FragPos);  // 物体表面一点指向观察者的单位向量
    vec3 reflectDir = reflect(-lightDir, norm);   // 计算一束光照射到物体表面,通过该物体的法向量计算发射的向量
    float spec = pow(max(dot(viewDir, reflectDir), 0.), 32);
    vec3 specular = specularStrength * spec * lightColor;
    

    vec3 result = (ambient + diffuse + specular) * objectColor;
    FragColor = vec4(result, 1.);
}