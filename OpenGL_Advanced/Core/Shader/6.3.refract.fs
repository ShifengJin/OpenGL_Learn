#version 330 core

out vec4 FragColor;

in vec3 Normal;
in vec3 Position;

uniform vec3 cameraPos;
uniform samplerCube skybox;
void main(){
    // 1.      atmosphere      1.33   water
    // 1.309   ice             1.52   glass
    // 2.42    diamonds
    float ratio = 1.f / 1.52f;
    vec3 I = normalize(Position - cameraPos);
    vec3 R = refract(I, normalize(Normal), ratio);
    FragColor = vec4(texture(skybox, R).rgb, 1.f);
}
