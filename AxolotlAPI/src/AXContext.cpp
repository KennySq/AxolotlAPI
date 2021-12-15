#include "pch.h"
#include "AXContext.h"
#include"AXCommandList.h"
#include"Command.h"

#include"AXRenderTargetView.cuh"

void AXContext::ClearRenderTarget(std::shared_ptr<AXRenderTargetView> rtv, float clearColor[4])
{
	
}

void AXContext::ExecuteCommandList(const std::shared_ptr<AXCommandList>& cmdList) const
{
	unsigned int size = cmdList->mCommands.size();

	for (unsigned int i = 0; i < size; i++)
	{
		cmdList->mCommands[i].Execute();
	}

	cmdList->mbClosed = false;
}

void AXContext::FinishCommandList(std::shared_ptr<AXCommandList>* cmdList)
{
	unsigned int size = mCommandBuffer.size();

	for (unsigned int i = 0; i < size; i++)
	{
		Command cmd = mCommandBuffer[i];
		(*cmdList)->mCommands.push_back(cmd);
	}
	(*cmdList)->mbClosed = true;

	mCommandBuffer.clear();
}
