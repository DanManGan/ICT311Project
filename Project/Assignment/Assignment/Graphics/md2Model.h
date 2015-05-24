
#ifndef MD2MODEL_H
#define MD2MODEL_H

#include "../AssetManagement/md2.h"
#include "../Extras/Vector3D.h"

class md2Model : public md2//, public GameObject
{
public:
	md2Model(char* name, md2Header *header, frame* frames,  
	      triangle* triangles, texCoord* texCoords, vertex* vertices);

	~md2Model();

	void Render(Vector3D position, float yaw);

private:

};

#endif