#version 330 core
out vec4 FragColor;
in vec2 TexCoords;

uniform sampler2D texture1;

void main(){
    FragColor = texture(texture1, TexCoords);

    // FragColor = vec4(vec3(gl_FragCoord.z), 1.f);

    /// float far = 100.f;
    /// float near = 0.1f;
    /// float z = gl_FragCoord.z * 2.f - 1.f;
    /// /// (-(f + n) / (f - n) * ze - 2.f * f * n / (f - n)) / ze = zn
    /// /// ze = 2 * f * n / (f + n - zn * (f - n))
    /// float depth = 2.f * near * far / (far + near - z * (far - near));
    /// depth = depth / (far - near);
    /// FragColor = vec4(vec3(depth), 1.f);
}