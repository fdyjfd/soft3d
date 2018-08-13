#include "DepthStencilState.h"

BEGIN_SOFT3D

DepthStencilState::DepthStencilState(const DepthStencilDesc& desc) :
	m_desc(desc)
{}

DepthStencilState* DepthStencilState::New(const DepthStencilDesc& desc)
{
	return new DepthStencilState(desc);
}

END_SOFT3D
