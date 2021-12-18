#pragma once

struct Command
{
public:
	Command();
	Command(const Command& right);

	inline void Execute() const noexcept
	{
	}

	template<typename ...A>
	void test(void f(A...))
	{
		test(std::function<void(A...)>(f));
	}

	template<size_t _ArgCount, typename ... _ArgTy>
	inline void Bind(void f(_ArgTy ...), _ArgTy ... args)
	{
		//va_list arguments;
		//va_start(arguments, _ArgCount);

		////_ArgTy args[_ArgCount];

		//int result = 0;

		////for (unsigned int i = 0; i < _ArgCount; i++)
		////{
		////	args[i] = va_arg(arguments, _ArgTy);
		////}

		//va_end(arguments);
		
	//	std::bind(f, args ...);

		//std::function<void(_ArgTy&&)> fn;
		mFunc = std::bind(f, args...);
	
	}

private:

	std::function<void()> mFunc;
};

