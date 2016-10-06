/*
 * mesh.h
 *
 *  Created on: Aug 31, 2016
 *      Author: olujimi
 */
#ifndef MESH_H
#define MESH_H

/** openGL math library to represent the vertices **/
#include <glm/glm.hpp>
/** for the openGL functions **/
#include <GL/glew.h>
#include <string>
#include "obj_loader.h"

using namespace std;


/** To make our data a little nicer for openGL to work with **/
class Vertex
{
    public:

        Vertex(const glm::vec3& pos, const glm::vec2 texCoord, const glm::vec3& normal = glm::vec3(0,0,0))
        {
            this->pos = pos;
            this->texCoord = texCoord;
            this->normal = normal;
        }
        /** Dummy constructor for the tetris game **/
        Vertex(const glm::vec3& pos)
        {
        	this->pos = pos;
        }
        /** Empty constructor for the array **/
        Vertex(){}

        glm::vec3 getPos(){ return pos; }
        glm::vec2 getTextCoord(){ return texCoord; }
        glm::vec3 getNormal(){ return normal; }

    protected:
    private:
        glm::vec3 pos;
        glm::vec2 texCoord;
        glm::vec3 normal;
};

class Mesh
{
    public:
	 	Mesh(const string & fileName);
        Mesh(Vertex * vertices, unsigned int numVertices, unsigned int * indices,
        		unsigned int numIndices);
        Mesh(){}
        void draw();
        virtual ~Mesh();
    protected:
    private:

        void InitMesh(const IndexedModel & model);
        enum
        {
            POSITION_VB,
            POSITION_TC,
            NORMAL_VB,
            INDEX_VB,
            NUM_BUFFERS
        };

        /** Data on the GPU?? **/
        GLuint vertexArrayObject;
        GLuint vertexArrayBuffers[NUM_BUFFERS];
        unsigned int drawCount;
};
class GameObject
{
public:
	GameObject(Mesh & mesh)
	{
		this->mesh = mesh;
		this->velocityX = 0;
		this->velocityY = 0;
	}
	Mesh & getMesh(){ return this->mesh; }
	double & getVelocityX() { return this->velocityX; }
	double & getVelocityY() { return this->velocityY; }
private:
	Mesh mesh;
	double velocityX;
	double velocityY;
};

#endif // MESH_H




