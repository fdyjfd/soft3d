#pragma once

#include "DeviceContext.h"
#include "Resource.h"
#include "InputLayout.h"

BEGIN_SOFT3D

void DeviceContext::setVertexBuffers(
	s3d_uint32 startSlot, 
	s3d_uint32 count, 
	Buffer* const* vertexBuffers, 
	s3d_uint32 const* strids, 
	s3d_uint32  const* offsets)
{
	if (startSlot >= vertex_buffer_slot_count)
	{
		return;
	}
	if (startSlot + count > vertex_buffer_slot_count)
	{
		count = vertex_buffer_slot_count - startSlot;
	}
	for (s3d_uint32 i = 0; i < count; ++i)
	{
		vertexBuffers[i]->safeInternalAddRef();
		m_vertexBuffers[startSlot + i]->safeInternalRelease();
		m_vertexBuffers[startSlot + i] = vertexBuffers[i];
	}
}

void DeviceContext::setIndexBuffer(Buffer* indexBuffer)
{
}

void DeviceContext::setInputLayout(InputLayout* inputLayout)
{
	m_inputLayout = inputLayout ? inputLayout : &InputLayout::s_defaultInputLayout;
}

void DeviceContext::setVertexShader(VertexShader* vertexShader)
{
}

void DeviceContext::setVertexShaderResources(VertexShader* vertexShader)
{
}

void DeviceContext::setVertexShaderSamplers(VertexShader* vertexShader)
{
}

void DeviceContext::setVertexShaderConstantBuffers(VertexShader* vertexShader)
{
}


void DeviceContext::setGeometryShader(GeometryShader* vertexShader)
{
}

void DeviceContext::setGeometryShaderResources(GeometryShader* vertexShader)
{
}

void DeviceContext::setGeometryShaderSamplers(GeometryShader* vertexShader)
{
}

void DeviceContext::setGeometryShaderConstantBuffers(GeometryShader* vertexShader)
{
}


void DeviceContext::setPixelShader(PixelShader* vertexShader)
{
}

void DeviceContext::setPixelShaderResources(PixelShader* vertexShader)
{
}

void DeviceContext::setPixelShaderSamplers(PixelShader* vertexShader)
{
}

void DeviceContext::setPixelShaderConstantBuffers(PixelShader* vertexShader)
{
}


void DeviceContext::setRenderTargets(Resource** renderTargets, Resource* depthStencil)
{
}

void DeviceContext::setViewport(Viewport viewport)
{
}


void DeviceContext::setPrimitiveTopology(PrimitiveTopology primitiveTopology)
{
}

void DeviceContext::draw(s3d_uint32 vertexCount, s3d_uint32 startVertexLocation)
{
	switch (m_primitiveTopology)
	{
	case PrimitiveTopology::point_list:
		drawPointList(vertexCount, startVertexLocation);
		break;
	case PrimitiveTopology::line_list:
		break;
	case PrimitiveTopology::line_strip:
		break;
	case PrimitiveTopology::triangle_list:
		break;
	case PrimitiveTopology::triangle_strip:
		break;
	}
}

void DeviceContext::drawIndexed()
{
}

void DeviceContext::drawInstanced()
{
}

void DeviceContext::drawIndexedInstanced()
{
}

void DeviceContext::drawPoint(s3d_uint32 vertexLocation)
{
}

void DeviceContext::drawPointList(s3d_uint32 vertexCount, s3d_uint32 startVertexLocation)
{
	//m_inputLayout
	for (s3d_uint32 i = 0; i < vertexCount; ++i)
	{
		drawPoint(startVertexLocation + i);
	}
}


END_SOFT3D
