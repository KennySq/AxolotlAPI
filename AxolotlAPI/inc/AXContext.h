#pragma once

struct Command;
struct AXCommandList;
struct AXRenderTargetView;
struct AXBuffer;
struct AXInputAssembler;
struct AXVertexStage;
struct AXRasterizer;
struct AXOutputMerger;
struct AXPixelStage;
#define CREATE_AXDEVICE_DEBUG 0xffffffff

struct AXContext
{
public:
	AXContext(unsigned int flag);
	~AXContext();

	void IASetVertexBuffer(std::shared_ptr<AXBuffer>* const buffer, unsigned int count, unsigned int* const stride, unsigned int* const offset);
	void IASetIndexBuffer(std::shared_ptr<AXBuffer> buffer);

	void DrawIndexed(unsigned int indexCount, unsigned int offset);

	void ClearRenderTarget(std::shared_ptr<AXRenderTargetView> rtv, float clearColor[4]);

	void ExecuteCommandList(const std::shared_ptr<AXCommandList>& cmdList) const;
	void FinishCommandList(std::shared_ptr<AXCommandList>* cmdList);
private:
	std::vector<Command> mCommandBuffer;
	unsigned int mFlag;
	unsigned int mCommandIndex;

	std::shared_ptr<AXInputAssembler> mAssembler;
	std::shared_ptr<AXVertexStage> mVertexStage;
	std::shared_ptr<AXRasterizer> mRasterStage;
	std::shared_ptr<AXOutputMerger> mOutputStage;
	std::shared_ptr<AXPixelStage> mPixelStage;

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