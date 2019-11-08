#include "ComponentMesh.h"
#include "GameObject.h"
#include "Glew/include/glew.h"
#include "Application.h"
#include "ComponentTexture.h"
#include "ComponentTransform.h"
#include "ComponentMesh.h"



ComponentMesh::ComponentMesh(GameObject* parent) : Component(parent, CompMesh)
{
	parent->components.push_back(this);
}


ComponentMesh::~ComponentMesh()
{
}

void ComponentMesh::Inspector()
{
	if (ImGui::CollapsingHeader("Mesh", ImGuiTreeNodeFlags_DefaultOpen))
	{
		ImGui::Text("Number of vertices: %u", mesh->vertex.size);
		ImGui::Text("Number of faces: %u", mesh->index.size / 3);

		ImGui::Checkbox("Vertex normals", &printVertexNormals);
	}
}

void ComponentMesh::Draw()
{
	ComponentTransform* transform = gameObject->transform;
	glPushMatrix();
	float4x4 mat = transform->GetMatrixOGL();

	glMultMatrixf(mat.ptr());

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertex.id);
	glVertexPointer(3, GL_FLOAT, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->index.id);

	if (gameObject)
	{
		ComponentTexture* tex = (ComponentTexture*)gameObject->GetComponent(CompTexture);
		if (tex)
		{
			if (tex->print)
			{
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, tex->GetID());
			}
		}

		if (printVertexNormals && mesh->hasNormals)
		{
			int size = 2;
			glColor3f(0.0f, 1.0f, 0.0f);

			for (uint i = 0; i < mesh->vertex.size * 3; i += 3)
			{
				glBegin(GL_LINES);
				glVertex3f(mesh->vertex.data[i], mesh->vertex.data[i + 1], mesh->vertex.data[i + 2]);
				glVertex3f(mesh->vertex.data[i] + mesh->normals.data[i] * size, mesh->vertex.data[i + 1] + mesh->normals.data[i + 1] * size, mesh->vertex.data[i + 2] + mesh->normals.data[i + 2] * size);
				glEnd();
			}
			glColor3f(1.0f, 1.0f, 1.0f);
		}
	}

	glBindBuffer(GL_ARRAY_BUFFER, mesh->uvs.id);
	glTexCoordPointer(2, GL_FLOAT, 0, NULL);

	glDrawElements(GL_TRIANGLES, mesh->index.size, GL_UNSIGNED_INT, NULL);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}
