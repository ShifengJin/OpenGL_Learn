#version 330 core

out vec4 FragColor;

void main(){
    if(gl_FragCoord.x < 320 && gl_FragCoord.y < 240){  // gl_FragCoord µÄÊ¹ÓÃ
        FragColor = vec4(1.f, 0.f, 0.f, 1.f);
    }else if(gl_FragCoord.x < 320 && gl_FragCoord.y > 240){
        FragColor = vec4(0.f, 1.f, 0.f, 1.f);
    }else if(gl_FragCoord.x > 320 && gl_FragCoord.y < 240){
        FragColor = vec4(0.f, 0.f, 1.f, 1.f);
    }else{
        FragColor = vec4(0.1f, 0.2f, 0.3f, 1.f);
    }
}