#pragma once
struct AXBuffer;
struct AXInputAssembler;
struct AX_INPUT_ELEMENT;
struct AXDeviceMemoryPool;
struct AXVertexStage
{
public:
	AXVertexStage(std::shared_ptr<AXDeviceMemoryPool> device);
	~AXVertexStage();
	
	void Process(std::shared_ptr<AXInputAssembler> assembler);

	void* GetOutput() const { return mVertexOutput; }

private:
	void* mVertexOutput;

	std::vector<AX_INPUT_ELEMENT>* mOutputElements;
	std::vector<AX_INPUT_ELEMENT>* mInputElements;

	std::vector<AX_INPUT_ELEMENT> mHostOutputElements;
};