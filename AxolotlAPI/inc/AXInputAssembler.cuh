#pragma once
struct AXBuffer;
struct AXInputLayout;
struct AXInputAssembler
{
	std::vector<std::shared_ptr<AXBuffer>> VertexBuffers;
	std::vector<unsigned int> VertexStrides;

	std::shared_ptr<AXBuffer> IndexBuffer;
	std::shared_ptr<AXInputLayout> InputLayout;
	// primitive topology.
	// input layout.
};