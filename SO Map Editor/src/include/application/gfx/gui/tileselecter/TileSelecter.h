#pragma once

#include "application\utils\Utilities.h"
#include "..\Component.h"
#include "application\gfx\font\Font.h"

class CTileSelecter : public Component
{
public:
	CTileSelecter(std::string p_compName, Vector2<Sint32> p_pos, function p_func = 0);

	void input(Sint8& p_interactFlags, Vector2<Sint32> p_mousePos);
	void update(GLfloat p_deltaUpdate);
	virtual void render();

	void setState(Sint8 p_selected);

	Sint8 isSelected(); // 0 = not selected, 1 = pressed, 2 = is held, 3 = released
	bool isHovered() { return m_hover; };
	void setHover(bool p_state) { m_hover = p_state; };
protected:
	Texture m_tileSheet;

	bool m_hover;
	bool m_stuck;
};
