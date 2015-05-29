
#ifndef OBJMODEL_H
#define OBJMODEL_H

#include "../AssetManagement/obj.h"
#include "../Extras/Vector3D.h"

#include <vector>

class objModel : public obj
{
public:
	objModel(char* name, std::vector<tinyobj::shape_t> shapes, 
				std::vector<tinyobj::material_t> m_mats,
				std::vector<unsigned int> textures);

	~objModel();

	void Render(Vector3D position, float yaw);


};

#endif