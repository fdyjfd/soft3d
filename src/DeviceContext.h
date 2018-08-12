#pragma once

#include "Utility.h"

namespace soft3d
{
	class Buffer;
	class InputLayout;
	class RenderState;
	class VertexShader;
	class GeometryShader;
	class PixelShader;
	class Resource;

	class DeviceContext
	{
	public:
		void setRenderState(
			RenderState* renderState);

		void setVertexBuffers(
			s3d_uint32 startSlot, 
			s3d_uint32 count, 
			Buffer* const* vertexBuffers, 
			s3d_uint32 const* strids, 
			s3d_uint32  const* offsets);

		void setIndexBuffer(Buffer* indexBuffer);
		void setInputLayout(InputLayout* inputLayout);

		void setVertexShader(VertexShader* vertexShader);
		void setVertexShaderResources(VertexShader* vertexShader);
		void setVertexShaderSamplers(VertexShader* vertexShader);
		void setVertexShaderConstantBuffers(VertexShader* vertexShader);

		void setGeometryShader(GeometryShader* vertexShader);
		void setGeometryShaderResources(GeometryShader* vertexShader);
		void setGeometryShaderSamplers(GeometryShader* vertexShader);
		void setGeometryShaderConstantBuffers(GeometryShader* vertexShader);

		void setPixelShader(PixelShader* vertexShader);
		void setPixelShaderResources(PixelShader* vertexShader);
		void setPixelShaderSamplers(PixelShader* vertexShader);
		void setPixelShaderConstantBuffers(PixelShader* vertexShader);

		void setRenderState(RenderState* renderState);
		void setRenderTargets(Resource** renderTargets, Resource* depthStencil);
		void setViewport(Viewport viewport);

		void setPrimitiveTopology(PrimitiveTopology primitiveTopology);
		void setBlendFactor(float4 blendFactor);
		void setStencilRef(s3d_uint32 stencilRef);
		void setViewports(Viewport* viewports, s3d_uint32 viewportCount);
		void draw(s3d_uint32 vertexCount, s3d_uint32 startVertexLocation);
		void drawIndexed();
		void drawInstanced();
		void drawIndexedInstanced();
	private:
		void drawPoint(s3d_uint32 vertexLocation);
		void drawPointList(s3d_uint32 vertexCount, s3d_uint32 startVertexLocation);
	protected:
		RenderState * m_renderState;
		InputLayout* m_inputLayout;
		Buffer* m_vertexBuffers[vertex_buffer_slot_count];
		s3d_uint32 m_strides[vertex_buffer_slot_count];
		s3d_uint32 m_offsets[vertex_buffer_slot_count];
		Buffer* m_indexBuffer;
		VertexShader* m_vertexShader;
		GeometryShader* m_geometryShader;
		PixelShader* m_pixelShader;
		Resource* m_vertexShaderResources[shader_resource_slot_count];
		Resource* m_geometryShaderResources[shader_resource_slot_count];
		Resource* m_pixelShaderResources[shader_resource_slot_count];
		Viewport m_viewports[render_target_slot_count];
		s3d_uint32 m_viewportCount;
		float4 m_blendFactor;
		s3d_uint32 m_stencilRef;
		PrimitiveTopology m_primitiveTopology;

	};
}
