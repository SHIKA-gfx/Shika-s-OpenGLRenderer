#version 330 core
out vec4 FragColor;

in vec3 Normal; // Normal came from vertex shader
in vec3 FragPos; // World coordinates came from vertex shader

uniform vec3 lightPos; // light position
uniform vec3 viewPos; // camera position (for calculates Specular)
uniform vec3 objectColor; // Color of the object
uniform vec3 lightColor;  // Color of the light source

void main()
{
    // 1. Ambient
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    // 2. Diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos); // Direction of light
    // calculates angle of light and normal for Dot Product
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // 3. Specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos); // view direction
    vec3 reflectDir = reflect(-lightDir, norm); // reflect direction
    // The brighter the viewing and reflection directions are same(32 is Shininess)
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    // result color
    vec3 result = (ambient + diffuse + specular) * objectColor;
    FragColor = vec4(result, 1.0);
}