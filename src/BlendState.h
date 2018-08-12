#pragma once

#include "Utility.h"

namespace soft3d
{

	enum class BlendOption
	{
		zero,
		one,
		src_color,
		inv_src_color,
		src_alpha,
		inv_src_alpha,
		dest_alpha,
		inv_dest_alpha,
		dest_color,
		inv_dest_color,
		src_alpha_sat,
		src_blend_factor,
		inv_blend_factor,
		src1_color,
		inv_src1_color,
		src1_alpha,
		inv_src1_alpha,
	};

	enum class BlendOperation
	{
		add,
		subtract,
		rev_subtract,
		min,
		max,
	};

	struct RenderTargetBlendDesc
	{
		bool           blendEnable;
		BlendOption    srcBlend;
		BlendOption    destBlend;
		BlendOperation blendOp;
		BlendOption    srcBlendAlpha;
		BlendOption    destBlendAlpha;
		BlendOperation blendOpAlpha;
		s3d_uint8      renderTargetWriteMask;
	};

	struct BlendDesc
	{
		bool alphaToCoverageEnable;
		RenderTargetBlendDesc renderTarget[8];
	};

	class BlendState
	{
	public:
		BlendDesc m_desc;
	public:
		static BlendDesc s_defaultDesc;
	};

	//----------------------------------------------------
}
