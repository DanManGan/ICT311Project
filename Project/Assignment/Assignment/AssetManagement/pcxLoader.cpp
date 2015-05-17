
#include "pcxLoader.h"
#include "pcx.h"

#include <iostream>
#include <gl/glut.h>

GameAsset* pcxLoader::Create(char *filePath)
{ 
	if(!ValidFile(filePath))
		return nullptr;

	int imgWidth, imgHeight, texFileLen, imgBufferPtr, i; 
	pcxHeader *pcxPtr; 
	unsigned char *imgData, *imgBuffer, *texBuffer, *pcxBufferPtr, *paletteBuffer; 

	/* find length of file */ 
	FILE *hTexFile = fopen( filePath, "rb" ); 
	fseek( hTexFile, 0, SEEK_END ); 
	texFileLen = ftell( hTexFile ); 
	fseek( hTexFile, 0, SEEK_SET ); 

	/* read in file */ 
	texBuffer = (unsigned char *)malloc( texFileLen+1 ); 
	fread( texBuffer, sizeof( char ), texFileLen, hTexFile ); 

	/* get the image dimensions */ 
	pcxPtr = (pcxHeader *)texBuffer; 
	imgWidth = pcxPtr->size[0] - pcxPtr->offset[0] + 1; 
	imgHeight = pcxPtr->size[1] - pcxPtr->offset[1] + 1; 
	/* image starts at 128 from the beginning of the buffer */ 
	imgBuffer = (unsigned char *)malloc( imgWidth * imgHeight ); 
	imgBufferPtr = 0; 
	pcxBufferPtr = &texBuffer[128]; 

	/* decode the pcx image */ 
	while( imgBufferPtr < (imgWidth * imgHeight) ) 
	{ 
		if( *pcxBufferPtr > 0xbf ) 
		{ 
		int repeat = *pcxBufferPtr++ & 0x3f; 
		for( i=0; i<repeat; i++ ) 
		{ 
			imgBuffer[imgBufferPtr++] = *pcxBufferPtr; 
		} 
		} else { 
		imgBuffer[imgBufferPtr++] = *pcxBufferPtr; 
		} 
		pcxBufferPtr++; 
	} 

	/* read in the image palette */ 
	paletteBuffer = (unsigned char *)malloc( 768 ); 
	for( i=0; i<768; i++ ) 
		paletteBuffer[i] = texBuffer[ texFileLen-768+i ]; 

	/* now create the texture */ 
	{ 
		int i, j; 
		imgData = (unsigned char *)malloc( imgWidth * imgWidth * 3 ); 
		for (j = 0; j < imgHeight; j++) 
		{ 
		for (i = 0; i < imgWidth; i++) 
		{ 
			imgData[3*(j * imgWidth + i)+0] 
			= paletteBuffer[ 3*imgBuffer[j*imgWidth+i]+0 ]; 
			imgData[3*(j * imgWidth + i)+1] 
			= paletteBuffer[ 3*imgBuffer[j*imgWidth+i]+1 ]; 
			imgData[3*(j * imgWidth + i)+2] 
			= paletteBuffer[ 3*imgBuffer[j*imgWidth+i]+2 ]; 
		} 
		} 
	} 
	// cleanup 
	if(!TexMapScalePow2(imgData, imgWidth, imgHeight)) {
		std::cout << "load error - Not power of 2" << std::endl;
		return nullptr;
	}

	free( paletteBuffer ); 
	free( imgBuffer ); 

	return new pcx(filePath, imgData, imgWidth, imgHeight); 
} 

const char* pcxLoader::GetExtension() 
{ 
	return ".pcx"; 
}


bool pcxLoader::TexMapScalePow2(unsigned char* data, int& width, int& height)
{
	int glMaxTexDim ;
	double xPow2, yPow2;
	int ixPow2, iyPow2;
	int xSize2, ySize2;

	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &glMaxTexDim);
	glMaxTexDim = std::min(128, glMaxTexDim);

	if (width <= glMaxTexDim)
		xPow2 = log((double)width) / log(2.0);
	else
		xPow2 = log((double)glMaxTexDim) / log(2.0);

	if (height <= glMaxTexDim)
		yPow2 = log((double)height) / log(2.0);
	else
		yPow2 = log((double)glMaxTexDim) / log(2.0);

	ixPow2 = (int)xPow2;
	iyPow2 = (int)yPow2;

	if (xPow2 != (double)ixPow2)
		ixPow2++;
	if (yPow2 != (double)iyPow2)
   		iyPow2++;
 
   
	xSize2 =1 << ixPow2;
	ySize2 = 1 << iyPow2;
	GLubyte *pData = (GLubyte*)malloc(xSize2 * ySize2 * 3 * sizeof(GLubyte));
		if (!pData) return false;
 
	gluScaleImage(GL_RGB, width, height,GL_UNSIGNED_BYTE, data,xSize2, ySize2, GL_UNSIGNED_BYTE,pData);

	free(data);
	data = (GLubyte*)pData; 
	width = xSize2 ;
	height = ySize2 ;

	return true ;
}