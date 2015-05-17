
#include "ResourceLoader.h"

#include <fstream>

bool ResourceLoader::ValidFile(char *filePath)
{
	std::fstream testExists(filePath);

	if(testExists.is_open()) {
		testExists.close();
		return true;
	}

	return false;
}