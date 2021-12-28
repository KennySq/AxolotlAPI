#include<pch.h>
#include"AXVertexStage.cuh"
#include"AXInputAssembler.cuh"
#include"AXInputLayout.cuh"
#include"AXBuffer.cuh"
#include"AXFormat.h"

__device__ std::vector<AX_INPUT_ELEMENT>* gInputStructure;
__device__ std::vector<AX_INPUT_ELEMENT>* gOutputStructure;

__global__ void KernelVertexProcess_Sample(void* vertices, unsigned int vertexCount, unsigned int vertexStride, void* outPtr, std::vector<AX_INPUT_ELEMENT>* input, std::vector<AX_INPUT_ELEMENT>* output)
{
	// do compute based on vertex shader.
	// output structure must be determined before the vertex stage. (IA stage)

	unsigned int vertexOffset = threadIdx.x * vertexStride;
	void* vertex = (int*)vertices + vertexOffset;
	
	unsigned int inputCount = input->size();

	std::vector<void*> inputElements(inputCount);
	void* buffer;
	for (unsigned int i = 0; i < inputCount; i++)
	{
		void* offsetElement = (size_t*)vertex + (*input)[i].Offset;
		
		AX_PIXEL_DESC pixDesc = GetPixelDesc((*input)[i].Format);
		unsigned int elementByteSize = (pixDesc.Components * pixDesc.BitPerComponent) / 8;

		inputElements.push_back(offsetElement);

		// update from here 2021/12/28 11:38 AM

	}

	unsigned int outputCount = output->size();
	void* out = (int*)outPtr + vertexOffset;
	for (unsigned int i = 0; i < outputCount; i++)
	{
		void* offsetElement = (size_t*)outPtr + (*output)[i].Offset;

		unsigned int slotId = (*output)[i].Slot;

	}


	

	return;
}

AXVertexStage::AXVertexStage()
{
	cudaMalloc(reinterpret_cast<void**>(&gInputStructure), 4096);
	cudaMalloc(reinterpret_cast<void**>(&gOutputStructure), 4096);

	// --------------------------------------------------------

	AX_INPUT_ELEMENT outputElements[] =
	{
		{"SV_Position", 0, 0, 0, eAXFormat::AX_R32G32B32A32_FLOAT },
	};
	mOutputElements.push_back(outputElements[0]);
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
		
		unsigned int vertexStride = assembler->VertexStrides[i];
		unsigned int vertexCount = bufferDesc.ByteSize / assembler->VertexStrides[i];
		
		dim3 grid = dim3(vertexCount);
		dim3 block = dim3(32);

		std::vector<AX_INPUT_ELEMENT>* inputElements = &assembler->InputLayout->mElements;
		std::vector<AX_INPUT_ELEMENT>* outputElements = &mOutputElements;
		cudaMemcpy(gInputStructure, inputElements, inputElements->size() * sizeof(AX_INPUT_ELEMENT), cudaMemcpyHostToDevice);
		cudaMemcpy(gOutputStructure, outputElements, outputElements->size() * sizeof(AX_INPUT_ELEMENT), cudaMemcpyHostToDevice);

		KernelVertexProcess_Sample <<<grid, block>>>(virtualAddr, vertexCount, vertexStride, mVertexOutput, gInputStructure, gOutputStructure);
		cudaDeviceSynchronize();
	}
}
