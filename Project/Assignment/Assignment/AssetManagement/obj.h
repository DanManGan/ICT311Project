
#ifndef OBJ_H
#define OBJ_H

#include "Mesh.h"
#include "tiny_obj_loader.h"
#include "../Extras/Vector3D.h"

#include <vector>
#include <map>
#include <string>

/////////////////////////////////////////////////////////////////////
//
// Copyright 2012-2013, Syoyo Fujita.
//
// Licensed under 2-clause BSD liecense.
//
//typedef struct
//{
//    std::string name;
//
//    float ambient[3];
//    float diffuse[3];
//    float specular[3];
//    float transmittance[3];
//    float emission[3];
//    float shininess;
//    float ior;                // index of refraction
//    float dissolve;           // 1 == opaque; 0 == fully transparent
//    // illumination model (see http://www.fileformat.info/format/material/)
//    int illum;
//
//    std::string ambient_texname;
//    std::string diffuse_texname;
//    std::string specular_texname;
//    std::string normal_texname;
//    std::map<std::string, std::string> unknown_parameter;
//} material_t;
//
//typedef struct
//{
//    std::vector<float>          positions;
//    std::vector<float>          normals;
//    std::vector<float>          texcoords;
//    std::vector<unsigned int>   indices;
//    std::vector<int>            material_ids; // per-mesh material ID
//} mesh_t;
//
//typedef struct
//{
//    std::string  name;
//    mesh_t       mesh;
//} shape_t;

///////////////////////////////////////////////////////////////////

class obj : public Mesh
{

public:

	obj(char* name, std::vector<tinyobj::shape_t> shapes, 
			std::vector<tinyobj::material_t> mats, 
			std::vector<unsigned int> textures);

	~obj();

	void Animate(float deltaT) {};

	void SetAnimation(AnimationState state) {};

	bool SetSkin(unsigned int skin);

	bool SetScale(float scaleX, float scaleY, float scaleZ);

	float GetBase();

	float GetModelSpeed();

	virtual void Render(Vector3D position, float yaw) = 0;

	std::vector<tinyobj::shape_t> GetShapes();

protected:


	/** 
	  * @brief Vector of model shapes
	  * @warning None
	  * 
	  * Memeber vector for shapes used to build the model
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	std::vector<tinyobj::shape_t> m_shapes;

	/** 
	  * @brief Vector of model texturing details
	  * @warning None
	  * 
	  * Memeber vector for texture positions and material numbers
	  * the model uses for texturing
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
	std::vector<tinyobj::material_t> m_mats;

	/** 
	  * @brief Vector of model textures
	  * @warning None
	  * 
	  * Memeber vector for textures to be used in the model
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
	std::vector<unsigned int> m_textures;

	Vector3D m_scale;

};

#endif