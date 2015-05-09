
#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H

#include <irrKlang/irrKlang.h>

using namespace irrklang;

class AudioEngine {
	public:
		AudioEngine();
		~AudioEngine();
		void Play2D(const char* filename, bool loop);
		void Play3D(const char* filename, float x, float y, float z, bool loop);
		void SetVolume(float volume);

	private:
		ISoundEngine* audioEngine;

};

#endif
