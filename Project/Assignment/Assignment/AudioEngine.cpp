
#pragma comment(lib, "irrKlang.lib")	// link with irrKlang.dll

#include "AudioEngine.h"
#include "Singletons.h"

AudioEngine::AudioEngine() 
{
	audioEngine = createIrrKlangDevice();
}

AudioEngine::~AudioEngine() 
{
	audioEngine->drop();
}

void AudioEngine::Play2D(const char* filename, bool loop) 
{
	audioEngine->play2D(filename, loop);
}

void AudioEngine::Play3D(const char* filename, float x, float y, float z, bool loop) 
{
	audioEngine->play3D(filename, vec3df(x, y, z), loop);
}

void AudioEngine::SetVolume(float volume) 
{
	audioEngine->setSoundVolume(volume);
}



