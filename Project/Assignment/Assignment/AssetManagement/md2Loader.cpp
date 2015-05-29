#include "md2Loader.h"

//#include "md2Header.h"
#include <cstdio>
#include <iostream>
#include <fstream>
//#include "imageLoader/imageFactory.h"
//#include <gl\glut.h>
//#include <GL/glfw.h>

GameAsset* md2Loader::Create(char* filePath)//, char* skinName)
{
	md2Header *header = new md2Header();
	frame* frames = nullptr;
	triangle* triangles = nullptr;
	//skin* skins = nullptr;
	texCoord* texCoords = nullptr;
	vertex* vertices = nullptr;
	char * buffer=nullptr;

	//open for binary read 
	ifstream infile(filePath,ios::binary|ios::in);

	if(!infile) {
		std::cout << "Cannot open md2File :" << filePath << std::endl;
		return nullptr;
	}
	else {
		// get length of file
		infile.seekg (0, ios::end);
		//determine length of file
		header->fileSize = infile.tellg();
		infile.seekg (0, ios::beg);
		// allocate memory:
		buffer = new  char [header->fileSize];
			if(!buffer)
				return nullptr;
		// read data as a block:
		infile.read(buffer,header->fileSize);
		infile.close();
	} //if
	//read in header
	header->readHeader(buffer);
	if(!validFile(header))
		return nullptr;
	//read in frames
	frames = readFrames(header, buffer);
	//read in triangles
	triangles = readTriangles(header, buffer);
	//read in textures
	texCoords = readTextures(header, buffer);
	//read in skin filenames
	//readSkins(buffer);
	//addCustomSkin(skinName);
   
	if(buffer)
		delete[] buffer;

	return new md2Model(filePath, header, frames, triangles, texCoords, vertices);
}

const char* md2Loader::GetExtension()
{
	return ".md2";
}

frame* md2Loader::readFrames(md2Header* head, char* buf)
{
	unsigned char* ptr=0;
	//allocate memory for frame data
	frame* frames=new frame[head->numFrames];
	if(!frames)
	{
		cerr<<"could not allocate mem for frames"<<endl;
		return false;
	}
	//point to the beggining of the frame data
	//need to convert to unsigned as x value is unsigned
	ptr=(unsigned char*)buf+head->offsetFrames;

	for(int i=0;i<head->numFrames;i++)
	{ //loop through and read in all frames
		//read in frame header
		//read in scale
		memcpy(frames[i].scale,ptr,12);
		//read in trans
		ptr+=12;
		memcpy(frames[i].trans,ptr,12);
		//read in name
		ptr+=12;
		memcpy(frames[i].name,ptr,16);
		ptr+=16;
		//allocate vertice mem
		frames[i].vertices=new vertex[head->numVertices];
		for(int j = 0; j < head->numVertices; j++)
		{
			//swap y and z coords to convert to the proper orientation on screen
			frames[i].vertices[j].x = ptr[0] * frames[i].scale[0] + frames[i].trans[0];
			frames[i].vertices[j].y = ptr[2] * frames[i].scale[2] + frames[i].trans[2];
			frames[i].vertices[j].z = ptr[1] * frames[i].scale[1] + frames[i].trans[1];
			frames[i].vertices[j].normIndex=ptr[3];  //read normal index
			ptr += 4;  //point to next vertex array index
		}
	} //for
 return frames;
}

triangle* md2Loader::readTriangles(md2Header* head, char* buf)
{
  unsigned char *ptr=(unsigned char *)buf+head->offsetTriangles;
	  //read in triangles
	  triangle* triangles=new triangle[head->numTriangles];
	  memcpy(triangles,ptr,12*head->numTriangles);
 return triangles;
}

texCoord* md2Loader::readTextures(md2Header* head, char* buf)
{	  
  //read in uv texture coords- read into array of shorts and convert
  //to floats using skinwidth and skinheight
  unsigned char *ptr=(unsigned char *)buf+head->offsetTexCoords;
      texCoord* texCoords = new texCoord[head->numTexCoords];
	  short *sTexCoords = new short[head->numTexCoords*2];
	  memcpy(sTexCoords, ptr, 4 * head->numTexCoords);
   	    for(int i = 0; i < head->numTexCoords; i++)
	    {
		 texCoords[i].tex[0] = (float)sTexCoords[2*i] /head->skinWidth;
		 texCoords[i].tex[1] = (float)sTexCoords[2*i+1] /head->skinHeight;
	    }
	 delete [] sTexCoords;
 return texCoords;
}




//*****************************************************************************
//*Purpose: checks for a valid md2 file
//*Pre : header is an assigned value
//*Post: returns true if valid, otherwise false
//*****************************************************************************/
bool md2Loader::validFile(md2Header* head)
{
	if(head->ident!=844121161 || head->version!=8)
	{
		cerr<<"Not a valid MD2 file"<<endl;
		return false;
	}
 return true;
}

