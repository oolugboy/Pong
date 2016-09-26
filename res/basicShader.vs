#version 120

attribute vec3 position;

uniform mat4 transform1;
uniform mat4 transform2;
uniform mat4 transform3;
uniform mat4 transform;

uniform bool leftBool;
uniform bool rightBool;
uniform bool ballBool;

void main()
{
	if(leftBool == true)
	{
		gl_Position = transform1 * vec4(position, 1.0);
	}
	else if(rightBool == true)
	{
		gl_Position = transform2 * vec4(position, 1.0);
	}
	else if(ballBool == true)
	{
		gl_Position = transform3 * vec4(position, 1.0);
	}
}
