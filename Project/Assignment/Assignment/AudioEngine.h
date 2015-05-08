
#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H

#include "irrKlang\irrKlang.h"

using namespace irrklang;

#pragma comment(lib, "irrKlang.lib")	// link with irrKlang.dll

class AudioEngine {
	public:
		AudioEngine();
		~AudioEngine();
		void Play2D(const char* filename, bool loop);
		void SetVolume(float volume);

	private:
		ISoundEngine* audioEngine;

};

#endif
