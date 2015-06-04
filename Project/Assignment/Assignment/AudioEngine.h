/** 
  * @class AudioEngine
  * @brief The facade class for the audio engine
  * 
  * 
  * @author Daniel Manganaro
  * @version 01
  * @date 5.04.15
  *
  * @todo 
  * 
  * @bugs 
  */

#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H

#include <irrKlang/irrKlang.h>

using namespace irrklang;

class AudioEngine {
	public:
	/** 
	  * @brief Default constructor
	  * @warning None
	  * 
	  * Default class constructor
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
		AudioEngine();

	/** 
	  * @brief Default deconstructor
	  * @warning None
	  * 
	  * Default class deconstructor
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
		~AudioEngine();

	/** 
	  * @brief Plays a 2D sound
	  * @warning None
	  * 
	  * @param const char* filename - path to the sound file
	  * @param bool loop - is the sound looping?
	  * 
	  * @pre 
	  * @post 
	  */
		void Play2D(const char* filename, bool loop);

	/** 
	  * @brief Plays a 3D sound
	  * @warning None
	  * 
	  * @param const char* filename - path to the sound file
	  * @param float x - x position of the sound
	  * @param float y - y position of the sound
	  * @param float z - z position of the sound
	  * @param bool loop - is the sound looping?
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
		void Play3D(const char* filename, float x, float y, float z, bool loop);

	/** 
	  * @brief Sets the volume of all sounds
	  * @warning None
	  * 
	  * @param float volume - volume of sounds
	  * 
	  * @pre 
	  * @post 
	  */
		void SetVolume(float volume);

	/** 
	  * @brief Adds a sound source from sound file
	  * @warning None
	  * 
	  * @param const char* filename - path to the sound file
	  * 
	  * @pre 
	  * @post 
	  */
		void AddSoundSource(const char* filename);

	/** 
	  * @brief Returns the sound source of specified sound
	  * @warning None
	  * 
	  * @param const char* filename - name of the sound file
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
		ISoundSource* GetSoundSource(const char* filename);

	/** 
	  * @brief Stop a specified sound
	  * @warning None
	  * 
	  * @param const char* filename - name of the sound file
	  * 
	  * @pre 
	  * @post 
	  */
		void Stop(const char* filename);

	/** 
	  * @brief Return true if specified sound is playing 
	  * @warning None
	  * 
	  * @param const char* filename - name of sound file
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
		bool GetIsPlaying(const char* filename);

	private:

	/** 
	  * @brief Reference to the audio engine
	  * @warning None
	  * 
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
		ISoundEngine* audioEngine;

	/** 
	  * @brief bool is sound currently playing
	  * @warning None
	  * 
	  * 
	  * 
	  * @pre 
	  * @post 
	  */
		bool isPlaying;
};

#endif
