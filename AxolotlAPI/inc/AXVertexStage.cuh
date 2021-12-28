#pragma once
struct AXBuffer;
struct AXInputAssembler;
struct AX_INPUT_ELEMENT;

struct AXVertexStage
{
public:
	AXVertexStage();
	~AXVertexStage();
	
	void Process(std::shared_ptr<AXInputAssembler> assembler);

	void* GetOutput() const { return mVertexOutput; }

private:
	std::vector<AX_INPUT_ELEMENT> mOutputElements;
	void* mVertexOutput;
};