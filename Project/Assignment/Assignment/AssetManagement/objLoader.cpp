
#include "objLoader.h"

//#include "../SOIL.h"

#include "tiny_obj_loader.h"
#include "../Graphics/objModel.h"
#include "../Singletons.h"

#include <string>
#include <iostream>


GameAsset* objLoader::Create(char* filePath)
{
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> mats;
	std::vector<unsigned int> textures;

	//std::vector<shape_t> shapes;
	//std::vector<material_t> tmats;

	bool DEBUG = false;

	std::string strFilePath = filePath;
	std::string strFolder = strFilePath.substr(0, strFilePath.find_last_of("/"))+"/"; //Get the extension
	//std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);

	std::cout << "file path: " << filePath << "\nFolder: " << strFolder << std::endl;
	//getchar();
	const char* folder = strFolder.c_str();

	
	// uses 'tiny_obj_loader' to load the .obj model for use with shapes and material specs
	std::string err = tinyobj::LoadObj(shapes, mats, filePath, folder);

	if(!err.empty()) // if fail to load return false
	{
		std::cout << err << std::endl;
		return nullptr;
	}



	if(DEBUG) // for debugging
	{
		std::cout << "# of shapes : " << shapes.size() << std::endl;	
		std::cout << "# of materials : " << mats.size() << std::endl;	
		for (size_t i = 0; i < shapes.size(); i++) 
		{
			printf("shape[%ld].name = %s\n", i, shapes[i].name.c_str());
			printf("Size of shape[%ld].indices: %ld\n", i, shapes[i].mesh.indices.size());
			printf("Size of shape[%ld].material_ids: %ld\n", i, shapes[i].mesh.material_ids.size());
				for (size_t f = 0; f < shapes[i].mesh.indices.size() / 3; f++) 
				{
					printf("  idx[%ld] = %d, %d, %d. mat_id = %d\n", f, 
						shapes[i].mesh.indices[3*f+0], 
						shapes[i].mesh.indices[3*f+1], 
						shapes[i].mesh.indices[3*f+2], 
						shapes[i].mesh.material_ids[f]);
				}
		}
	}

	// iterate through texture names and load textures
	for (size_t i = 0; i < mats.size(); i++) 
	{
		if(DEBUG)
		{
			printf("  material.map_Ka = %s\n", mats[i].ambient_texname.c_str());
			printf("  material.map_Kd = %s\n", mats[i].diffuse_texname.c_str());
			printf("  material.map_Ks = %s\n", mats[i].specular_texname.c_str());
		}
		// set correct name for texture for loading
		std::string texstr = mats[i].diffuse_texname.c_str();
		std::string texFilePath = strFolder + texstr;

		const char *texfile = texFilePath.c_str();
		std::string texname = mats[i].name.c_str();
		if(DEBUG)
		{
			std::cout << " tempstr " << texFilePath << std::endl;	
			std::cout << "texname " << texname << std::endl;
		}
		assetManager->Load(texFilePath);
		unsigned int tex = graphics->SetupTextureClamp(assetManager->GetAsset(texFilePath));
		//tex = LoadTexWrap(texFilePath.c_str());
		textures.push_back(tex);
		//tex = LoadTexWrap(texfile); 
		//m_textures.push_back(tex); // add to texture vector
	}

	if(DEBUG) getchar();

	return new objModel(filePath, shapes, mats, textures);
}


const char* objLoader::GetExtension()
{
	return ".obj";
}


//--------------------------------------------------------------------------------------
//
//unsigned int objLoader::LoadTexWrap(const char * filename)
//{
//    GLuint texture;
//
//	texture = SOIL_load_OGL_texture( filename, SOIL_LOAD_AUTO,
//		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y);
//
//	if(texture == 0)
//		cout << "*** Can't open input file - please check file name typed! " << filename << endl;
//
//    glBindTexture( GL_TEXTURE_2D, texture ); //bind the texture to its array
//
//    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR );
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
//
//    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT ); //setting the parameter to repeat the texture instead of clamping the texture
//    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
//
//    return texture;
//}