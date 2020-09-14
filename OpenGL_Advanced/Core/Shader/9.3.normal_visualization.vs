#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out VS_OUT{
    vec3 normal;
}vs_out;

uniform mat4 view;
uniform mat4 model;

void main(){
    mat3 normalMatrix = mat3(view * model);
    vs_out.normal = vec3(vec4(normalMatrix * aNormal, 0.f));
    gl_Position = view * model * vec4(aPos, 1.f);
}