/*
 * main.cpp

 *
 *  Created on: Aug 29, 2016
 *      Author: olujimi
 */
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include "display.h"
#include "mesh.h"
#include "Transform.h"
#include "Shader.h"

using namespace std;

int main()
{
	Display disp = Display(700, 700, "Jimi's Pong window");

	/** Mesh for left paddle **/
	Vertex leftPaddle[] ={
			Vertex(glm::vec3(-0.75f, 0.80f, 0.0f)),Vertex(glm::vec3(-0.7f, 0.80f,0.0f)),
			Vertex(glm::vec3(-0.75f, 0.85f, 0.0f)),Vertex(glm::vec3(-0.7f, 0.85f, 0.0f)),
			Vertex(glm::vec3(-0.75f, 0.90f, 0.0f)),Vertex(glm::vec3(-0.7f, 0.90f, 0.0f)),
			Vertex(glm::vec3(-0.75f, 0.95f, 0.0f)),Vertex(glm::vec3(-0.7f, 0.95f, 0.0f)),
			Vertex(glm::vec3(-0.75f, 1.00f, 0.0f)),Vertex(glm::vec3(-0.7f, 1.00f, 0.0f))
	};
	/** The indices to specify the order of the vertices to draw **/
	unsigned int indices[] = {0,1,3,0,3,2,2,3,5,2,5,4,4,5,7,4,7,6,6,7,9,6,9,8};


	/** Mesh for the right paddle **/
	Vertex rightPaddle[] ={
			Vertex(glm::vec3( 0.70f, 0.80f, 0.0f)),Vertex(glm::vec3(0.75f, 0.80f,0.0f)),
			Vertex(glm::vec3( 0.70f, 0.85f, 0.0f)),Vertex(glm::vec3(0.75f, 0.85f, 0.0f)),
			Vertex(glm::vec3( 0.70f, 0.90f, 0.0f)),Vertex(glm::vec3(0.75f, 0.90f, 0.0f)),
			Vertex(glm::vec3( 0.70f, 0.95f, 0.0f)),Vertex(glm::vec3(0.75f, 0.95f, 0.0f)),
			Vertex(glm::vec3( 0.70f, 1.00f, 0.0f)),Vertex(glm::vec3(0.75f, 1.00f, 0.0f))
	};
	/** The indices to specify the order of the vertices to draw **/
	unsigned int indices2[] = {0,1,3,0,3,2,2,3,5,2,5,4,4,5,7,4,7,6,6,7,9,6,9,8};

	Vertex ballVertices[] = {
			Vertex(glm::vec3(-0.025f, 0.875f, 0.0f)), Vertex(glm::vec3(0.025f, 0.875, 0.0f)),
			Vertex(glm::vec3(-0.025f, 0.925, 0.0f)), Vertex(glm::vec3(0.025f, 0.925, 0.0f))
	};
	/** The indices for the ball **/
	unsigned int  indices3[] = {0,2,3,0,3,1};

	Mesh leftPaddleMesh = Mesh(leftPaddle, 10, indices, 24);
	GameObject leftP = GameObject(leftPaddleMesh);
	Mesh rightPaddleMesh = Mesh(rightPaddle, 10, indices2, 24);
	GameObject rightP = GameObject(rightPaddleMesh);
	Mesh ballMesh = Mesh(ballVertices, 4, indices3, 6);
	GameObject ball = GameObject(ballMesh);


    Shader shader("./res/basicShader");

    /** Now to test the display **/
	while(!(disp.getClosed()))
    {
    	disp.clear(0.0f, 0.0f, 0.0f,1);
    	shader.Bind();
    	disp.updatePosition(shader, leftP, rightP, ball);
        disp.update();
    }
    return 0;
}




