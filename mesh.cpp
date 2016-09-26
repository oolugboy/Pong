/*
 * mesh.cpp
 *
 *  Created on: Aug 31, 2016
 *      Author: olujimi
 */
/*
 * mesh.cpp
 *
 *  Created on: Jun 29, 2016
 *      Author: olujimi
 */
#include "mesh.h"
#include <vector>
#include <iostream>
#include "obj_loader.h"
using namespace std;

Mesh::Mesh(const string & fileName)
{
	IndexedModel model = OBJModel(fileName).ToIndexedModel();
	InitMesh(model);
}

Mesh::Mesh(Vertex * vertices, unsigned int numVertices, unsigned int * indices,
		unsigned int numIndices)
{
	IndexedModel model;
	for(unsigned int i = 0; i < numVertices; i++)
	{
		model.positions.push_back(vertices[i].getPos());
		model.texCoords.push_back(vertices[i].getTextCoord());
		model.normals.push_back(vertices[i].getNormal());
	}
	for(unsigned int i = 0; i < numIndices; i++)
	{
		model.indices.push_back(indices[i]);
		cout << " The index " << indices[i] << endl;
	}
	InitMesh(model);
}


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &vertexArrayObject);
}
/** The method that is supposed to draw up our mesh **/
void Mesh::draw()
{
	glBindVertexArray(vertexArrayObject);
	glDrawElements(GL_TRIANGLES,drawCount,GL_UNSIGNED_INT,0);
	glBindVertexArray(0);
}
void Mesh::InitMesh(const IndexedModel & model)
{
	drawCount = model.indices.size();
	/** Generate the VAO to store the state of the buffers and the attribute **/
	glGenVertexArrays(1,&vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	/** The generate the vertex buffer **/
	glGenBuffers(NUM_BUFFERS, vertexArrayBuffers);

	cerr << " The amount of buffers " << NUM_BUFFERS << endl;

	/** We have now buffered the positons data **/
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(model.positions[0]), &(model.positions[0]), GL_STATIC_DRAW);

	/** This would be a sequence of positions **/
	glEnableVertexAttribArray(0);
	/** Now to specify how openGL should get all the position attributes **/
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	/** Now to buffer data for the textcoords **/
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[POSITION_TC]);
	glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(model.texCoords[0]), &(model.texCoords[0]), GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	/** We have now buffered the positons data **/
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[NORMAL_VB]);
	glBufferData(GL_ARRAY_BUFFER, model.normals.size() * sizeof(model.normals[0]), &(model.normals[0]), GL_STATIC_DRAW);

	/** This would be a sequence of positions **/
	glEnableVertexAttribArray(2);
	/** Now to specify how openGL should get all the position attributes **/
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

	/** We have now buffered the indices data **/
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertexArrayBuffers[INDEX_VB]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size() * sizeof(model.indices[0]), &(model.indices[0]), GL_STATIC_DRAW);

	/** Unbind the vertex array */
	glBindVertexArray(0);

}




