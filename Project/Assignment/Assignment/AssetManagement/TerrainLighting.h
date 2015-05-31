
/** 
  * @class TerrainLighting
  * @brief Provides software lighting for a terrain
  * 
  *
  * Provides software lighting for a terrain either through a loaded light map or
  * by creating a light map using the slope lighting technique.
  * The light map is simple loaded in for use.
  * The Slope light map is created from the terrain that is passed in. 
  * Parameters such as light direction, min/max brightness and softness
  * can be set to provide good control over the lighting created
  *
  * 
  * @author Justin Pettit
  * @version 01
  * @date 07.05.15
  * @status Finished
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

#ifndef TERRAINLIGHTING_H
#define TERRAINLIGHTING_H

#include "Texture.h"

/** 
  * @brief Lighting type
  * @warning None
  * 
  * Enum for lighting type to be used
  * LIGHTMAP specifies a lighting map is loaded to be used
  * SLOPE_LIGHT means a light map will be created based on the terrain and light location
  * 
  * 
  * @pre 
  * @post 
  */ 
enum LIGHTING_TYPE{LIGHTMAP, SLOPE_LIGHT};
 
class TerrainLighting
{
public:

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
	TerrainLighting();

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
	~TerrainLighting();

	/** 
	  * @brief Load grayscale Lightmap
	  * @warning variable size must be power of 2 value
	  * 
	  * Load a grayscale RAW light map
	  * 
	  * @param file: char type variable in TerrainLighting class for file name
	  * @param size: const int type variable in TerrainLighting class for sile size
	  * @return bool value true if load successful
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool LoadLightmap(char *file, const int size);
	
	/** 
	  * @brief Unload light map
	  * @warning None
	  * 
	  * Deletes light map data and sets size to 0
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	void UnloadLightmap();

	/** 
	  * @brief Save light map
	  * @warning None
	  * 
	  * Saves a grayscale RAW light map
	  * 
	  * @param file: char type variable in TerrainLighting class for file name
	  * @return bool value trye if save successful
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool SaveLightmap(char* file);

	/** 
	  * @brief Get Lightmap data
	  * @warning None
	  * 
	  * Returns a pointer to the Light map
	  * 
	  * @return unsigned char * for light map
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	unsigned char* GetLightmap();
	
	/** 
	  * @brief Get lightmap size
	  * @warning None
	  * 
	  * Get current size of lightmap
	  * 
	  * @return int value for light map size member
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	int GetSize();

	/** 
	  * @brief Get brightness at point on lightmap
	  * @warning None
	  * 
	  * A function to get the brightness value at a 
	  * certain point in a lightmap
	  * 
	  * @param x: i type variable in TerrainLighting class for x position
	  * @param z: i type variable in TerrainLighting class for z position
	  * @return unsigned char value 
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	unsigned char GetBrightnessAtPoint(int x, int z);
	
	/** 
	  * @brief Gets lightmap colour
	  * @warning Must accept RGB struct
	  * 
	  * Returns RGB struct for rgb lighting values
	  * 
	  * @return RGB<float> value for rgb lighting values
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	RGB<float> GetLightmapColour();

	/** 
	  * @brief Gets value at x,z point
	  * @warning None
	  * 
	  * Gets the value from the array for point x,z on map
	  * 
	  * @param verts: unsigned char type variable in TerrainLighting class for map array
	  * @param size: int type variable in TerrainLighting class for map size
	  * @param xPos: int type variable in TerrainLighting class for x pos
	  * @param zPos: int type variable in TerrainLighting class for z pos
	  * @return float value for value at position on map
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float GetValueAtPoint(unsigned char* verts, int size, int xPos, int zPos);

	/** 
	  * @brief Get light x direction
	  * @warning None
	  * 
	  * Returns values for lighting x direction member
	  * 
	  * @return int value for light x direction
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	int GetDirectionX();

	/** 
	  * @brief Get light z direction
	  * @warning None
	  * 
	  * Returns values for lighting z direction member
	  * 
	  * @return int value for light z direction
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
    int GetDirectionZ();

	/** 
	  * @brief Get lighting min brightness
	  * @warning None
	  * 
	  * Returns value for lighting minimum brightness member
	  * 
	  * @return float value for minimum brightness
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float GetMinBrightness();

	/** 
	  * @brief Get lighting max brightness
	  * @warning None
	  * 
	  * Returns value for lighting maximum brightness member
	  * 
	  * @return float value for maximum brightness
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	float GetMaxBrightness();

	/** 
	  * @brief Get lighting softness
	  * @warning None
	  * 
	  * Returns value for lighting softness member
	  * 
	  * @return float value for softness
	  * 
	  * 
	  * @pre 
	  * @post 
	  */  
	float GetSoftness();

