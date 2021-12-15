#pragma once

struct Command;
struct AXCommandList;
struct AXRenderTargetView;

struct AXContext
{
public:
	void ClearRenderTarget(std::shared_ptr<AXRenderTargetView> rtv, float clearColor[4]);

	void ExecuteCommandList(const std::shared_ptr<AXCommandList>& cmdList) const;
	void FinishCommandList(std::shared_ptr<AXCommandList>* cmdList);
private:
	std::vector<Command> mCommandBuffer;

};
