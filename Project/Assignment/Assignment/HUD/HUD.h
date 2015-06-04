#ifndef HUD_H
#define HUD_H

#include"HUD_Frame.h"

#include<map>
#include<string>

class HUD
{
public:
	HUD() {frames = 0;};

	void AddFrame(std::string name) {m_HUDFrame[name] = new HUD_Frame;};

	HUD_Frame* Frame(std::string name) { return m_HUDFrame[name];};

	void RenderFrame(std::string name) {m_HUDFrame[name]->Render();};

private:
	int frames;

	typedef std::map<std::string, HUD_Frame*> HUD_Frames;
	HUD_Frames m_HUDFrame;
};

#endif