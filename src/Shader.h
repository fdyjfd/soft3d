#pragma once

#include "RefCount.h"
#include <string>
#include <vector>

namespace soft3d
{
	struct ShaderRegister
	{};

	class StreamOutput
	{
	public:
		void ouputTriangleStrip(s3d_uint32 vertexCount);
	public:
		ShaderRegister m_registers[stream_output_slot_count];
	};

	class SystemValue
	{
	public:
		s3d_uint32 m_vertexID;
		s3d_uint32 m_primitiveID;
		s3d_uint32 m_instanceID;
	};


	typedef void (*VertexShaderFunction)(ShaderRegister* output, const ShaderRegister* input, const SystemValue* systemValue);
	
	class VertexShader : public RefCount
	{
	public:
		VertexShaderFunction* m_vertexShaderFunction;
	};

	struct PixelShaderOutput
	{
		float4 target[render_target_slot_count];
		float depth;
	};

	typedef void(*PixelShaderFunction)(PixelShaderOutput* output, const ShaderRegister* input);

	class PixelShader : public RefCount
	{
	public:
		PixelShaderFunction * m_pixelShaderFunction;
	};

	typedef void(*GeometryShaderFunction)(StreamOutput* output, const ShaderRegister* input);

	class GeometryShader : public RefCount
	{
	public:
		GeometryShaderFunction * m_geometryShaderFunction;
	};

}
