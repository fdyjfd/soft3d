#pragma once

#include "Utility.h"

namespace soft3d
{
	enum class ResourceCategory
	{
		vertex_buffer,
		index_buffer,
		constant_buffer,
		texture_1d,
		texture_2d,
		texture_3d,
		texture_1d_array,
		texture_2d_array,
		texture_3d_array,
		texture_cube,
	};

	class Resource
	{
	public:
		Resource(ResourceCategory category);
	public:
		ResourceCategory getCategory() const;
	private:
		long addRef();
		long release();
		long internalAddRef();
		long internalRelease();
     protected:
		ResourceCategory m_category;
		long m_refCount;
		long m_internalRefCount;
	};
	
	class Buffer : public Resource
	{
	public:
		Buffer(ResourceCategory category);
	public:
		void* getData();
		s3d_uint32 getSize() const;
	private:
		void* m_ptr;
		s3d_uint32 m_size;
	};

	class VertexBuffer : public Buffer
	{
	public:
		VertexBuffer();
	};

	class IndexBuffer : public Buffer
	{
	public:
		IndexBuffer();
	};

	class ConstantBuffer : public Buffer
	{
	public:
		ConstantBuffer();
	};

	class Texture1D : public Resource
	{
	public:
		TextureFormat m_format;
		s3d_uint32 m_width;
		s3d_uint32 m_mipLevel;
	};

	class Texture2D : public Resource
	{
	public:
		TextureFormat m_format;
		s3d_uint32 m_width;
		s3d_uint32 m_height;
		s3d_uint32 m_mipLevel;
	};

	class Texture3D : public Resource
	{
	public:
		TextureFormat m_format;
		s3d_uint32 m_width;
		s3d_uint32 m_height;
		s3d_uint32 m_depth;
		s3d_uint32 m_mipLevel;
	};

	class Texture1DArray : public Resource
	{
	public:
		TextureFormat m_format;
		s3d_uint32 m_width;
		s3d_uint32 m_mipLevel;
		s3d_uint32 m_arraySize;
	};

	class Texture2DArray : public Resource
	{
	public:
		TextureFormat m_format;
		s3d_uint32 m_width;
		s3d_uint32 m_height;
		s3d_uint32 m_mipLevel;
		s3d_uint32 m_arraySize;
	};

	class Texture3DArray : public Resource
	{
	public:
		TextureFormat m_format;
		s3d_uint32 m_width;
		s3d_uint32 m_height;
		s3d_uint32 m_depth;
		s3d_uint32 m_mipLevel;
		s3d_uint32 m_arraySize;
	};

	class TextureCube : public Resource
	{
	public:
		TextureFormat m_format;
		s3d_uint32 m_width;
		s3d_uint32 m_mipLevel;
	};

	//----------------------------------------------------

	inline Resource::Resource(ResourceCategory category) :
		m_category(category)
	{}

	inline ResourceCategory Resource::getCategory() const
	{
		return m_category;
	}

	Buffer::Buffer(ResourceCategory category) :
		Resource(category)
	{}

	inline void* Buffer::getData()
	{
		return m_ptr;
	}

	inline s3d_uint32 Buffer::getSize() const
	{
		return m_size;
	}

	VertexBuffer::VertexBuffer() :
		VertexBuffer(ResourceCategory::vertex_buffer)
	{}

	IndexBuffer::IndexBuffer() :
		IndexBuffer(ResourceCategory::index_buffer)
	{}

	ConstantBuffer::ConstantBuffer() :
		ConstantBuffer(ResourceCategory::constant_buffer)
	{}

}
