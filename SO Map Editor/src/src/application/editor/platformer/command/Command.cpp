#include "application\editor\platformer\command\Command.h"
#include <locale>

std::map<std::pair<Sint32, Sint32>, KeyCommand*> MKeyCommand::m_commands;

void MKeyCommand::addCommand(KeyBind p_keyBind, KeyCommand * p_chatCmd) {
	m_commands.insert({{p_keyBind.keyCode, p_keyBind.mods}, p_chatCmd});
}
void MKeyCommand::checkCommand(MKeyCommand::KeyBind p_keyBind) {
	if(m_commands.find({p_keyBind.keyCode, p_keyBind.mods}) != m_commands.end())
		m_commands[{p_keyBind.keyCode, p_keyBind.mods}]->callFunction();
}
