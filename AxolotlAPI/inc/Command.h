#pragma once

struct Command
{
public:
	Command();
	Command(const Command& right);

	inline void Execute() const noexcept
	{
		mFunc();
	}

private:
	std::function<void()> mFunc;

};

