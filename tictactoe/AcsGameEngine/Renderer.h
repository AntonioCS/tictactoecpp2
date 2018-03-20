#ifndef RENDERER_H
#define RENDERER_H

#include "Util/ColorList.h"
#include <SDL2/SDL.h>
#include <memory>
#include <string>

namespace AcsGameEngine {

class Window;
class Texture;
class Sprite;

class Renderer {
public:
    explicit Renderer(const Window& window, int index = -1, Uint32 flags = SDL_RENDERER_ACCELERATED);
    Renderer(const Renderer& orig) = delete;
    Renderer(Renderer &&) = default;
    Renderer& operator=(const Renderer& other)
    {
        if (&other != this) {
            
        }
        return *this;
    }
    Renderer& operator=(Renderer && other)
    {
        if (&other != this) {
            
        }
        return *this;
    }
    
    void DrawColor(const Util::ColorList::Color& /*color*/, uint8_t alpha = 255) const;
    void DrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha = 255) const;
    void Clear() const;
    void Clear(const Util::ColorList::Color& /*color*/) const;
    void Present() const;
    void DrawRect(SDL_Rect, const Util::ColorList::Color &c = Util::ColorList::_nocolor, bool fill = false) const;
    void DrawSprite(Sprite &) const noexcept;

    Texture MakeTexture(const std::string &path) const noexcept;
    Sprite MakeSprite(const Texture &) const noexcept;
    Sprite MakeSprite(const std::string &) const noexcept;

    SDL_Renderer* getRawPointer() const;
    const Window& getWindow() const;
private:
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;
    const Window& m_window;
    SDL_Renderer* createRendererPointer(SDL_Window* w, int index, Uint32 flags);
};
} //namespace AcsGameEngine

#endif // RENDERER_H