
#include "CameraModel.h"
#include "../Singletons.h"

CameraModel::CameraModel() :
	Camera()
{
}

CameraModel::~CameraModel()
{
}

void CameraModel::Render(Vector3D p_position, Vector3D p_lookAt)
{
	//p_position.Print();
	//	p_lookAt.Print();
	graphics->UpdateCamera(p_position, p_lookAt);
}