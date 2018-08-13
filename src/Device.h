#pragma once

#include "RefCount.h"

namespace soft3d
{
	class VertexBuffer;
	class IndexBuffer;
	class ConstantBuffer;
	class Texture1D;
	class Texture2D;
	class Texture3D;
	class Texture1DArray;
	class Texture2DArray;
	class Texture3DArray;
	class TextureCube;
	class Sampler;
	class RasterizerState;
	class DepthStencilState;
	class BlendState;
	class VertexShader;
	class PixelShader;
	class GeometryShader;

	struct SamplerDesc;
	struct RasterizerDesc;
	struct DepthStencilDesc;
	struct BlendDesc;

	class Device : public RefCount
	{
	public:
		VertexBuffer * createVertexBuffer(
			s3d_uint32 size);

		IndexBuffer* createIndexBuffer(
			s3d_uint32 size);

		ConstantBuffer* createConstantBuffer(
			s3d_uint32 size);

		Texture1D* createTexture1D(
			TextureFormat format,
			s3d_uint32 width,
			s3d_uint32 mipLevel);

		Texture2D* createTexture2D(
			TextureFormat format,
			s3d_uint32 width,
			s3d_uint32 height,
			s3d_uint32 mipLevel);

		Texture3D* createTexture3D(
			TextureFormat format,
			s3d_uint32 width,
			s3d_uint32 height,
			s3d_uint32 depth,
			s3d_uint32 mipLevel);

		Texture1DArray* createTexture1DArray(
			TextureFormat format,
			s3d_uint32 width,
			s3d_uint32 mipLevel,
			s3d_uint32 arraySize);

		Texture2DArray* createTexture2DArray(
			TextureFormat format,
			s3d_uint32 width,
			s3d_uint32 height,
			s3d_uint32 mipLevel,
			s3d_uint32 arraySize);

		Texture3DArray* createTexture3DArray(
			TextureFormat format,
			s3d_uint32 width,
			s3d_uint32 height,
			s3d_uint32 depth,
			s3d_uint32 mipLevel,
			s3d_uint32 arraySize);

		TextureCube* createTextureCube(
			TextureFormat format,
			s3d_uint32 width,
			s3d_uint32 mipLevel);

		Sampler* createSampler(
			const SamplerDesc* desc);

		RasterizerState* createRasterizerState(
			const RasterizerDesc* desc);

		DepthStencilState* createDepthStencilState(
			const DepthStencilDesc* desc);

		BlendState* createBlendState(
			const BlendDesc* desc);

		VertexShader* createVertexShader();
		PixelShader* createPixelShader();
		GeometryShader* createGeometryShader();

		//ShaderProgram* createShaderProgram(
		//	VertexShader* vertexShader,
		//	PixelShader* pixelShader = 0,
		//	GeometryShader* geometryShader = 0);
	private:
		static Sampler* s_defaultSampler;
		static RasterizerState* s_defaultRasterizerState;
		static DepthStencilState* s_defaultDepthStencilState;
		static BlendState* s_defaultBlendState;
	};
}
