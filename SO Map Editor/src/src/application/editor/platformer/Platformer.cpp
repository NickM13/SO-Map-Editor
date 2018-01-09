#include "application\editor\platformer\Platformer.h"

Platformer::Platformer() {
	m_map = new Map();
	m_gui = new Container("MAIN_GUI", GScreen::m_screenSize / -2, GScreen::m_screenSize, true);
	m_tileSelectTex = MTexture::getTexture("gui\\TileSelect.png");
}
Platformer::~Platformer() {
	delete m_map;
}

void Platformer::input() {
	if(GMouse::mouseDown(GLFW_MOUSE_BUTTON_RIGHT)) {
		m_camPos = m_camPos - GMouse::getDeltaMousePos();
	}
	m_map->input();
	m_gui->input();
}

void Platformer::update(GLfloat p_deltaUpdate) {
	m_selectedTile = Vector2<Sint32>((Vector2<GLfloat>(GMouse::getMousePos() - m_camPos) / m_map->getTileSize()).floor());
	
	m_map->update(p_deltaUpdate);
	m_gui->update(p_deltaUpdate);
}

void Platformer::render() {
	glPushMatrix();
	{
		glTranslatef(m_camPos.x, m_camPos.y, 0);
		m_map->render();
		glTranslatef(m_selectedTile.x * m_map->getTileSize(), m_selectedTile.y * m_map->getTileSize(), 0);
		if(m_map->isPointOnMap(m_selectedTile))
			m_tileSelectTex->render();
	}
	glPopMatrix();
	m_gui->render();
}
