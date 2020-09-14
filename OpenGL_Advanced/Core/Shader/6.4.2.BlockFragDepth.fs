#version 330 core
out vec4 FragColor;

in VS_OUT{
    vec2 TexCoords;
}fs_in;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform sampler2D texture3;
uniform sampler2D texture4;

void main(){
    //gl_FrontFacing
    if(gl_FragCoord.x < 320.f && gl_FragCoord.y < 240.f){
        if(gl_FrontFacing){
            FragColor = texture(texture1, fs_in.TexCoords);
        }else{
            FragColor = texture(texture2, fs_in.TexCoords);
        }
    }else if(gl_FragCoord.x < 320.f && gl_FragCoord.y >= 240.f){
        if(gl_FrontFacing){
            FragColor = texture(texture2, fs_in.TexCoords);
        }else{
            FragColor = texture(texture3, fs_in.TexCoords);
        }
    }else if(gl_FragCoord.x > 320.f && gl_FragCoord.y < 240.f){
        if(gl_FrontFacing){
            FragColor = texture(texture3, fs_in.TexCoords);
        }else{
            FragColor = texture(texture4, fs_in.TexCoords);
        }
    }else if(gl_FragCoord.x > 320.f && gl_FragCoord.y >= 240.f){
        if(gl_FrontFacing){
            FragColor = texture(texture4, fs_in.TexCoords);
        }else{
            FragColor = texture(texture1, fs_in.TexCoords);
        }
    }
}
