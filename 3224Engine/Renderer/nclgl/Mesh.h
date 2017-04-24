#pragma once
#include "OGLRenderer.h"
#include "../nclgl/ChunkGenerator.h"
#include <string>
#include <fstream>

using std::ifstream;
using std::string;

enum MeshBuffer {
	VERTEX_BUFFER, COLOUR_BUFFER, TEXTURE_BUFFER, MAX_BUFFER
};

class Mesh
{
public:
	Mesh(void);
	~Mesh(void);

	virtual void Draw(GLuint texture = 0);
	static Mesh* GenerateTriangle();
	static Mesh* GenerateTriangleStrip();
	static Mesh* Mesh::LoadMeshFile(const string &fileName);

protected:
	void BufferData();

	GLuint arrayObject;
	GLuint bufferObject[MAX_BUFFER];
	GLuint numVertices;
	GLuint type;

	Vector3* vertices;
	Vector4* colours;

	Vector2* textureCoords;
};

