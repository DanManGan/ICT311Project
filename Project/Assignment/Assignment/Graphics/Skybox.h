/** 
  * @class Skybox
  * @brief used to create a skybox 
  * 
  * 
  * 
  * @author Daniel Manganaro
  * @version 01
  * @date 25.04.15
  * @status under construction
  * 
  * @todo 
  * 
  * @bugs 
  */

#ifndef SKYBOX_H
#define SKYBOX_H

#include "..\Extras\MathExtra.h"
#include "..\Extras\Vector3D.h"
#include "..\AssetManagement\GameAsset.h"
#include "..\AssetManagement\Texture.h"
#include "..\Graphics\ViewOpenGL.h"

#define SB_NUMSIDES 6

#define SB_FRONT	0
#define SB_BACK		1
#define SB_RIGHT	2
#define SB_LEFT		3
#define SB_TOP		4
#define SB_BOTTOM	5

class Skybox {
private:
	/** 
	  * @brief Vector objects
	  * @warning None
	  * 
	  * min, max and center positions of the skybox
	  * 
	  * @pre 
	  * @post 
	  */
	Vector3D m_vecMin, m_vecMax, m_vecCenter;
	
	/** 
	  * @brief array of texture i
	  * @warning None
	  * 
	  * 
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
	unsigned int m_textureIDs[SB_NUMSIDES];
	
public:
	/** 
	  * @brief load a texture to the specific side of skybox
	  * @warning None
	  * 
	  * @param int side - side of the skybox
	  * @param char* filename - name of texture file
	  * 
	  * @pre 
	  * @post 
	  */
	bool LoadTexture(int side, char* filename);
	/** 
	  * @brief Renders the skybox
	  * @warning None
	  * 
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
	void Render();

	/** 
	  * @brief set the position and size of the skybox
	  * @warning None
	  * 
	  * @param float cx - x pos
	  * @param float cy - y pos
	  * @param float cz - z pos
	  * @param float size - size of skybox
	  *
	  * @pre 
	  * @post 
	  */
	void Set(float cx, float cy, float cz, float size) {
		float halfSize = size/2;

		m_vecCenter.Set(cx, cy, cz);

		m_vecMin.Set(-halfSize, -halfSize, -halfSize);
		m_vecMax.Set(halfSize, halfSize, halfSize);
	}

	/** 
	 * @brief Default constructor
	 * @warning None
	 * 
	 * Default class constructor
	 * 
	 * 
	 * @pre 
	 * @post 
	 */
	Skybox()
	{	}
	/** 
	  * @brief Default destructor
	  * @warning None
	  * 
	  * Default class destructor
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
	~Skybox()
	{	}
};

#endif
