#version 330 core
out vec4 FragColor;

in vec2 TexCoord; // Receive texture coordinates from vertex shader

uniform sampler2D ourTexture; // Texture sampler

void main()
{
    // texture function, fetch the color from the texture using the texture coordinates
    FragColor = texture(ourTexture, TexCoord);
}