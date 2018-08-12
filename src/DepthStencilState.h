#pragma once

#include "Utility.h"

namespace soft3d
{
	enum DepthWriteMask
	{
		zero,
		all,
	};

	enum class StencilOperation
	{
		keep,
		zero,
		replace,
		incr_sat,
		decr_sat,
		invert,
		incr,
		decr,
	};

	struct DepthStencilDesc
	{
		bool depthEnable;
		DepthWriteMask depthWriteMask;
		ComparisonFunc depthFunc;
		bool stencilEnable;
		s3d_uint8 stencilReadMask;
		s3d_uint8 stencilWriteMask;
		StencilOperation frontFace;
		StencilOperation backFace;
	};

	class DepthStencilState
	{
	public:
		DepthStencilDesc m_desc;
	public:
		static DepthStencilDesc s_defaultDesc;
	};

	//----------------------------------------------------
}
