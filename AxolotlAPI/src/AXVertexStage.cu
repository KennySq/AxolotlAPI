#include<pch.h>
#include"AXVertexStage.cuh"
#include"AXInputAssembler.cuh"
#include"AXBuffer.cuh"

__global__ void KernelVertexProcess(void* vertices, unsigned int vertexCount, void* outPtr)
{
	// do compute based on vertex shader.
	// output structure must be determined before vertex stage. (IA stage)


	return;
}

AXVertexStage::AXVertexStage()
{
}

AXVertexStage::~AXVertexStage()
{
}

void AXVertexStage::Process(std::shared_ptr<AXInputAssembler> assembler)
{
	unsigned int vbCount = assembler->VertexBuffers.size();
	for (unsigned int i = 0; i < vbCount; i++)
	{
		std::shared_ptr<AXBuffer> buffer = assembler->VertexBuffers[i];

		void* virtualAddr = buffer->GetVirtual();

		AX_BUFFER_DESC bufferDesc = buffer->GetDesc();
		unsigned int vertexCount = bufferDesc.ByteSize / assembler->VertexStrides[i];

		dim3 grid = dim3(vertexCount);
		dim3 block = dim3(32);
		KernelVertexProcess<<<grid, block>>>(virtualAddr, vertexCount, mVertexOutput);
	}
}
