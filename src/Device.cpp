#include "Device.h"
#include "Sampler.h"
#include "RasterizerState.h"
#include "DepthStencilState.h"
#include "BlendState.h"
#include "Resource.h"
#include "Shader.h"

BEGIN_SOFT3D

static Sampler* NewDefaultSampler()
{
	return 0;
}

static RasterizerState* NewDefaultRasterizerState()
{
	return 0;
}

static DepthStencilState* NewDefaultDepthStencilState()
{
	return 0;
}

static BlendState* NewDefaultBlendState()
{
	return 0;
}

Sampler* Device::s_defaultSampler = NewDefaultSampler();
RasterizerState* Device::s_defaultRasterizerState = NewDefaultRasterizerState();
DepthStencilState* Device::s_defaultDepthStencilState = NewDefaultDepthStencilState();
BlendState* Device::s_defaultBlendState = NewDefaultBlendState();

VertexBuffer* Device::createVertexBuffer(s3d_uint32 size)
{
	return new VertexBuffer(size);
}

IndexBuffer* Device::createIndexBuffer(s3d_uint32 size)
{
	return new IndexBuffer(size);
}

ConstantBuffer* Device::createConstantBuffer(s3d_uint32 size)
{
	return new ConstantBuffer(size);
}

Texture1D* Device::createTexture1D(TextureFormat format, s3d_uint32 width, s3d_uint32 mipLevel)
{
	return 0;
}

Texture2D* Device::createTexture2D(TextureFormat format, s3d_uint32 width, s3d_uint32 height, s3d_uint32 mipLevel)
{
	return 0;
}

Texture3D* Device::createTexture3D(TextureFormat format, s3d_uint32 width, s3d_uint32 height, s3d_uint32 depth, s3d_uint32 mipLevel)
{
	return 0;
}

Texture1DArray* Device::createTexture1DArray(TextureFormat format, s3d_uint32 width, s3d_uint32 mipLevel, s3d_uint32 arraySize)
{
	return 0;
}

Texture2DArray* Device::createTexture2DArray(TextureFormat format, s3d_uint32 width, s3d_uint32 height, s3d_uint32 mipLevel, s3d_uint32 arraySize)
{
	return 0;
}

Texture3DArray* Device::createTexture3DArray(TextureFormat format, s3d_uint32 width, s3d_uint32 height, s3d_uint32 depth, s3d_uint32 mipLevel, s3d_uint32 arraySize)
{
	return 0;
}

TextureCube* Device::createTextureCube(TextureFormat format, s3d_uint32 width, s3d_uint32 mipLevel)
{
	return 0;
}

Sampler* Device::createSampler(const SamplerDesc* desc)
{
	if (desc)
	{
		return new Sampler(*desc);
	}
	else
	{
		s_defaultSampler->addRef();
		return s_defaultSampler;
	}
}

RasterizerState* Device::createRasterizerState(
	const RasterizerDesc* desc)
{
	if (desc)
	{
		return new RasterizerState(*desc);
	}
	else
	{
		s_defaultRasterizerState->addRef();
		return s_defaultRasterizerState;
	}
}

DepthStencilState* Device::createDepthStencilState(
	const DepthStencilDesc* desc)
{
	if (desc)
	{
		return new DepthStencilState(*desc);
	}
	else
	{
		s_defaultDepthStencilState->addRef();
		return s_defaultDepthStencilState;
	}
}

BlendState* Device::createBlendState(
	const BlendDesc* desc)
{
	if (desc)
	{
		return new BlendState(*desc);
	}
	else
	{
		s_defaultBlendState->addRef();
		return s_defaultBlendState;
	}
}

VertexShader* Device::createVertexShader()
{
	return 0;
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
	return 0;
}

PixelShader* Device::createPixelShader()
{
	return 0;
}

END_SOFT3D
