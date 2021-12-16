#pragma once

struct Command;
struct AXCommandList;
struct AXRenderTargetView;
#define CREATE_AXDEVICE_DEBUG 0xffffffff

struct AXContext
{
public:
	AXContext(unsigned int flag);
	~AXContext();

	void ClearRenderTarget(std::shared_ptr<AXRenderTargetView> rtv, float clearColor[4]);

	void ExecuteCommandList(const std::shared_ptr<AXCommandList>& cmdList) const;
	void FinishCommandList(std::shared_ptr<AXCommandList>* cmdList);
private:
	std::vector<Command> mCommandBuffer;
	unsigned int mFlag;
};

static inline std::shared_ptr<AXContext> AXCreateContext(unsigned int flag)
{
	std::shared_ptr<AXContext> context = std::make_shared<AXContext>(flag);

	if (flag & CREATE_AXDEVICE_DEBUG)
	{
		std::cout << "Debug Layer Active.\n";
		OutputDebugStringA("Debug Layer Active.\n");
	}

	return context;
}