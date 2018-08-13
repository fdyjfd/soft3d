#pragma once

#include "RefCount.h"

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

	class DepthStencilState : public RefCount
	{
	public:
		DepthStencilState(const DepthStencilDesc& desc);
	public:
		DepthStencilDesc m_desc;
	public:
		static DepthStencilState* New(const DepthStencilDesc& desc);
	};

	//----------------------------------------------------
}
