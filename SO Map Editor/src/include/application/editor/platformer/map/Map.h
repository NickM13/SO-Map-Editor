#pragma once
#include "application\utils\Utilities.h"
#include "application\gfx\LTexture.h"
#include "application\gfx\tileset\Tileset.h"

#define TS 32

class Map {
private:
	struct Tile {
		int tilesheetId;
	};

	Vector2<Sint32> m_mapSize;
	Uint16 **m_tileMap;
	Tileset *m_grassTileset;
	Texture *m_gridTex;
public:
	Map();
	~Map();

	void setTile(Vector2<Sint32> p_pos, Uint16 p_tileId);
	static GLfloat getTileSize() { return TS; }

	bool isPointOnMap(Vector2<Sint32> p_point);

	void input();
	void update(GLfloat p_deltaUpdate);
	void render();
};
