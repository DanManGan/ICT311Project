
#include "AudioEngine.h"
#include "Singletons.h"

AudioEngine::AudioEngine() {
	audioEngine = createIrrKlangDevice();
}

AudioEngine::~AudioEngine() {
	audioEngine->drop();
}

void AudioEngine::Play2D(const char* filename, bool loop) {
	audioEngine->play2D(filename, loop);
}

void AudioEngine::SetVolume(float volume) {
	audioEngine->setSoundVolume(volume);
}

