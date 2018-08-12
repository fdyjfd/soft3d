#pragma once

#include "RefCount.h"
#include <string>
#include <vector>

namespace soft3d
{
	struct InputElement
	{
		std::string semanticName;
		s3d_uint32 semanticIndex;
		VertexFormat format;
		s3d_uint32 slot;
		s3d_uint32 offset;
		InputElementCategory category;
		s3d_uint32 instanceDataStepRate;
	};

	class InputLayout : public RefCount
	{
	public:
		InputLayout();
		InputLayout(InputElement const* inputElements, s3d_uint32 count);

	public:
		std::vector<InputElement> m_inputElements;
	public:
		static bool Check(InputElement const* inputElements, s3d_uint32 count);
	public:
		static InputLayout s_defaultInputLayout;
	};

	//----------------------------------------------------
}
