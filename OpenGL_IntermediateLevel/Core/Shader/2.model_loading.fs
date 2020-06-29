#version 330 core

out vec4 FragColor;

struct DirLight{
    vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;
uniform sampler2D texture_normal1;

uniform vec3 viewPos;
uniform DirLight dirLight;

void main(){
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);

    vec3 lightDir = normalize(-dirLight.direction);
    float diff = max(dot(norm, lightDir), 0.f);

    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.f), 32.f);

    vec3 ambient = dirLight.ambient * vec3(texture(texture_diffuse1, TexCoords));
    vec3 diffuse = dirLight.diffuse * diff * vec3(texture(texture_diffuse1, TexCoords));
    vec3 specular = dirLight.specular * spec * vec3(texture(texture_specular1, TexCoords));

    FragColor = vec4(ambient + diffuse + specular, 1.f);
    // FragColor = vec4(ambient, 1.f);
    // FragColor = vec4(diffuse, 1.f);
    // FragColor = vec4(specular, 1.f);
}
