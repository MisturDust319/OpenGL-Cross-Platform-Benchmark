#version 330 core

// position variable
layout (location = 0) in vec3 aPos;

// transform matrices
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main()
{
	gl_Position = projection * view * model * vec4(aPos, 1.0);
}