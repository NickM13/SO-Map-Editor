#pragma once
#include "application\gfx\font\Font.h"
#include "application\gfx\LTexture.h"
#include "application\gfx\sprite\SpriteAnimation.h"

#include "application\sfx\Sound.h"

#include "application\utils\global\event\GKey.h"
#include "application\utils\global\event\GMouse.h"
#include "application\utils\global\GScreen.h"
#include "application\utils\LOpenGL.h"
#include "application\utils\Singleton.h"
#include "application\utils\Utilities.h"
#include "application\utils\variable\datatype\Rectangle.h"
#include "application\utils\variable\manager\TextureManager.h"

#include "application\gfx\gui\container\Container.h"

#include "application\editor\platformer\Platformer.h"

#include <vector>

class Editor {
protected:
	Platformer* m_platformer;

	GLfloat m_lastUpdate, m_deltaUpdate;
	Vector2<Sint32> m_mouseBuffer;
	Texture *m_vignette;		// Shading around edges of screen
	SpriteAnimation *m_cursor;	// Custom cursor

	void renderMouse();
	void renderVignette();
public:
	enum GameState {
		MENU = 0,
		GAME = 1
	} m_gameState;

	Editor();
	~Editor();
	void resize();

	void setGameState(GameState p_state);
	//World* getWorld() { return m_world; }

	void input();
	void update();
	void render2d();
};
