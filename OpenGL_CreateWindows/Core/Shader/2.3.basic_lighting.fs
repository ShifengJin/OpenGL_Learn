#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec3 LightPos;

uniform vec3 lightColor;
uniform vec3 objectColor;

void main(){
    float ambientStrength = 0.1f;
    vec3 ambient = ambientStrength * lightColor;  // 环境光
    
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(LightPos - FragPos);  // 漫反射
    float diff = max(dot(norm, lightDir), 0.f);
    vec3 diffuse = diff * lightColor;

    float specularStrength = 0.5f;
    vec3 viewDir = normalize(-FragPos);            // 镜面反射
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.f), 32);
    vec3 specular = specularStrength * spec * lightColor;

    vec3 result = (ambient + diffuse * specular) * objectColor;
    FragColor = vec4(result, 1.f);
}