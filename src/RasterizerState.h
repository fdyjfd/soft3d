#pragma once

#include "Utility.h"

namespace soft3d
{
	enum class FillMode
	{
		point,
		wire_frame,
		solid
	};

	enum class CullMode
	{
		none,
		front,
		back
	};

	struct RasterizerStateDesc
	{
		FillMode fillMode;
		CullMode cullMode;
		bool frontCounterClockwise;
		int depthBias;
		float depthBiasClamp;
		float slopeScaledDepthBias;
		bool depthClipEnable;
		bool scissorEnable;
		bool multisampleEnable;
		bool antialiasedLineEnable;
	};

	class RasterizerState
	{
	public:
		RasterizerStateDesc m_rasterizerStateDesc;
	public:
		static RasterizerStateDesc s_defaultRasterizerStateDesc;
	};

	//----------------------------------------------------
}
