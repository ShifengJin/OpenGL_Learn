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
    vec3 ambient = ambientStrength * lightColor;   // ģ����Ȼ��

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);  // ���ߵķ���  ������
    float diff = max(dot(norm, lightDir), 0.);
    vec3 diffuse = diff * lightColor;

    float specularStrength = 0.5;  // ���淴��
    vec3 viewDir = normalize(viewPos - FragPos);  // �������һ��ָ��۲��ߵĵ�λ����
    vec3 reflectDir = reflect(-lightDir, norm);   // ����һ�������䵽�������,ͨ��������ķ��������㷢�������
    float spec = pow(max(dot(viewDir, reflectDir), 0.), 32);
    vec3 specular = specularStrength * spec * lightColor;
    

    vec3 result = (ambient + diffuse + specular) * objectColor;
    FragColor = vec4(result, 1.);
}