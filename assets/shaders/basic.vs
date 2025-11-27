#version 330 core
layout (location = 0) in vec3 aPos; // (loaction variable) 
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord; // output variable hand over to fragment shader

// [NEW] MVP Matrix
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    // sequnce is Important : Projection * View * Model * Location
    gl_Position = projection * view * model * vec4(Pos, 1.0);
    TexCoord = aTexCoord;
}