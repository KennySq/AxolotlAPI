#pragma once
struct AXBuffer;
struct AXInputAssembler
{
	std::vector<std::shared_ptr<AXBuffer>> VertexBuffers;
	std::vector<unsigned int> VertexStrides;

	std::shared_ptr<AXBuffer> IndexBuffer;
	// primitive topology.
	// input layout.
};