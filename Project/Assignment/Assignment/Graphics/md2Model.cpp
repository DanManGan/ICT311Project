
#include "md2Model.h"
#include "../Graphics/ViewOpenGL.h"
#include "../Singletons.h"

md2Model::md2Model(char* name, md2Header *header, frame* frames,  
	      triangle* triangles, texCoord* texCoords, vertex* vertices) :
	md2(name, header, frames,  
	      triangles, texCoords, vertices)
{
}

md2Model::~md2Model()
{

}


void md2Model::Render(Vector3D position, float yaw)
{
	Vector3D v1,v2,v3;

	graphics->PushMatrix();
		graphics->LightOn(GL_LIGHT0);
		graphics->Translate(position.x, position.y, position.z);
		graphics->Rotate(-yaw, 0.0f, 1.0f, 0.0f);

		if(m_skinID) {
			graphics->Tex2DOn(m_skinID);
		}

		//graphics->Scale(m_scale.x, m_scale.y, m_scale.z);
		graphics->Begin(GL_TRIANGLES);

		for(int i = 0; i < m_header->numTriangles; i++) {
			v1.Set(m_vertices[m_triangles[i].vertIndices[0]].x,
			m_vertices[m_triangles[i].vertIndices[0]].y,
			m_vertices[m_triangles[i].vertIndices[0]].z);
			v2.Set(m_vertices[m_triangles[i].vertIndices[1]].x,
			m_vertices[m_triangles[i].vertIndices[1]].y,
			m_vertices[m_triangles[i].vertIndices[1]].z);
			v3.Set(m_vertices[m_triangles[i].vertIndices[2]].x,
			m_vertices[m_triangles[i].vertIndices[2]].y,
			m_vertices[m_triangles[i].vertIndices[2]].z);

			Vector3D n1=calculateTriangleNormal(v1,v2,v3);

			graphics->Normals(n1.x,n1.y,n1.z);

			if(m_skinID) {
				graphics->TexCoords(m_texCoords[m_triangles[i].texIndices[0]].tex);	
			}
			graphics->Vertex(v1.x,v1.y,v1.z);

			if(m_skinID) {
				graphics->TexCoords(m_texCoords[m_triangles[i].texIndices[1]].tex);	
			}
			graphics->Vertex(v2.x,v2.y,v2.z);

			if(m_skinID) {
				graphics->TexCoords(m_texCoords[m_triangles[i].texIndices[2]].tex);		
			}
			graphics->Vertex(v3.x,v3.y,v3.z);  
		}  

		graphics->End();	
		graphics->Tex2DOff();
		
		graphics->LightOff(GL_LIGHT0);
	graphics->PopMatrix();
}

//void md2Model::Render()
//{
//		
//	unsigned int frameNum = 0;
//
//	Vector3D v1,v2,v3;
//
//	  if(m_skinID)
//		  graphics->Tex2DOn(m_skinID);
//
//	graphics->Scale(m_scale.x, m_scale.y, m_scale.z);
//	graphics->Begin(GL_TRIANGLES);
//
//	for(int i = 0; i < m_header->numTriangles; i++)
//	{
//		v1.Set(m_frames[frameNum].vertices[m_triangles[i].vertIndices[0]].x,
//		    m_frames[frameNum].vertices[m_triangles[i].vertIndices[0]].y,
//			m_frames[frameNum].vertices[m_triangles[i].vertIndices[0]].z);
//		v2.Set(m_frames[frameNum].vertices[m_triangles[i].vertIndices[1]].x,
//		    m_frames[frameNum].vertices[m_triangles[i].vertIndices[1]].y,
//			m_frames[frameNum].vertices[m_triangles[i].vertIndices[1]].z);
//		v3.Set(m_frames[frameNum].vertices[m_triangles[i].vertIndices[2]].x,
//		    m_frames[frameNum].vertices[m_triangles[i].vertIndices[2]].y,
//			m_frames[frameNum].vertices[m_triangles[i].vertIndices[2]].z);
//		Vector3D n1=calculateTriangleNormal(v1,v2,v3);
//
//		graphics->Normals(n1.x,n1.y,n1.z);
//
//		if(m_skinID)
//			graphics->TexCoords(m_texCoords[m_triangles[i].texIndices[0]].tex);		       
//		graphics->Vertex(v1.x,v1.y,v1.z);
//
//		if(m_skinID)
//			graphics->TexCoords(m_texCoords[m_triangles[i].texIndices[1]].tex);		  
//		graphics->Vertex(v2.x,v2.y,v2.z);
//
//		if(m_skinID)
//			graphics->TexCoords(m_texCoords[m_triangles[i].texIndices[2]].tex);		  
//		graphics->Vertex(v3.x,v3.y,v3.z);  
//	}  
//
//	graphics->End();	
//	graphics->Tex2DOff();
//}