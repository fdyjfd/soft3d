#pragma once

#include "RefCount.h"

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

	struct RasterizerDesc
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

	class RasterizerState : public RefCount
	{
	public:
		RasterizerState(const RasterizerDesc& desc);
	public:
		RasterizerDesc m_desc;
	public:
		static RasterizerState* New(const RasterizerDesc& desc);
	};

	//----------------------------------------------------
}
