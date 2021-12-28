#pragma once

enum eAXFormat;
struct AX_INPUT_ELEMENT
{
	const char* SemanticName;
	unsigned int Slot;
	unsigned int SemanticIndex;
	size_t Offset;
	eAXFormat Format;
};

struct AXInputLayout
{
	friend struct AXDevice;
	friend struct AXVertexStage;
public:

private:
	std::vector<AX_INPUT_ELEMENT> mElements;
	std::map<AX_INPUT_ELEMENT, void*> mInputOffset;

};