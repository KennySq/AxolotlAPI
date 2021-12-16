#pragma once


struct IAXResource
{
	friend struct AXContext;
protected:
	void* mRaw;
};