#version 330 core

out vec4 FragColor;

struct Material{
    vec3 ambient;   // ���ʵ���ɫ
    vec3 diffuse;   // �������������ɫ
    vec3 specular;  // ���ʾ��淴�����ɫ
    float shininess;// Ӱ�쾵��߹��ɢ��/�뾶
};

struct Light{
    vec3 position;   // �ƹ��λ��
    vec3 ambient;    // �������յ���ɫ
    vec3 diffuse;    // ���������ɫ
    vec3 specular;   // ���淴�����ɫ
};

in vec3 FragPos;
in vec3 Normal;

uniform vec3 viewPos;       // �����λ��
uniform Material material;
uniform Light light;

void main(){
    // ��������
    vec3 ambient = light.ambient * material.ambient;     // ���������ڲ�����,���������������ɫ
    
    // ���������
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);  // ����ָ���Դ������
    float diff = max(dot(norm, lightDir), 0.f);           // a*b = |a||b|cos(\theta)
    vec3 diffuse = light.diffuse * (diff * material.diffuse);  // �������Դ����ɫ*�������������ɫ*diff

    // ���淴��
    vec3 viewDir = normalize(viewPos - FragPos);   // ���嵽���������
    vec3 reflectDir = reflect(-lightDir, norm);    // ��������
    float spec = pow(max(dot(viewDir, reflectDir), 0.f), material.shininess);  // �������� �� ���嵽��������ļн�
    vec3 specular = light.specular * (spec * material.specular); // ���淴���Դ����ɫ*���ʾ��淴�����ɫ*spec

    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
}