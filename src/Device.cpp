#include "Device.h"

BEGIN_SOFT3D

VertexBuffer* Device::createVertexBuffer(s3d_uint32 size)
{
}

IndexBuffer* Device::createIndexBuffer(s3d_uint32 size)
{
}

ConstantBuffer* Device::createConstantBuffer(s3d_uint32 size)
{
}

Texture1D* Device::createTexture1D(TextureFormat format, s3d_uint32 width, s3d_uint32 mipLevel)
{
}

Texture2D* Device::createTexture2D(TextureFormat format, s3d_uint32 width, s3d_uint32 height, s3d_uint32 mipLevel)
{
}

Texture3D* Device::createTexture3D(TextureFormat format, s3d_uint32 width, s3d_uint32 height, s3d_uint32 depth, s3d_uint32 mipLevel)
{
}

Texture1DArray* Device::createTexture1DArray(TextureFormat format, s3d_uint32 width, s3d_uint32 mipLevel, s3d_uint32 arraySize)
{
}

Texture2DArray* Device::createTexture2DArray(TextureFormat format, s3d_uint32 width, s3d_uint32 height, s3d_uint32 mipLevel, s3d_uint32 arraySize)
{
}

Texture3DArray* Device::createTexture3DArray(TextureFormat format, s3d_uint32 width, s3d_uint32 height, s3d_uint32 depth, s3d_uint32 mipLevel, s3d_uint32 arraySize)
{
}

TextureCube* Device::createTextureCube(TextureFormat format, s3d_uint32 width, s3d_uint32 mipLevel)
{
}

Sampler* Device::createSampler(const SamplerDesc* desc)
{
	Sampler* sampler = new Sampler(desc ? *desc : Sampler::s_defaultDesc);
	return sampler;
}

RasterizerState* Device::createRasterizerState(
	const RasterizerStateDesc* desc)
{

}

DepthStencilState* Device::createDepthStencilState(
	const DepthStencilDesc* desc)
{

}

BlendState* Device::createBlendState(
	const BlendDesc* desc)
{
}

VertexShader* Device::createVertexShader()
{
}

//HullShader* Device::createHullShader()
//{
//}
//
//DomainShader* Device::createDomainShader()
//{
//}

GeometryShader* Device::createGeometryShader()
{
}

PixelShader* Device::createPixelShader()
{
}

