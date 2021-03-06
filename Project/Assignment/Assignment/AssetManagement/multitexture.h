
//////////////////////////////////////////////////////////////////////////
//		THIRD PARTY CODE
//////////////////////////////////////////////////////////////////////////

/*-----------------------------------------------
MultiTexture.h
-----------------------------------------------*/

#ifndef __MULTITEXTURE_H
#define __MULTITEXTURE_H

#ifdef __cplusplus
extern "C" {
#endif

#if _MCS_VER >= 1020
  #pragma once
#endif

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__)
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>
#endif

#ifndef APIENTRY
#define APIENTRY
#endif

#include <gl/gl.h> // Header File For The OpenGL32 Library
#include <gl/glu.h> // Header File For The GLu32 Library

// Constants ////////////////////////////////////////////////////////////////////////////

// Multitexture constants
#define GL_TEXTURE0_ARB 0x84C0
#define GL_TEXTURE1_ARB 0x84C1

#define GL_COMBINE_ARB 0x8570
#define GL_RGB_SCALE_ARB 0x8573


// Functions ////////////////////////////////////////////////////////////////////////////

typedef void (APIENTRY * PFNGLMULTITEXCOORD2FARBPROC) (GLenum target, GLfloat s, GLfloat t);
typedef void (APIENTRY * PFNGLACTIVETEXTUREARBPROC) (GLenum target);
typedef void (APIENTRY * PFNGLCLIENTACTIVETEXTUREARBPROC) (GLenum target);

bool initMultiTextures(void);


// External Function Pointers ///////////////////////////////////////////////////////////

extern PFNGLMULTITEXCOORD2FARBPROC glMultiTexCoord2fARB;
extern PFNGLACTIVETEXTUREARBPROC glActiveTextureARB;
extern PFNGLCLIENTACTIVETEXTUREARBPROC glClientActiveTextureARB;

#ifdef __cplusplus
}
#endif

#endif 
