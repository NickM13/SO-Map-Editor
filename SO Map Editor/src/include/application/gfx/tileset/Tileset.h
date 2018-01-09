#pragma once
#include "..\LTexture.h"

class Tileset {
private:
	Texture *m_tileset;
	Sint32 m_tileSize;
	
	Vector2<Sint32> m_tileCount;
public:
	Tileset(Texture *p_tileset, Sint32 p_tileSize) 
		: m_tileset(p_tileset), m_tileSize(p_tileSize) {
		m_tileCount.x = m_tileset->getSize().x / p_tileSize;
		m_tileCount.y = m_tileset->getSize().y / p_tileSize;
	}

	void renderTile(Sint32 p_tileIndex) {
		renderTile(p_tileIndex % m_tileCount.x, p_tileIndex / m_tileCount.x);
	}
	void renderTile(Sint32 p_tileX, Sint32 p_tileY) {
		Vector4<GLfloat> m_texCoords;
		m_texCoords.x1 = GLfloat(p_tileX) / m_tileCount.x;
		m_texCoords.y1 = 1.f - GLfloat(p_tileY) / m_tileCount.y;
		m_texCoords.x2 = GLfloat(p_tileX + 1) / m_tileCount.x;
		m_texCoords.y2 = 1.f - GLfloat(p_tileY + 1) / m_tileCount.y;

		glBindTexture(GL_TEXTURE_2D, m_tileset->getId());
		glBegin(GL_QUADS);
		{
			glTexCoord2f(m_texCoords.x1, m_texCoords.y1); glVertex2f(0, 0);
			glTexCoord2f(m_texCoords.x2, m_texCoords.y1); glVertex2f(m_tileSize, 0);
			glTexCoord2f(m_texCoords.x2, m_texCoords.y2); glVertex2f(m_tileSize, m_tileSize);
			glTexCoord2f(m_texCoords.x1, m_texCoords.y2); glVertex2f(0, m_tileSize);
		}
		glEnd();
	}
};
