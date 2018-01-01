#include "draw.h"

using std::vector;


int createRod(GLfloat hor_step, GLfloat ver_step, 
			  GLuint &vao)
{
	vector<GLfloat> vertices;
	GLfloat h = -0.2f, 
			w = -0.9f;

	int dot_num = 0;

	while (h < 0.2f)
	{
		while (w < 0.9f)
		{
			vertices.push_back(w);
			vertices.push_back(h);
			vertices.push_back(0.0f);

			w += hor_step;
			dot_num++;
		}

		h += ver_step; 
	}

	GLuint vbo_vertices;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo_vertices);

	glBindVertexArray(vao);

	{
		glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * 
					 sizeof(GL_FLOAT), &vertices[0], 
					 GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 
							  3 * sizeof(GL_FLOAT), 
							  (GLvoid *) 0);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	glBindVertexArray(0);
	
	return dot_num;
}
