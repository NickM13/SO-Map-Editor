#include "application\editor\platformer\map\Map.h"

Map::Map() {
	m_mapSize = {16, 16};
	m_tileMap = new Uint16*[m_mapSize.x];
	for(Uint16 x = 0; x < m_mapSize.x; x++) {
		m_tileMap[x] = new Uint16[m_mapSize.y];
		for(Uint16 y = 0; y < m_mapSize.y; y++) {
			m_tileMap[x][y] = 0;
		}
	}
	m_grassTileset = new Tileset(MTexture::getTexture("tileset\\Grass.png"), TS);
	m_gridTex = MTexture::getTexture("gui\\Grid.png");
}
Map::~Map() {

}

void Map::setTile(Vector2<Sint32> p_pos, Uint16 p_tileId) {
	m_tileMap[p_pos.x][p_pos.y] = p_tileId;
}

bool Map::isPointOnMap(Vector2<Sint32> p_point) {
	return (p_point.x >= 0 && p_point.x < m_mapSize.x &&
		p_point.y >= 0 && p_point.y < m_mapSize.y);
}

void Map::input() {

}

void Map::update(GLfloat p_deltaUpdate) {

}

void Map::render() {
	glPushMatrix();
	{
		glBindTexture(GL_TEXTURE_2D, 0);
		glColor3f(1, 1, 1);
		for(Uint16 x = 0; x < m_mapSize.x; x++) {
			for(Uint16 y = 0; y < m_mapSize.y; y++) {
				glPushMatrix();
				{
					glTranslatef(x*TS, y*TS, 0);
					m_grassTileset->renderTile(m_tileMap[x][y]);
				}
				glPopMatrix();
			}
		}
		glBindTexture(GL_TEXTURE_2D, m_gridTex->getId());
		glBegin(GL_QUADS);
		{
			glTexCoord2f(0, 0);							glVertex2f(0, 0);
			glTexCoord2f(m_mapSize.x, 0);				glVertex2f(m_mapSize.x * TS, 0);
			glTexCoord2f(m_mapSize.x, m_mapSize.y);		glVertex2f(m_mapSize.x * TS, m_mapSize.y * TS);
			glTexCoord2f(0, m_mapSize.y);				glVertex2f(0, m_mapSize.y * TS);
		}
		glEnd();
	}
	glPopMatrix();
}
