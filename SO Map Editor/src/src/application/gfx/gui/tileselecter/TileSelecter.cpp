#include "application\gfx\gui\tileselecter\TileSelecter.h"
#include "application\editor\platformer\map\Map.h"

CTileSelecter::CTileSelecter(std::string p_compName, Vector2<Sint32> p_pos, function p_func)
	: Component(p_compName, "", p_pos, Vector2<Sint32>(Map::getTileSize() * 3, Map::getTileSize() * 3), ACTION) {
	m_selected = 0;
	m_texture = -1;
	m_releaseFunction = p_func;
}
void CTileSelecter::input(Sint8& p_interactFlags, Vector2<Sint32> p_mousePos) {
	if((p_interactFlags & EVENT_MOUSEOVER) &&
		p_mousePos.x >= m_pos.x && p_mousePos.x <= m_pos.x + m_size.x &&
		p_mousePos.y >= m_pos.y && p_mousePos.y <= m_pos.y + m_size.y) {
		if(!m_hover) {
			m_hover = true;
		}
	}
	else if(m_hover) {
		m_hover = false;
	}

	if(m_hover)
		addTooltip();

	if(GMouse::mouseDown(GLFW_MOUSE_BUTTON_LEFT)) {
		if(m_hover || m_selected != 0) {
			if(GMouse::mousePressed(GLFW_MOUSE_BUTTON_LEFT)) {
				if(m_selected == 0) {
					m_selected = 1;
					if(m_pressFunction) m_pressFunction();
				}
				else m_selected = 2;
			}
		}
		else m_selected = 0;
	}
	else {
		if(m_selected == 1 || m_selected == 2) {
			m_selected = 3;
		}
		else if(m_selected == 3) {
			m_selected = 0;
			if(m_releaseFunction) m_releaseFunction();
		}
	}
}
void CTileSelecter::update(GLfloat p_deltaUpdate) {
	if(m_stuck) {
		m_selected = 0;
		m_stuck = false;
	}
	else if(m_selected == 3)
		m_stuck = true;
	else
		m_stuck = false;
}
void CTileSelecter::render() {
	glBindTexture(GL_TEXTURE_2D, 0);

	glPushMatrix();
	{
		glTranslatef(GLfloat(m_pos.x), GLfloat(m_pos.y), 0);
		glTranslatef(GLfloat(m_size.x / 2), GLfloat(m_size.y / 2), 0);

		glPushMatrix();
		{
			glColor3f(1, 1, 1);
			glBindTexture(GL_TEXTURE_2D, m_tileSheet.getId());
			glBegin(GL_QUADS);
			{
				glTexCoord2f(0, 1);
				glVertex2f(-GLfloat(m_tileSheet.getSize().x) / 2, -GLfloat(m_tileSheet.getSize().y) / 2);
				glTexCoord2f(1, 1);
				glVertex2f(GLfloat(m_tileSheet.getSize().x) / 2, -GLfloat(m_tileSheet.getSize().y) / 2);
				glTexCoord2f(1, 0);
				glVertex2f(GLfloat(m_tileSheet.getSize().x) / 2, GLfloat(m_tileSheet.getSize().y) / 2);
				glTexCoord2f(0, 0);
				glVertex2f(-GLfloat(m_tileSheet.getSize().x) / 2, GLfloat(m_tileSheet.getSize().y) / 2);
			}
			glEnd();
		}
		glPopMatrix();


		m_colorTheme.m_text.useColor();
		Font::setAlignment(ALIGN_CENTER);
		Font::print(m_title, 0, 0);
	}
	glPopMatrix();
}

void CTileSelecter::setState(Sint8 p_selected) {
	m_selected = p_selected;
	if(p_selected == 1 && m_releaseFunction != 0)
		m_releaseFunction();
}

Sint8 CTileSelecter::isSelected() {
	if(!m_visible) return 0;
	return m_selected;
}
