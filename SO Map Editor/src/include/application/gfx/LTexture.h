#pragma once
#include "application\utils\LOpenGL.h"
#include "application\utils\variable\manager\TextureManager.h"

class LTexture {
private:
	static bool m_isInit;
public:
	static void init();
	// Use MTexture::getTexture!!!
	static Texture* loadTexture(std::string src);
	static void freeTex(GLuint id = -1);
};
