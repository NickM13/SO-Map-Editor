#include "application\editor\Editor.h"

#include "application\gfx\font\Font.h"

#include "application\utils\global\GGameState.h"

#include <functional>
#include <iostream>

Editor::Editor() {
	m_gameState = GAME;
	LTexture::init();
	Font::loadFont("Console", "consolas.ttf", 10);
	Font::loadFont("UI", "segoeui.ttf", 10);
	m_cursor = new SpriteAnimation(MTexture::getTexture("gui\\Cursor.png"), 0.15f);
	m_cursor->pushSpriteRepeated({0, 0}, {22, 0}, {22, 22}, 8);
	m_vignette = MTexture::getTexture("gui\\Vignette.png");
	Sound::init();
	/* Load sound files here */

	m_platformer = new Platformer();
}
Editor::~Editor() {
	Sound::close();
	delete m_platformer;
}

void Editor::resize() {

}

void Editor::setGameState(GameState p_state) {
	if(m_gameState != p_state)
	{
		m_gameState = p_state;
		switch(m_gameState)
		{
		case MENU:

			break;
		case GAME:

			break;
		}
	}
}

void Editor::input() {
	Vector2<Sint32> _mouseDelta = GMouse::getMousePos() - m_mouseBuffer;
	m_platformer->input();
}
void Editor::update() {
	m_deltaUpdate = min(10.f/60, GLfloat(glfwGetTime() - m_lastUpdate));
	GScreen::m_deltaTime = m_deltaUpdate;

	switch(m_gameState)
	{
	case MENU:

		break;
	case GAME:
		m_platformer->update(m_deltaUpdate);
		break;
	}
	m_lastUpdate += m_deltaUpdate;
}
void Editor::renderMouse() {
	glPushMatrix();
	{
		glTranslatef(GLfloat(GMouse::getMousePos().x), GLfloat(GMouse::getMousePos().y), 0);
		m_cursor->render();
	}
	glPopMatrix();
}
void Editor::renderVignette() {
	glBindTexture(GL_TEXTURE_2D, m_vignette->getId());
	glColor3f(1, 1, 1);
	glTranslatef(-GScreen::m_screenSize.x / 2, -GScreen::m_screenSize.y / 2, 0);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0, 0); glVertex2f(0, 0);
		glTexCoord2f(1, 0); glVertex2f(GScreen::m_screenSize.x, 0);
		glTexCoord2f(1, 1); glVertex2f(GScreen::m_screenSize.x, GScreen::m_screenSize.y);
		glTexCoord2f(0, 1); glVertex2f(0, GScreen::m_screenSize.y);
	}
	glEnd();
}
void Editor::render2d() {
	Font::setFont("UI");
	switch(m_gameState) {
	case MENU:

		break;
	case GAME:
		m_platformer->render();
		renderMouse();
		break;
	}
	renderVignette();
}
