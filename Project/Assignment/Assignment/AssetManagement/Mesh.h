
#ifndef MESH_H
#define MESH_H

#include "GameAsset.h"
#include "../Extras/Vector3D.h"

enum AnimationState
{
   STAND = 0,
    RUN,
    ATTACK,
    PAIN_A,
    PAIN_B,
    PAIN_C,
    JUMP,
    FLIP,
    SALUTE,
    FALLBACK,
    WAVE,
    POINT_AT,
    CROUCH_STAND,
    CROUCH_WALK,
    CROUCH_ATTACK,
    CROUCH_PAIN,
    CROUCH_DEATH,
    DEATH_FALLBACK,
    DEATH_FALLFORWARD,
    DEATH_FALLBACKSLOW,
    BOOM
};

enum Animate
{
	START_FRAME = 0,
	END_FRAME,
	ANIMATION_SPEED,
	MODEL_SPEED
};


enum MeshType 
{
	MD2 = 0,
	OBJ
};

class Mesh : public GameAsset
{
public:

	Mesh();

	Mesh(char* name);

	~Mesh();

	virtual void Render(Vector3D position, float yaw) = 0;

	virtual void Animate(float deltaT) = 0;

	virtual void SetAnimation(AnimationState state) = 0;

	virtual bool SetSkin(unsigned int skin) = 0;

	virtual bool SetScale(float scaleX, float scaleY, float scaleZ) = 0;

	virtual float GetBase() = 0;

	virtual float GetModelSpeed() = 0;

protected:

	Vector3D m_scale;
	//unsigned int m_skinID;
};

#endif