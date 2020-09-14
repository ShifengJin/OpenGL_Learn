#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D screenTexture;

void main(){
    vec3 col = texture(screenTexture, TexCoords).rgb;
    float grayscale = 0.2126f * col.r + 0.7152f * col.g + 0.0722 * col.b;
    FragColor = vec4(vec3(grayscale), 1.f);
}