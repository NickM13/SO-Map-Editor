#pragma once
#include "map\Map.h"
#include "application\gfx\LGui.h"
#include "application\utils\Utilities.h"

class Platformer {
private:
	Map* m_map;
	Container* m_gui;
	Texture* m_tileSelectTex;

	Vector2<GLfloat> m_camPos;
	Vector2<Sint32> m_selectedTile;
public:
	Platformer();
	~Platformer();

	void input();
	void update(GLfloat p_deltaUpdate);
	void render();
};
