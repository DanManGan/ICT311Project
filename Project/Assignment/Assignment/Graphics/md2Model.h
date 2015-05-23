
#ifndef MD2MODEL_H
#define MD2MODEL_H

#include "../AssetManagement/md2.h"

class md2Model : public md2
{
public:
	md2Model(char* name, md2Header *header, frame* frames,  
	      triangle* triangles, texCoord* texCoords, vertex* vertices);

	~md2Model();

	void Render();
};

#endif