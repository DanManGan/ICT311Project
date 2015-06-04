#include"HUD_Frame.h"
#include"HUD_Factory.h"
#include"../Singletons.h"

HUD_Frame::HUD_Frame()
{
	elements = 0;
}

//--------------------------------------------------------------------------------------

void HUD_Frame::CreateShape(std::string name,
							float x, float y, float w, float h,
							float r, float g, float b)
{
	m_HUD[name] = HUDFactory->Create("hud_shape");
	m_HUD[name]->SetX(x);
	m_HUD[name]->SetY(y);
	m_HUD[name]->SetWidth(w);
	m_HUD[name]->SetHeight(h);
	((HUD_Shape*)m_HUD[name])->SetColor(r, g, b);
}

//--------------------------------------------------------------------------------------

void HUD_Frame::CreatePicture(std::string name,
							float x, float y, float w, float h,
							unsigned int texture)
{
	m_HUD[name] = HUDFactory->Create("hud_picture");
	m_HUD[name]->SetX(x);
	m_HUD[name]->SetY(y);
	m_HUD[name]->SetWidth(w);
	m_HUD[name]->SetHeight(h);
	((HUD_Picture*)m_HUD[name])->SetTexture(texture);
}

//--------------------------------------------------------------------------------------

void HUD_Frame::CreateText(std::string name,
							float x, float y, float w, float h,
							float r, float g, float b,
							std::string text)
{
	m_HUD[name] = HUDFactory->Create("hud_text");
	m_HUD[name]->SetX(x);
	m_HUD[name]->SetY(y);
	m_HUD[name]->SetWidth(w);
	m_HUD[name]->SetHeight(h);
	((HUD_Text*)m_HUD[name])->SetColor(r, g, b);
	((HUD_Text*)m_HUD[name])->SetText(text);
}

//--------------------------------------------------------------------------------------

HUD_Element* HUD_Frame::getElement(std::string name)
{
	return m_HUD[name];
}

//--------------------------------------------------------------------------------------

void HUD_Frame::Render()
{
	for(ElementIter itr = m_HUD.begin(); itr != m_HUD.end(); itr++)
	{
		itr->second->Render();
	}
}