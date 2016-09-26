/*
 * shader.h
 *
 *  Created on: Sep 3, 2016
 *      Author: olujimi
 */

#ifndef SHADER_H_
#define SHADER_H_

#include <string>
#include <GL/glew.h>
#include "Transform.h"

using namespace std;

class Shader {
	public:
		Shader(const string & fileName);

		void Bind();
		void UpdateLeftPaddle(const Transform & transform1);
		void UpdateRightPaddle(const Transform & transform2);
		void UpdateBall(const Transform & transform3);
		virtual ~Shader();
	protected:
	private:
		string LoadShader(const std::string& fileName);
		static const unsigned int NUM_SHADERS = 2;
		/** Keep track of our uniform variables **/
		enum
		{
			LEFT_PADDLE,
			RIGHT_PADDLE,
			BALL,
			LEFT_BOOL,
			RIGHT_BOOL,
			BALL_BOOL,
			NUM_UNIFORMS
		};
	/** keep track of where the program is **/
		GLuint program;
	/** Now to store the 2 shaders **/
		GLuint shaders[NUM_SHADERS];
		GLuint uniforms[NUM_UNIFORMS];


};

#endif /* SHADER_H_ */



