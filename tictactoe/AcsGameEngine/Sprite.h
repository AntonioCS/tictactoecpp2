#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <utility>

namespace AcsGameEngine {

class Renderer;
class Texture;

class Sprite {
public:
    Sprite(const Renderer& renderer, const Texture& texture);
    Sprite(const Renderer& renderer, const Texture& texture, int, int);
    
    Sprite(const Sprite& orig) = delete;
    Sprite(Sprite&& other);
    virtual ~Sprite();

    void setSourceDestination(SDL_Rect, SDL_Rect);

    void setSourceXYWH(int, int, int, int);
    void setDestinationXYWH(int, int, int, int);

    void setSourceXY(int, int);
    void setDestinationXY(int, int);

    void setSourceWH(int, int);
    void setDestinationWH(int, int);

    void setCenter();

    std::pair<int, int> getDestinationPoint() const noexcept;
    SDL_Rect getDestination() const noexcept;
    SDL_Rect getSource() const noexcept;

    const Texture& getTexture() const noexcept;

private:
    const Renderer& m_renderer;
    const Texture& m_texture;

    SDL_Rect m_destination{ 0, 0, 0, 0 };
    SDL_Rect m_source{ 0, 0, 0, 0 };
};
}
#endif /* SPRITE_H */
