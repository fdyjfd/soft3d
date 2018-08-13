#include "RasterizerState.h"

BEGIN_SOFT3D

RasterizerState::RasterizerState(const RasterizerDesc& desc) :
	m_desc(desc)
{}

RasterizerState* RasterizerState::New(const RasterizerDesc& desc)
{
	return new RasterizerState(desc);
}

END_SOFT3D
