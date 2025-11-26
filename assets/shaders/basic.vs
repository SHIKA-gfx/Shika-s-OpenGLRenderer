#version 330 core
layout (location = 0) in vec3 aPos; // (loaction variable) 
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord; // output variable hand over to fragment shader

// [NEW] uniform variables to recieve Transformation Matrix
uniform mat4 transform;

void main()
{
    // location vector(vec4) * Tranformation Matrix(mat4) = move, rotate location
    // sequnce is Important : Matrix * vector
    gl_Position = transform * vec4(aPos, 1.0);
    TexCoord = aTexCoord;
}