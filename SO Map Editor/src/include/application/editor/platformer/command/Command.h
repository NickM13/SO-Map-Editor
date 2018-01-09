#pragma once
#include "application\utils\Utilities.h"
#include <map>
#include <strstream>
#include <algorithm>
#include <functional>

struct KeyCommand {
private:
	std::function<void()> m_function;
public:
	KeyCommand(std::function<void()> p_function) {
		m_function = p_function;
	}
	void callFunction() {
		m_function();
	}
};
class MKeyCommand {
public:
	struct KeyBind {
		Sint32 keyCode, mods;
	};
private:
	static std::map<std::pair<Sint32, Sint32>, KeyCommand*> m_commands;
public:
	static void addCommand(KeyBind p_keyBind, KeyCommand* p_chatCmd);
	static void checkCommand(KeyBind p_keyBind);
};
