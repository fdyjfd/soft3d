#include "Sampler.h"

BEGIN_SOFT3D

Sampler::Sampler(const SamplerDesc& desc) :
	m_desc(desc)
{}

Sampler* Sampler::New(const SamplerDesc& desc)
{
	return new Sampler(desc);
}

END_SOFT3D

