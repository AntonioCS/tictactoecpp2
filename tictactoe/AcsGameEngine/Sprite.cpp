#include "Sprite.h"
#include "Renderer.h"
#include "Texture.h"
#include "Window.h"

namespace AcsGameEngine {

Sprite::Sprite(const Renderer& renderer, const Texture& texture)
    : m_renderer(renderer)
    , m_texture(texture)
{
}

Sprite::Sprite(const Renderer& renderer, const Texture& texture, int w, int h)
    : Sprite(renderer, texture)
{
    setSourceXYWH(0, 0, w, h);
    setDestinationXYWH(0, 0, w, h);
}
Sprite::Sprite(Sprite&& other)
    : m_renderer(std::move(other.m_renderer))
    , m_texture(std::move(other.m_texture))
    , m_destination(std::move(other.m_destination))
    , m_source(std::move(other.m_source))
{
}

Sprite::~Sprite()
{
}

void Sprite::setSourceDestination(SDL_Rect source, SDL_Rect destination)
{
    m_source = std::move(source);
    m_destination = std::move(destination);
}

void Sprite::setSourceXYWH(int x, int y, int w, int h)
{
    m_source.x = x;
    m_source.y = y;
    m_source.w = w;
    m_source.h = h;
}

void Sprite::setDestinationXYWH(int x, int y, int w, int h)
{
    m_destination.x = x;
    m_destination.y = y;
    m_destination.w = w;
    m_destination.h = h;
}

void Sprite::setSourceXY(int x, int y)
{
    m_source.x = x;
    m_source.y = y;
}

void Sprite::setSourceWH(int w, int h)
{
    m_source.w = w;
    m_source.h = h;
}

void Sprite::setDestinationXY(int x, int y)
{
    m_destination.x = x;
    m_destination.y = y;
}

void Sprite::setDestinationWH(int w, int h)
{
    m_destination.w = w;
    m_destination.h = h;
}

void Sprite::setCenter()
{
    auto win_center_w = win.getWidth() / 2;
    auto win_center_h = win.getHeight() / 2;

    m_destination.x = win_center_w - (m_source.w / 2);
    m_destination.y = win_center_h - (m_source.h / 2);
}

std::pair<int, int> Sprite::getDestinationPoint() const noexcept
{
    return { m_destination.x, m_destination.y };
}
SDL_Rect Sprite::getDestination() const noexcept
{
    return m_destination;
}
SDL_Rect Sprite::getSource() const noexcept
{
    return m_source;
}
const Texture& Sprite::getTexture() const noexcept
{
    return m_texture;
}
} // namespace AcsGameEngine
