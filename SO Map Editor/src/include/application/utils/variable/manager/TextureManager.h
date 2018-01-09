#pragma once
#include "Manager.h"
#include "application\utils\variable\datatype\Texture.h"

class MTexture {
private:
	static ManagerMap<std::string, Texture*> m_manager;
public:
	// res/gfx/...
	static Texture* getTexture(std::string p_filePath);
};
