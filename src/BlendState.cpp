#include "BlendState.h"

BEGIN_SOFT3D

BlendState::BlendState(const BlendDesc& desc) :
	m_desc(desc)
{}

BlendState* BlendState::New(const BlendDesc& desc)
{
	return new BlendState(desc);
}

END_SOFT3D
