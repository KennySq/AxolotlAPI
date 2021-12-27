#pragma once

enum eAXFormat;
struct AX_INPUT_ELEMENT
{
	const char* SemanticName;
	unsigned int Slot;
	unsigned int SemanticIndex;
	eAXFormat Format;
};

struct AXInputLayout
{
	friend struct AXDevice;
public:

private:
	std::vector<AX_INPUT_ELEMENT> mElements;

};