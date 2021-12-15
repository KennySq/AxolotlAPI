#include<pch.h>
#include "..\inc\AXChain.h"

AXChain::AXChain()
{
}

AXChain::~AXChain()
{
}

void AXChain::Present()
{

}

std::shared_ptr<AXChain> AXCreateChain(unsigned int flag)
{
	std::shared_ptr<AXChain> chain = std::make_shared<AXChain>();



	return chain;
}
