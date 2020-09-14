#version 330 core

out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D screenTexture;

void main(){
    // vec3 col = texture(screenTexture, TexCoords).rgb;
    // FragColor = vec4(col, 1.f);

    // FragColor = vec4(1.f - col, 1.f);

    // float average = (col.r + col.g + col.b) / 3.0;
    // FragColor = vec4(average, average, average, 1.0);

    // float average = 0.2126 * col.r + 0.7152 * col.g + 0.0722 * col.b;
    // FragColor = vec4(average, average, average, 1.0);


    const float offset = 1.f / 640.f;
    vec2 offsets[9] = vec2[](
        vec2(-offset,  offset), // 左上
        vec2( 0.0f,    offset), // 正上
        vec2( offset,  offset), // 右上
        vec2(-offset,  0.0f),   // 左
        vec2( 0.0f,    0.0f),   // 中
        vec2( offset,  0.0f),   // 右
        vec2(-offset, -offset), // 左下
        vec2( 0.0f,   -offset), // 正下
        vec2( offset, -offset)  // 右下
    );

    // float kernel[9] = float[](
    //     -1, -1, -1,
    //     -1,  9, -1,
    //     -1, -1, -1
    // );
    // float kernel[9] = float[](
    //     1.0 / 16, 2.0 / 16, 1.0 / 16,
    //     2.0 / 16, 4.0 / 16, 2.0 / 16,
    //     1.0 / 16, 2.0 / 16, 1.0 / 16  
    // );
    float kernel[9] = float[](
        1.f,  1.f, 1.f,
        1.f, -8.f, 1.f,
        1.f,  1.f, 1.f
    );
    
    vec3 sampleTex[9];
    for(int i = 0; i < 9; i++)
    {
        sampleTex[i] = vec3(texture(screenTexture, TexCoords.xy + offsets[i]));
    }
    vec3 col = vec3(0.0);
    for(int i = 0; i < 9; i++)
        col += sampleTex[i] * kernel[i];
    FragColor = vec4(col, 1.0);
}