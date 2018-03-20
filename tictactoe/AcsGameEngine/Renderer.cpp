#include <SDL2/SDL_image.h>

#include "Renderer.h"
#include "Sprite.h"
#include "Texture.h"
#include "Window.h"

namespace AcsGameEngine {

Renderer::Renderer(const Window& window, int index, Uint32 flags)
    : m_renderer(createRendererPointer(window.getRawPointer(), index, flags), SDL_DestroyRenderer)
    , m_window(window)
{

    if (m_renderer == nullptr) {
        throw std::runtime_error(std::string{ "Unable to initialize renderer: " }
            + std::string{ SDL_GetError() });
    }
}

SDL_Renderer* Renderer::createRendererPointer(SDL_Window* w, int index, Uint32 flags)
{
    return SDL_CreateRenderer(w, index, flags);
}

void Renderer::DrawColor(const Util::ColorList::Color& color, uint8_t alpha) const
{
    DrawColor(color.r, color.g, color.b, alpha);
}

void Renderer::DrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha) const
{
    SDL_SetRenderDrawColor(getRawPointer(), r, g, b, alpha);
}

void Renderer::Clear(const Util::ColorList::Color& color) const
{
    DrawColor(color);
    Clear();
}

void Renderer::Clear() const
{
    SDL_RenderClear(getRawPointer());
}

void Renderer::Present() const
{
    SDL_RenderPresent(getRawPointer());
}

void Renderer::DrawRect(const SDL_Rect rect, const Util::ColorList::Color& c, bool fill) const
{
    if (c != Util::ColorList::_nocolor) {
        DrawColor(c);
    }

    fill ? SDL_RenderFillRect(getRawPointer(), &rect) : SDL_RenderDrawRect(getRawPointer(), &rect);
}

SDL_Renderer* Renderer::getRawPointer() const
{
    return m_renderer.get();
}

const Window& Renderer::getWindow() const
{
    return m_window;
}

void AcsGameEngine::Renderer::DrawSprite(Sprite& sprite) const noexcept
{
    const Texture& texture = sprite.getTexture();
    SDL_RenderCopy(getRawPointer(), texture.getRawPointer(), &(sprite.getSource()), &(sprite.getDestination()));
}

Texture Renderer::MakeTexture(const std::string &path) const noexcept
{
    SDL_Surface *tmp = IMG_Load(path.c_str());
    SDL_Texture *t = SDL_CreateTextureFromSurface(getRawPointer(), tmp);
    SDL_FreeSurface(tmp);

    return Texture{ t };
}

Sprite Renderer::MakeSprite(const Texture &texture) const noexcept
{    
    return { *this, texture };
}

Sprite Renderer::MakeSprite(const std::string &path) const noexcept
{

    return MakeSprite(MakeTexture(path));
}

} // namespace AcsGameEngine
/*

TextureManager

#include <memory>
#include <unordered_map>
#include <string>
#include <iostream>

class Texture {
private:
const std::string &m_path;
public:
Texture(const std::string &path) : m_path(path) {
}

void printPath() {
std::cout << m_path << '\n';
}
};

class TextureFactory {
private:
using tsPtr = std::shared_ptr<Texture>;
std::unordered_map<std::string, tsPtr> m_items;
public:
tsPtr getTexture(const std::string &path) {

if (m_items.find(path) == m_items.end()) {
m_items[path] = std::make_shared<Texture>(path);
}

return m_items[path];
}
};

int main() {
TextureFactory tf;

auto t1 = tf.getTexture("path1");
auto t2 = tf.getTexture("path1");

(*t1).printPath();
//(*t2)->printPath();

std::cout << t2.use_count() << '\n';
}
*/