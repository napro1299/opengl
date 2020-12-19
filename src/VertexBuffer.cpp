#include "VertexBuffer.h"

#include "Renderer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    glGenBuffers(1, &m_RendererID); // Generate buffer object
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID); // Bind the buffer
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW); // Fill buffer with vertex data
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_RendererID);
}

void VertexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void VertexBuffer::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
