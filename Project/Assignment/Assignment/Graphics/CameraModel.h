
#ifndef CAMERAMODEL_H
#define CAMERAMODEL_H

#include "../AssetManagement/Camera.h"
#include "../Extras/Vector3D.h"

class CameraModel : public Camera
{
public:

	CameraModel();

	~CameraModel();

	void Render(Vector3D p_position, Vector3D p_lookAt);


private:

};

#endif