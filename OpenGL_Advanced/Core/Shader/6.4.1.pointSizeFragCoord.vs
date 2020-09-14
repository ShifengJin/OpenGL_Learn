#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 view;
uniform mat4 model;
uniform mat4 projection;

void main(){
    gl_Position = projection * view * model * vec4(aPos, 1.f);

    if(gl_VertexID == 4){ // gl_VertexID 的使用
        gl_PointSize = 10.f; // gl_PointSize 的使用
    }else{
        gl_PointSize = 5.f;
    }
}
