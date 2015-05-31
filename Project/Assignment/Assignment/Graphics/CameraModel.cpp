
#include "CameraModel.h"
#include "../Singletons.h"

CameraModel::CameraModel() :
	Camera()
{
}

CameraModel::~CameraModel()
{
}

void CameraModel::Render()
{
	graphics->UpdateCamera(position, lookAt);
}