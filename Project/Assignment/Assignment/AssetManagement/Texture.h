
#ifndef TEXTURE_H
#define TEXTURE_H

#include "GameAsset.h"
//#include "textureHandler/image.h"

#include <string>


template <class T>
struct RGB
{
	T r;
	T g;
	T b;
	void set(RGB<T> rgb){r=rgb.r;g=rgb.g;b=rgb.b;}
    void reset(){r=0;g=0;b=0;}
};

class Texture : public GameAsset
{
public:

	
	Texture();
	
	//Texture(char* name, unsigned int texID);

	Texture(char* name, unsigned char* data, int width, 
		int height, unsigned int BPP);

	//Texture(char* filePath);

	~Texture();

	//void Load(char* filePath);

	//bool SetImage(image* rawImage);

	bool SetData(unsigned char* data);
	bool SetWidth(int width);
	bool SetHeight(int height);
	
	bool SetBPP(unsigned int BPP);

	bool SetTexID(unsigned int texture);

	Texture* GetTexture();

	unsigned int GetTexID();

	//virtual bool load(char *filename)=0;
	void Unload();
	//virtual unsigned char* GetData()=0;
	//virtual int GetWidth()=0;
	//virtual int GetHeight()=0;
	//
	//virtual unsigned int GetBPP()=0;
	//virtual RGB<unsigned char> GetColor(int x,int y)=0;

	unsigned char* GetData();
	int GetWidth();
	int GetHeight();
	
	virtual unsigned int GetBPP()=0;
	virtual RGB<unsigned char> GetColor(int x,int y)=0;

protected:
	
	//image* m_image;

	unsigned int m_textureID;

	unsigned char* m_imageData;
	int m_width;
	int m_height;
	unsigned int m_BPP;

private:
	
};

#endif