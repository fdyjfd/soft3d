#pragma once

#include "Utility.h"
#include "RefCount.h"

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

	class Resource : public RefCount
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
		Buffer(ResourceCategory category, s3d_uint32 size);
		~Buffer();
	public:
		void* getData();
		s3d_uint32 getSize() const;
	private:
		s3d_uint8* m_buffer;
		s3d_uint32 m_size;
	};

	class VertexBuffer : public Buffer
	{
	public:
		VertexBuffer(s3d_uint32 size);
	};

	class IndexBuffer : public Buffer
	{
	public:
		IndexBuffer(s3d_uint32 size);
	};

	class ConstantBuffer : public Buffer
	{
	public:
		ConstantBuffer(s3d_uint32 size);
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

	inline Buffer::Buffer(ResourceCategory category, s3d_uint32 size) :
		Resource(category)
	{
		m_buffer = new s3d_uint8[size];
		m_size = size;
	}

	inline Buffer::~Buffer()
	{
		delete[] m_buffer;
	}

	inline void* Buffer::getData()
	{
		return m_buffer;
	}

	inline s3d_uint32 Buffer::getSize() const
	{
		return m_size;
	}

	inline VertexBuffer::VertexBuffer(s3d_uint32 size) :
		Buffer(ResourceCategory::vertex_buffer, size)
	{}

	inline IndexBuffer::IndexBuffer(s3d_uint32 size) :
		Buffer(ResourceCategory::index_buffer, size)
	{}

	inline ConstantBuffer::ConstantBuffer(s3d_uint32 size) :
		Buffer(ResourceCategory::constant_buffer, size)
	{}

}
