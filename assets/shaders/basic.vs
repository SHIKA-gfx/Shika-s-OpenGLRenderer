#version 330 core
layout (location = 0) in vec3 aPos; // (loaction variable) 
layout (location = 1) in vec2 aTexCoord; // [New] Texture Coordinate variable 

out vec2 TexCoord; // output variable hand over to fragment shader

void main()
{
    gl_Position = vec4(aPos, 1.0);
    TexCoord = aTexCoord;
}