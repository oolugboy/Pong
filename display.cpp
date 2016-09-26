/*
 * display.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: olujimi
 */
#include "display.h"
#include "Transform.h"
#include "Shader.h"
#include <iostream>
#include <string>

using namespace std;
/** We are using SDL2 to create the window **/

/** need arguments to specify the dimensions of the window **/
Display::Display(int height, int width, const string & title)
{
    /** Okay we initialize SDL **/
    SDL_Init(SDL_INIT_EVERYTHING);
    /** Because we are doing SDL using OpenGL, we can use some additional parameters **/
    /** firstly to be able to get all the possible colors we need **/
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    /** This specifies how transparent the colors will be **/
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    /** Now to set the buffer size for every pixel **/
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);/** 32 because we need all the color data for each pixel **/
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    /** allocate space for the second buffer **/
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    /** Now to initialize our window **/
    currWind = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

    /** Now to create the context **/
    currContext = SDL_GL_CreateContext(currWind);

    /** Now to use the openGL library **/
    GLenum status = glewInit();

    if(status != GLEW_OK)
    {
        cerr << " Glew did not initialize " << endl;
    }
    isClosed = false;

}
Display::~Display()
{
    /** Then we are deallocating everything **/
    /** firstly we deallocate the context **/
    SDL_GL_DeleteContext(currContext);
    /** We then deallocate the window **/
    SDL_DestroyWindow(currWind);

    SDL_Quit();
    //dtor
}
double leftPaddleY = 0, rightPaddleY = 0, ballX = 0, ballY = 0;
bool goLeft = false, goRight = true;
void Display::updatePosition(Shader & shader, Mesh & leftP, Mesh & rightP, Mesh & ball)
{
	Transform transform1, transform2, transform3;
	transform1.getPos().y = leftPaddleY;
	shader.UpdateLeftPaddle(transform1);
	leftP.draw();

	transform2.getPos().y = rightPaddleY;
	shader.UpdateRightPaddle(transform2);
	rightP.draw();

	transform3.getPos().x = ballX;
	shader.UpdateBall(transform3);
	ball.draw();

	if(transform3.getPos().x > 0.95)
	{
		goRight = false;
		goLeft = true;
	}
	if(transform3.getPos().x < -0.95)
	{
		goLeft = false;
		goRight = true;
	}
}

void Display::update()
{
	SDL_GL_SwapWindow(currWind);
	/** The ball has to constantly be in motion **/
	if(goLeft)
		ballX -= 0.01;
	else
		ballX += 0.01;

	/** receive and handle all the events that the operating system throws **/
	SDL_Event e;
	while(SDL_PollEvent(&e))
	{
		if(e.type == SDL_QUIT)
		{
			isClosed = true;
		}
		else
		{
			if(e.type == SDL_KEYDOWN)
			{
				/** Time to find out which key was pressed **/
				switch(e.key.keysym.sym )
				{
				case SDLK_UP:
					rightPaddleY += 0.05;
					cout << " The right up button was pressed " << endl;
					break;
				case SDLK_DOWN:
					rightPaddleY -= 0.05;
					cout << " The right down button was pressed " << endl;
					break;
				case SDLK_w:
					leftPaddleY += 0.05;
					cout << " The left up button was pressed " << endl;
					break;
				case SDLK_s:
					leftPaddleY -= 0.05;
					cout << " The left down button was pressed " << endl;
					break;
				default:
					cout << " I do not know what key you pressed " << endl;
				}
			}
		}
	}
}
bool Display::getClosed()
{
    return isClosed;
}
void Display::clear(float r, float g, float b, float a)
{
	glClearColor(r,g,b,a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}



