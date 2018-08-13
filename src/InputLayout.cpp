#include "InputLayout.h"

BEGIN_SOFT3D

InputLayout InputLayout::s_defaultInputLayout;

InputLayout::InputLayout()
{
}

InputLayout::InputLayout(InputElement const* inputElements, s3d_uint32 count)
{
	if (inputElements && count)
	{
		m_inputElements.insert(m_inputElements.end(), inputElements, inputElements + count);
	}
}

bool InputLayout::Check(InputElement const* inputElements, s3d_uint32 count)
{
	if (inputElements && count)
	{
		for (s3d_uint32 i = 0; i < count; ++i)
		{
			InputElement const& inputElement = inputElements[i];
			if (VertexFormat::vertex_format_count <= inputElement.format)
			{
				return false;
			}
			if (InputElementCategory::input_element_category_count <= inputElement.category)
			{
				return false;
			}
		}
	}
	return true;
}

END_SOFT3D