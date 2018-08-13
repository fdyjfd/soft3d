#pragma once

#if defined SOFT3D_EXPORTS
#define SOFT3D_EXPORT __declspec(dllexport)
#else
#define SOFT3D_EXPORT __declspec(dllimport)
#endif

#define BEGIN_SOFT3D	namespace soft3d {
#define END_SOFT3D		}

namespace soft3d
{

	typedef int s3d_int32;
	typedef unsigned int s3d_uint32;
	typedef unsigned char s3d_uint8;

	enum class IndexFormat
	{
		index_16,
		index_32,
	};

	enum class VertexFormat
	{
		vertex_float_1,
		vertex_float_2,
		vertex_float_3,
		vertex_float_4,

		vertex_int_1,
		vertex_int_2,
		vertex_int_3,
		vertex_int_4,

		vertex_uint_1,
		vertex_uint_2,
		vertex_uint_3,
		vertex_uint_4,

		vertex_format_count,

	};

	enum
	{
		vertex_buffer_slot_count = 16,
		shader_resource_slot_count = 16,
		render_target_slot_count = 8,
		shader_register_slot = 16,
		stream_output_slot_count = 16,
	};

	enum class ComparisonFunc
	{
		never,
		less,
		equal,
		less_equal,
		greater,
		not_equal,
		greater_equal,
		always
	};

	enum class TextureFormat
	{

	};

	enum class InputElementCategory
	{
		vertex_data,
		instance_data,
		input_element_category_count
	};

	enum class PrimitiveTopology
	{
		point_list,
		line_list,
		line_strip,
		triangle_list,
		triangle_strip,
	};

	struct Viewport
	{
		float x;
		float y;
		float width;
		float height;
		float minDepth;
		float maxDepth;
	};

	struct float4
	{
		union
		{
			struct
			{
				float x, y, z, w;
			};
			struct
			{
				float r, g, b, a;
			};
		};
	};

	struct ShaderInput
	{
		float4 vector[shader_register_slot];
	};
}
