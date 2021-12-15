#pragma once

#include"Command.h"

struct AXCommandList
{
	friend struct AXDevice;
	friend struct AXContext;
	AXCommandList();
	~AXCommandList();
	AXCommandList(const AXCommandList& right) = delete;
private:
	std::vector<Command> mCommands;
	bool mbClosed;
};