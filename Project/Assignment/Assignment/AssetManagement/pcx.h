

#ifndef PCX_H 
#define PCX_H 

#include "Texture.h"

typedef struct _pcxHeader 
{ 
	short id[2]; 
	short offset[2]; 
	short size[2]; 
} pcxHeader; 


class pcx : public Texture
{ 
public: 

	pcx(char* name, unsigned char* data, int width, int height);

	~pcx();
 
	//unsigned char* GetData();

	//int GetWidth();

	//int GetHeight();

	//unsigned int GetBPP();

	//RGB<unsigned char> GetColor(int x,int y);

private:

}; 

#endif 
