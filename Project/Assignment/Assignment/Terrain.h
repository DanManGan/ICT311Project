
/** 
  * @class Terrain
  * @brief Terrain Generation class
  * 
  * Class to generate terrain from a height map or
  * via fault formation algorithm
  * Provides for texturing of terrain from a single texture 
  * or with procedural texture and the application of
  * a detailed map
  * 
  * @author Justin Pettit
  * @version 01
  * @date 20.04.15
  * @status under construction
  * 
  * @author 
  * @version 
  * @date 
  * @status 
  * 
  * @todo 
  * 
  * @bugs 
  */ 

#ifndef TERRAIN_H
#define TERRAIN_H

#include "AssetManagement/textureGenerator.h"
#include "AssetManagement/Texture.h"
#include "Vector3D.h"
#include "TerrainLighting.h"
#include "AssetManagement/GameAsset.h"


class Terrain : public GameAsset
{
public:
////////////////////  Terrain Methods  ////////////////////
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
	Terrain();

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
	~Terrain();

	/** 
	  * @brief Virtual Render method
	  * @warning None
	  * 
	  * Render method for to be implemented in child classes
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	virtual void Render() = 0;

	/** 
	  * @brief Load heightfield map for terrain
	  * @warning variable size must be power of 2 value
	  * 
	  * Loads a heightfield from a map for rendering as terrain
	  * 
	  * @param file: char type pointer variable in Terrain class for file name
	  * @param size: const int type variable in Terrain class for terrain size
	  * @return bool value true if load successful
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool LoadHeightfield(char* file, const int size);

	bool LoadHeightfield(char* file);

	/** 
	  * @brief Unload Height field
	  * @warning None
	  * 
	  * Deletes terrain data and sets size to 0
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void UnloadHeightfield();

	/** 
	  * @brief Save heightfield to file
	  * @warning None
	  * 
	  * Save a grayscale RAW height map
	  * 
	  * @param file: char type variable for file name
	  * @return bool value true if save successfule
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool SaveHeightfield(char* file);

	/** 
	  * @brief Get terrain size
	  * @warning None
	  * 
	  * Get size of current terrain
	  * 
	  * @return int value for terrain size member
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	int GetSize();

	/** 
	  * @brief Get the height grayscale colour
	  * @warning None
	  * 
	  * Gets the height grayscale colour from map at the given x,z coordinates
	  * 
	  * @param xPos: int type variable in Terrain class for x position
	  * @param zPos: int type variable in Terrain class for z position
	  * @return unsigned char type variable in Terrain class for height at x,z position 
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	unsigned char GetHeightColour(int xPos, int zPos);
		
	/** 
	  * @brief Get Scaled height at point
	  * @warning None
	  * 
	  * Gets the scaled height of the terrain at the given x,z coordinates
	  * 
	  * @param xPos: int type variable in Terrain class for x position
	  * @param zPos: int type variable in Terrain class for z position
	  * @return float value for scaled height at x,z position
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float GetHeightScaled(int xPos, int zPos);

	/** 
	  * @brief Get unscaled height at point
	  * @warning None
	  * 
	  * Gets the unscaled height of the terrain at the given x,z coordinates
	  * 
	  * @param xPos: int type variable in Terrain class for x position
	  * @param zPos: int type variable in Terrain class for z position
	  * @return float value for unscaled height at x,z position
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float GetHeightUnscaled(int xPos, int zPos);

	/** 
	  * @brief Get average height at point
	  * @warning None
	  * 
	  * Gets the average height of the terrain at the given x,z coordinates
	  * 
	  * @param xPos: int type variable in Terrain class for x position
	  * @param zPos: int type variable in Terrain class for z position
	  * @return float value for average height at x,z position 
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float GetHeightAverage(float xPos, float zPos);
	
	/** 
	  * @brief Set map scale
	  * @warning ONLY SCALE Y AXIS, x and z not setup
	  * 
	  * Scales the terrain map by the values passed in
	  * 
	  * @param xScale: float type variable in Terrain class for x scale
	  * @param yScale: float type variable in Terrain class for y scale
	  * @param zScale: float type variable in Terrain class for z scale
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetScaleFactor(float xScale, float yScale, float zScale);

	/** 
	  * @brief Set terrain height at point
	  * @warning None
	  * 
	  * Sets the height of the terrain at the given x,z coordinates
	  * 
	  * @param height: unsigned char type variable in Terrain class for height
	  * @param xPos: int type variable in Terrain class for x position
	  * @param zPos: int type variable in Terrain class for z position
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetHeightAtPoint(unsigned char height, int xPos, int zPos);
	
	/** 
	  * @brief Generate terrain via fault form algorithm
	  * @warning variable size must be a power of 2
	  * 
	  * Generates a 3d terrain using the fault formation algorithm
	  * using the values for size, height etc passed in
	  * 
	  * @param iterations: int type variable in Terrain class for number of iterations to make field
	  * @param size: int type variable in Terrain class for size of terrain
	  * @param minHeight: int type variable in Terrain class for minimum height of terrain
	  * @param maxHeight: int type variable in Terrain class for maximum height of terrain
	  * @param weight: float type variable in Terrain class for weight of variations in terrain
	  * @param random: bool type variable in Terrain class to define if terrain is to be truly random
	  * @return bool value true for success of terrain generation
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool GenFaultFormation(int iterations, int size, int minHeight, 
		int maxHeight, float weight, bool random);

////////////////////  Texture Methods  ////////////////////

	/** 
	  * @brief Load terrain texture
	  * @warning None
	  * 
	  * Load terrain texture map from file
	  * 
	  * @param file: char type variable in Terrain class for file name
	  * @return bool value true if file loaded
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool LoadTexture(char* file);
		
	/** 
	  * @brief Add texture to procedural textures
	  * @warning None
	  * 
	  * Loads and adds a texture in for procedural map creation
	  * 
	  * @param file: char type variable in Terrain class for file name
	  * @return bool value true if file loaded
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool LoadProceduralTexture(char* file);

	/** 
	  * @brief Load detail map texture
	  * @warning None
	  * 
	  * Load detail map texture from file
	  * 
	  * @param file: char type variable in Terrain class for file name
	  * @return bool value true if file loaded
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool LoadDetailMap(char* file); 

	/** 
	  * @brief Set texture repeat value
	  * @warning None
	  * 
	  * Set the number of times the applied texture will repeat
	  * 
	  * @param num: int type variable in Terrain class for texture repeat
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetNumTerrainTexRepeat(int num);

	/** 
	  * @brief Set detail map repeat value
	  * @warning None
	  * 
	  * Set the number of times the detail map will repeat
	  * 
	  * @param num: int type variable in Terrain class for detail map repeat
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetNumDetailMapRepeat(int num);

	/** 
	  * @brief Creates procedural texture
	  * @warning None
	  * 
	  * Creates a procedural texture from the loaded procedural
	  * texture files
	  * 
	  * @return bool value true if creation successful
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool CreateProceduralTexture();

	/** 
	  * @brief Sets normal texture on
	  * @warning None
	  * 
	  * Sets normal texture to be used for rendering
	  * 
	  * @return bool value true if texture set
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool TextureMapNormal();

	/** 
	  * @brief Sets procedural texture on
	  * @warning None
	  * 
	  * Sets procedural texture to be used for rendering
	  * 
	  * @return bool value true if texture set
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool TextureMapProcedural();

////////////////////  Lighting Methods  ////////////////////

	/** 
	  * @brief Get brightness at position
	  * @warning None
	  * 
	  * Gets the brightness at the position for lighting
	  * 
	  * @param xPos: int type variable in Terrain class for x position
	  * @param zPos: int type variable in Terrain class for z position
	  * @return unsigned char value for brightness value
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	unsigned char GetBrightnessAtPoint(int x, int z);

	/** 
	  * @brief Get the light map
	  * @warning None
	  * 
	  * Gets the light map
	  * 
	  * @return unsigned char * value for light map
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	unsigned char* GetLightMap();

	/** 
	  * @brief Get lighting colour
	  * @warning None
	  * 
	  * Gets the r,g,b values for light colour
	  * 
	  * @return RGB<float> value for light colour
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	RGB<float> GetLightMapColour();

	/** 
	  * @brief Set the light colour
	  * @warning None
	  * 
	  * Sets the r,g,b light colour for the light map
	  * 
	  * @param red: unsigned char type variable for red light value
	  * @param green: unsigned char type variable for green light value
	  * @param blue: unsigned char type variable for blue light value
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetLightingColor(unsigned char red,unsigned char green, unsigned char blue);

	/** 
	  * @brief Set lighting parameters
	  * @warning None
	  * 
	  * Sets the parameters for slope lighting
	  * 
	  * @param dirx: int type variable for light direction on x axis 
	  * @param dirz: int type variable for light direction on y axis 
	  * @param minB: float type variable for minimum brightness
	  * @param maxB: float type variable for maximum brightness
	  * @param soft: float type variable for lighting softness value
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetSlopeLightingParams(int dirx, int dirz, float minB, float maxB, float soft);

	/** 
	  * @brief Creates procedrual light map
	  * @warning None
	  * 
	  * Creates a procedrual light map from the terrain map
	  * 
	  * @return bool value true for successful light map creation
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool CreateSlopeLighting();

////////////////////////////////////////////////////////////////////////////////////////
	Vector3D GetNormal(int x, int z);

	void ComputeNormals();

	void SetTexture(unsigned int tex);

protected:
	
	/** 
	  * @brief terrain data member
	  * @warning None
	  * 
	  * stores values for terrain height data
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	unsigned char* m_terrainData;

	/** 
	  * @brief Terrain size member
	  * @warning None
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	int m_size;

	/** 
	  * @brief Terrain scale member
	  * @warning None
	  * 
	  * Hold values for x,y,z scale
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	Vector3D m_scale;

	/** 
	  * @brief Normal texture ID
	  * @warning None
	  * 
	  * ID for the normal texture
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	unsigned int m_texMapNormalID;

	/** 
	  * @brief Procedural texture ID
	  * @warning None
	  * 
	  * ID for the procedural texture
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	unsigned int m_texMapProceduralID;

	/** 
	  * @brief Detail texture ID
	  * @warning None
	  * 
	  * ID for the detailed texture map
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	unsigned int m_detailMapTexID;

	/** 
	  * @brief normal texture map on member
	  * @warning None
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool m_texMapNormal;

	/** 
	  * @brief Procedural texture map on member
	  * @warning None
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool m_texMapProcedural;

	/** 
	  * @brief detail texture map on member
	  * @warning None
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool m_texMapDetail;

	/** 
	  * @brief Terrain texture repeat member
	  * @warning None
	  * 
	  * Sets the value for the number of times the texture is to be repeated
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	int m_numTerrainTexRepeat;

	/** 
	  * @brief Detail map texture repeat
	  * @warning None
	  * 
	  * Sets the value for the number of times the detail map is to be repeated
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	int m_numDetailMapRepeat;

	/** 
	  * @brief Procedural Texture Generator member
	  * @warning None
	  * 
	  * Used to create the procedural texture map
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	textureGenerator m_textureGenerator;

	/** 
	  * @brief Procedural Light map member
	  * @warning None
	  * 
	  * Used to create the procedural light map
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
	TerrainLighting m_lighting;

private:

	/** 
	  * @brief Test x,z point on terrain
	  * @warning None
	  * 
	  * Test the x,z coordinates to confirm they're within the terrain limits
	  * 
	  * @param zPos: int type variable in Terrain class for z position
	  * @param xPos: int type variable in Terrain class for x position
	  * @return bool value true if in bounds
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool Inbounds(int xPos, int zPos);

	/** 
	  * @brief Terrain Generation helper
	  * @warning None
	  * 
	  * Filter pass used as a helper function for terrain generation
	  * with the fault formation algorithm in the GenFaultFormation method
	  * 
	  * @param dataP: float type variable in Terrain class for data to be filtered
	  * @param increment: int type variable in Terrain class increment value for dataP
	  * @param weight: float type variable in Terrain class for weight of filtering
	  * 
	  * @pre 
	  * @post 
	  */ 
	void FilterPass(float* dataP, int increment, float weight);

	/** 
	  * @brief Terrain Generation helper
	  * @warning None
	  * 
	  * Controls the filter passes for the terrain
	  * 
	  * @param terrainData: float type pointer variable in Terrain class for terrain data
	  * @param weight: float type variable in Terrain class for weight of filtering
	  * 
	  * @pre 
	  * @post 
	  */ 
	void AddFilter(float* terrainData, float weight);

	/** 
	  * @brief Terrain Generation helper
	  * @warning None
	  * 
	  * Normalises the terrain data
	  * 
	  * @param terrainData: float type pointer variable in Terrain class for terrain data
	  * 
	  * @pre 
	  * @post 
	  */ 
	void NormaliseTerrain(float* terrainData);

	/** 
	  * @brief Procdural texture helper
	  * @warning None
	  * 
	  * Gets texture coordinates of current texture to be used in
	  * procedural terrain generation
	  * 
	  * @param texNum: int type variable in Terrain class 
	  * @param x: unsigned int type variable in Terrain class 
	  * @param y: unsigned int type variable in Terrain class 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void GetTexCoords(int texNum, unsigned int& x, unsigned int& y);
	

};

#endif