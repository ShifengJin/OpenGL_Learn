#version 330 core
out vec4 FragColor;

in VS_OUT{
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
    vec4 FragPosLightSpace;
}fs_in;

uniform sampler2D diffuseTexture;
uniform sampler2D shadowMap;

uniform vec3 lightPos;
uniform vec3 viewPos;

float ShadowCalculation(vec4 fragPosLightSpace){
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    projCoords = projCoords * 0.5f + 0.5f;

    float closestDepth = texture(shadowMap, projCoords.xy).r;
    float currentDepth = projCoords.z;

    float shadow = currentDepth > closestDepth ? 1.f : 0.f;

    return shadow;
}

float ShadowCalculation1(vec4 fragPosLightSpace){
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    projCoords = projCoords * 0.5f + 0.5f;

    float closestDepth = texture(shadowMap, projCoords.xy).r;
    float currentDepth = projCoords.z;

    float bias = 0.005f;
    float shadow = currentDepth - bias > closestDepth ? 1.f : 0.f;

    return shadow;
}

float ShadowCalculation2(vec4 fragPosLightSpace, vec3 lightDir){
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    projCoords = projCoords * 0.5f + 0.5f;

    float closestDepth = texture(shadowMap, projCoords.xy).r;
    float currentDepth = projCoords.z;

    float bias = max(0.05f * (1.f - dot(fs_in.Normal, lightDir)), 0.005f);
    float shadow = currentDepth - bias > closestDepth ? 1.f : 0.f;

    return shadow;
}

float ShadowCalculation3(vec4 fragPosLightSpace, vec3 lightDir){
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    projCoords = projCoords * 0.5f + 0.5f;

    float closestDepth = texture(shadowMap, projCoords.xy).r;
    float currentDepth = projCoords.z;

    float bias = max(0.05f * (1.f - dot(fs_in.Normal, lightDir)), 0.005f);

    float shadow = 0.f;
    vec2 texelSize = 1.f / textureSize(shadowMap, 0);
    for(int x = -1; x <= 1; ++x){
        for(int y = -1; y <= 1; ++y){
            float pcfDepth = texture(shadowMap, projCoords.xy + vec2(x, y) * texelSize).r;
            shadow += currentDepth - bias > pcfDepth ? 1.f : 0.f;
        }
    }
    shadow /= 9.f;
    if(projCoords.z > 1.f)
        shadow = 0.f;
    return shadow;
}

void main(){
    vec3 color = texture(diffuseTexture, fs_in.TexCoords).rgb;
    vec3 normal = normalize(fs_in.Normal);

    vec3 lightColor = vec3(0.3);

    vec3 ambient = 0.6 * color;
    
    vec3 lightDir = normalize(lightPos - fs_in.FragPos);
    float diff = max(dot(lightDir, normal), 0.f);
    vec3 diffuse = diff * lightColor * 1.5f;

    vec3 viewDir = normalize(viewPos - fs_in.FragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = 0.f;
    vec3 halfwayDir = normalize(lightDir + viewDir);
    spec = pow(max(dot(normal, halfwayDir), 0.f), 64.f);
    vec3 specular = spec * lightColor;

    //float shadow = ShadowCalculation(fs_in.FragPosLightSpace);
    //float shadow = ShadowCalculation1(fs_in.FragPosLightSpace);
    //float shadow = ShadowCalculation2(fs_in.FragPosLightSpace, lightDir);
    float shadow = ShadowCalculation3(fs_in.FragPosLightSpace, lightDir);
    
    vec3 lighting = (ambient + (1.f - shadow) * (diffuse + specular)) * color;

    FragColor = vec4(lighting, 1.f);
}