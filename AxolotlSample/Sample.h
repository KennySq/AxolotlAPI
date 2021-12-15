#pragma once

#include<Axolotl.h>

#include<iostream>

#pragma comment(lib, "Axolotl.lib")

struct SampleApp
{
public:
	SampleApp();
	~SampleApp();

	void Init();
	void Update(float delta);
	void Render(float delta);
	void Release();
private:
	std::shared_ptr<AXDevice> mDevice;

};