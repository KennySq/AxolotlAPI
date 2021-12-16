#include"pch.h"
#include"Command.h"

Command::Command(std::function<void(...)> func, ...)
	: mFunc(func)
{
}

Command::Command(const Command& right)
	: mFunc(right.mFunc)
{

}