	/** 
	  * @brief Get set Lighting type
	  * @warning None
	  * 
	  * Get the current set lighting type
	  * 
	  * @return LIGHTING_TYPE value for lighting type in use
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	LIGHTING_TYPE GetLightingType();
	
	/** 
	  * @brief Set light map size
	  * @warning None
	  * 
	  * Sets the size of the light map to be created
	  * 
	  * @param size: i type variable in TerrainLighting class for light map size
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetLightmapSize(int size);

	/** 
	  * @brief Sets brightness at x,z pos
	  * @warning None
	  * 
	  * A function to set the brightness value at a certain point in a lightmap
	  * 
	  * @param x: int type variable in TerrainLighting class for x pos
	  * @param z: int type variable in TerrainLighting class for z pos
	  * @param brightness: unsigned char type variable in TerrainLighting class for brightness value
	  * @return bool value rtue if set ok
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool SetBrightnessAtPoint(int x,int z,unsigned char brightness);

	/** 
	  * @brief Set lighting direction
	  * @warning None
	  * 
	  * Sets the direction of the light to be used when crerating slope lighting
	  * 
	  * @param x: int type variable in TerrainLighting class for x pos
	  * @param z: int type variable in TerrainLighting class for z pos
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetDirection(int x,int z);

	/** 
	  * @brief Set lighting brightness
	  * @warning None
	  * 
	  * Sets the min and max brightness values to be used when creating slope lighting
	  * 
	  * @param min: float type variable in TerrainLighting class for min brightness
	  * @param max: float type variable in TerrainLighting class for max brightness
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetBrightness(float min, float max);

	/** 
	  * @brief Set softenss value
	  * @warning None
	  * 
	  * Sets softness value to be used when creating slope lighting
	  * 
	  * @param soft: float type variable in TerrainLighting class for softness
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetSoftness(float soft);

	/** 
	  * @brief Set lighting type
	  * @warning None
	  * 
	  * Set the lighting technique to be used
	  * 
	  * @param type: LIGHTING_TYPE type variable in TerrainLighting class for lighting type
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetLightingType(LIGHTING_TYPE type);
	
	/** 
	  * @brief Set lighting rgb values
	  * @warning None
	  * 
	  * Set the color of the terrain's lighting system
	  * 
	  * @param red: unsigned char type variable in TerrainLighting class for red
	  * @param green: unsigned char type variable in TerrainLighting class for green
	  * @param blue: unsigned char type variable in TerrainLighting class for blue
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetLightmapColor(unsigned char red,unsigned char green, unsigned char blue);


	//--------------------------------------------------------------
	// Name:			CTERRAIN::CustomizeSlopeLighting - public
	// Description:		Customize the parameters for slope lighting
	// Arguments:		-iDirX, iDirZ: direction of the light, which can only
	//					               be a whole number.
	//					-fSoftness: the softness of the shadows
	//					-fMinBrightness, fMaxBrightness: the min/max brightness
	//													 of the light
	// Return Value:	None
	//--------------------------------------------------------------
	/** 
	  * @brief Set slope lighting parameters
	  * @warning None
	  * 
	  * Customize the parameters for slope lighting
	  * 
	  * @param dirx: int type variable in TerrainLighting class for x direction member
	  * @param dirz: int type variable in TerrainLighting class for z direction member
	  * @param minB: float type variable in TerrainLighting class for min brightness member
	  * @param maxB: float type variable in TerrainLighting class for max brightness member
	  * @param soft: float type variable in TerrainLighting class for softness member
	  * 
	  * @pre 
	  * @post 
	  */ 
	void SetSlopeLightingParams(int dirx, int dirz, float minB, float maxB, float soft);

	/** 
	  * @brief Creates Slope lighting values
	  * @warning None
	  * 
	  * Calculates lighting for the pre-set technique, and
	  * stores all computations in a lightmap
	  * 
	  * @param heightmap: unsigned char* type variable in TerrainLighting class for terrain to be used
	  * @param hMapSize: int type variable in TerrainLighting class for terrain map size
	  * @return bool value true for successful creation
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool CreateSlopeLighting(unsigned char* heightmap, int mapSize);

	/** 
	  * @brief Checks if light map exists
	  * @warning None
	  * 
	  * Returns true if light map has been create or loaded
	  * 
	  * @return bool value true if light map exists
	  * 
	  * 
	  * @pre 
	  * @post 
	  */ 
	bool IsLightMapped();

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
	  * @brief Light map data
	  * @warning None
	  * 
	  * unsigned char* for light map array
	  * 
	  * @pre 
	  * @post 
	  */
	unsigned char* m_lightmapData;
	
	/** 
	  * @brief Light map size
	  * @warning None
	  * 
	  * int type member for light map size
	  * 
	  * @pre 
	  * @post 
	  */
	int m_lightmapSize;

	/** 
	  * @brief Light x direction member
	  * @warning None
	  * 
	  * int type member for light x direction
	  * 
	  * @pre 
	  * @post 
	  */ 
	int m_directionX;

	/** 
	  * @brief Light z direction member
	  * @warning None
	  * 
	  * int type member for light z direction
	  * 
	  * @pre 
	  * @post 
	  */
	int m_directionZ;

	/** 
	  * @brief Light min brightness member
	  * @warning None
	  * 
	  * float type member for min brightness
	  * 
	  * @pre 
	  * @post 
	  */
	float m_minBrightness; //min max brightness values

	/** 
	  * @brief Light max brightness member
	  * @warning None
	  * 
	  float type member for max brightness
	  * 
	  * @pre 
	  * @post 
	  */
	float m_maxBrightness; 

	/** 
	  * @brief Light softness member
	  * @warning None
	  * 
	  * float type member for lighting softness
	  * 
	  * @pre 
	  * @post 
	  */
	float m_softness;
	
	/** 
	  * @brief Lighting type member
	  * @warning None
	  * 
	  * LIGHTING_TYPE type member for lighting technique
	  * 
	  * @pre 
	  * @post 
	  */
	LIGHTING_TYPE m_lightingType;
	
	/** 
	  * @brief Lighting colour member
	  * @warning None
	  * 
	  * RGB<float> type member for lighting colour
	  * 
	  * @pre 
	  * @post 
	  */ 
	RGB<float> m_lightmapColour;
};
#endif