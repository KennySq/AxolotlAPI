#pragma once
struct AXBuffer;
struct AXInputAssembler;

struct AXVertexStage
{
public:
	AXVertexStage();
	~AXVertexStage();
	
	void Process(std::shared_ptr<AXInputAssembler> assembler);

	void* GetOutput() const { return mVertexOutput; }

private:
	void* mVertexOutput;
};