#pragma once

#include "Utility.h"

namespace soft3d
{
	enum class FilterType
	{
		min_mag_mip_point,
		min_mag_point_mip_linear,
		min_point_mag_linear_mip_point,
		min_point_mag_mip_linear,
		min_linear_mag_mip_point,
		min_linear_mag_point_mip_linear,
		min_mag_linear_mip_point,
		min_mag_mip_linear,
		anisotropic,
	};

	enum TextureAddressMode
	{
		wrap,
		mirror,
		clamp,
		border,
		mirror_once
	};

	struct SamplerDesc
	{
		FilterType filter;
		TextureAddressMode addressU;
		TextureAddressMode addressV;
		TextureAddressMode addressW;
		ComparisonFunc comparisonFunc;
		float mipLODBias;
		s3d_uint32 maxAnisotropy;
		float borderColor[4];
		float minLOD;
		float maxLOD;
	};

	class Sampler
	{
	public:
		Sampler(const SamplerDesc& desc);
	public:
		SamplerDesc m_desc;
	public:
		static SamplerDesc s_defaultDesc;
	};

	//-------------------------------------------------------
	inline Sampler::Sampler(const SamplerDesc& desc) :
		m_desc(desc)
	{}

}
