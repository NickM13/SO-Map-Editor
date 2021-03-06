#include "application\gfx\gui\field\DataField.h"

void DataField::input(Sint8& p_interactFlags)
{
	Vector2<Sint32> _mousePos = GMouse::getMousePos();
	if((p_interactFlags & EVENT_MOUSEOVER) && _mousePos.x >= 0 && _mousePos.x < m_size.x
		&& _mousePos.y >= 0 && _mousePos.y < m_size.y)
	{
		addTooltip();
		if(GMouse::mousePressed(GLFW_MOUSE_BUTTON_LEFT))
			m_selected = 1;
	}
	else if(GMouse::mousePressed(GLFW_MOUSE_BUTTON_LEFT))
		m_selected = 0;

	if((p_interactFlags & EVENT_MOUSEOVER) &&
		_mousePos.x >= 0 && _mousePos.x < m_size.x
		&& _mousePos.y >= 0 && _mousePos.y < m_size.y)
		p_interactFlags -= EVENT_MOUSEOVER;
}

void DataField::update(GLfloat p_deltaUpdate)
{

}

void DataField::render()
{
	glPushMatrix();
	{
		glBindTexture(GL_TEXTURE_2D, 0);
		glTranslatef(GLfloat(m_pos.x), GLfloat(m_pos.y), 0);
		m_colorTheme.m_text.useColor();
		Font::setAlignment(ALIGN_LEFT);
		Font::print(*m_dataString, 0, Sint32(Font::getHeight()));
	}
	glPopMatrix();
}
