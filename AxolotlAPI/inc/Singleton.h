#pragma once

template<class _Ty>
struct Singleton
{
public:
	static _Ty* Make()
	{
		if (mInstance == nullptr)
		{
			mInstance = new _Ty();
		}
	}
	static void Destroy()
	{
		if (mInstance != nullptr)
		{
			delete mInstance;
			mInstance = nullptr;
		}
	}

	static _Ty* GetInstance() const { return mInstance; }
private:
	static _Ty* mInstance;

};