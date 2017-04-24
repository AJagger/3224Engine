#include "Mesh.h"

Mesh::Mesh(void)
{
	for (int i = 0; i < MAX_BUFFER; i++) {
		bufferObject[i] = 0;
	}
	glGenVertexArrays(1, &arrayObject);

	numVertices = 0;
	vertices = NULL;
	colours = NULL;
	type = GL_TRIANGLES;
	//texture = 0;
	textureCoords = NULL;
}


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &arrayObject);
	glDeleteBuffers(MAX_BUFFER, bufferObject);
	//glDeleteTextures(1, &texture);
	delete[] textureCoords;
	delete[] vertices;
	delete[] colours;
}

void Mesh::Draw(GLuint texture)
{
	glBindTexture(GL_TEXTURE_2D, texture);
	glBindVertexArray(arrayObject);
	glDrawArrays(type, 0, numVertices);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

//Generates a triangle for testing purposes
Mesh * Mesh::GenerateTriangle()
{
	Mesh*m = new Mesh();
	m->numVertices = 3;

	m->vertices = new Vector3[m->numVertices];
	m->vertices[0] = Vector3(0.0f, 0.5f, 0.0f);
	m->vertices[1] = Vector3(0.5f, -0.5f, 0.0f);
	m->vertices[2] = Vector3(-0.5f, -0.5f, 0.0f);

	m->textureCoords = new Vector2[m->numVertices];
	m->textureCoords[0] = Vector2(0.5f, 0.0f);
	m->textureCoords[1] = Vector2(1.0f, 1.0f);
	m->textureCoords[2] = Vector2(0.0f, 1.0f);

	m->colours = new Vector4[m->numVertices];
	m->colours[0] = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
	m->colours[1] = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
	m->colours[2] = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

	m->BufferData();

	return m;
}

Mesh * Mesh::GenerateTriangleStrip()
{
	Mesh*m = new Mesh();
	m->numVertices = 4;
	m->type = GL_TRIANGLE_STRIP;

	m->vertices = new Vector3[m->numVertices];
	m->vertices[0] = Vector3(0.0f, 0.0f, 0.0f);
	m->vertices[1] = Vector3(0.0f, 0.5f, 0.0f);
	m->vertices[2] = Vector3(0.5f, 0.0f, 0.0f);
	m->vertices[3] = Vector3(0.5f, 0.5f, 0.0f);

	m->colours = new Vector4[m->numVertices];
	m->colours[0] = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
	m->colours[1] = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
	m->colours[2] = Vector4(0.0f, 0.0f, 1.0f, 1.0f);
	m->colours[3] = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

	m->BufferData();

	return m;
}

Mesh * Mesh::LoadMeshFile(const string & fileName)
{
	ifstream f(fileName);

	if (!f) {
		return nullptr;
	}

	Mesh*m = new Mesh();
	m->type = GL_TRIANGLE_STRIP;
	f >> m->numVertices;

	int hasTex = 0;
	int hasColour = 0;

	f >> hasTex;
	f >> hasColour;

	m->vertices = new Vector3[m->numVertices];
	m->textureCoords = new Vector2[m->numVertices];
	m->colours = new Vector4[m->numVertices];

	float x, y, z;

	for (int i = 0; i < m->numVertices; ++i) {
		//f >> m->vertices[i].x;
		//f >> m->vertices[i].y;
		//f >> m->vertices[i].z;
		f >> x;
		f >> y;
		f >> z;

		m->vertices[i] = Vector3(x , y , z );
	}
	if (hasColour) {
		for (int i = 0; i < m->numVertices; ++i) {
			f >> m->colours[i].x;
			f >> m->colours[i].y;
			f >> m->colours[i].z;
			f >> m->colours[i].w;
		}
	}

	if (hasTex) {
		for (int i = 0; i < m->numVertices; ++i) {
			//f >> m->textureCoords[i].x;
			//f >> m->textureCoords[i].y;
			f >> x;
			f >> y;
			m->textureCoords[i] = Vector2(x, y);
		}
	}

	m->BufferData();

	return m;
}

void Mesh::BufferData()
{
	glBindVertexArray(arrayObject);
	glGenBuffers(1, &bufferObject[VERTEX_BUFFER]);
	glBindBuffer(GL_ARRAY_BUFFER, bufferObject[VERTEX_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(Vector3), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(VERTEX_BUFFER, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(VERTEX_BUFFER);

	if(textureCoords)
	{
		glGenBuffers(1, &bufferObject[TEXTURE_BUFFER]);
		glBindBuffer(GL_ARRAY_BUFFER, bufferObject[TEXTURE_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(Vector2), textureCoords, GL_STATIC_DRAW);
		glVertexAttribPointer(TEXTURE_BUFFER, 2, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(TEXTURE_BUFFER);
	}

	if (colours) 
	{
		glGenBuffers(1, &bufferObject[COLOUR_BUFFER]);
		glBindBuffer(GL_ARRAY_BUFFER, bufferObject[COLOUR_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(Vector4), colours, GL_STATIC_DRAW);
		glVertexAttribPointer(COLOUR_BUFFER, 4, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(COLOUR_BUFFER);
	}
	
	glBindVertexArray(0);
}
