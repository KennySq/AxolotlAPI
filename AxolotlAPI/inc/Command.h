#pragma once

struct Command
{
public:
	Command(std::function<void(const char*, va_list)> func, ...);
	Command(const Command& right);

	inline void Execute() const noexcept
	{
		//mFunc.target(mArguments);
		// update from here 2021/12/16 10:38 PM
	}

private:
	std::function<void(...)> mFunc;
	va_list mArguments;
};

