
#ifndef MODEL_H
#define MODEL_H

#include "GameObject.h"
#include "../AssetManagement/Mesh.h"

class Model : public GameObject
{
public:
	Model();

	Model(char* name, float xPos, 
				float yPos, float zPos);

	~Model();

	CLASS_TYPE(MODEL);

	void Animate(float deltaT) {};
	void SetAnimation(AnimationState state){};
	void Render();



private:

};

#endif
