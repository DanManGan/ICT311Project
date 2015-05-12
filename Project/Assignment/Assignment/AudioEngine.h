
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
		void AddSoundSource(const char* filename);
		ISoundSource* GetSoundSource(const char* filename);
		void Stop(const char* filename);
		bool GetIsPlaying(const char* filename);

	private:
		ISoundEngine* audioEngine;
		bool isPlaying;
};

#endif
