#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

void main(){
    float ambientStrength = 0.1f;
    vec3 ambient = ambientStrength * lightColor;   // 模拟自然光

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);  // 光线的方向
    float diff = max(dot(norm, lightDir), 0.f);
    vec3 diffuse = diff * lightColor;

    vec3 result = (ambient + diffuse) * objectColor;
    FragColor = vec4(result, 1.f);
}