#ifndef NPC_H
#define NPC_H

#include "GameObject.h"

class NPC :public GameObject
{
public:
	NPC();

	NPC(char* objectName, float xPos, 
			float yPos, float zPos);

	void Initialise();
	void Update(float deltaT);
	void SetAnimation(unsigned short startFrame, unsigned short endFrame);

	void Render();

protected:
private:
	int m_Health;
};

#endif