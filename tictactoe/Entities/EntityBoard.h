#pragma once

#include "..\AcsGameEngine\Sprite.h"
#include "..\AcsGameEngine\Texture.h"
#include <utility>
#include <memory>


class EntityBoard  {
public:
    EntityBoard(std::shared_ptr<AcsGameEngine::Texture>);
    ~EntityBoard();
    
    std::pair<int, int> getPoint() const noexcept;

    AcsGameEngine::Sprite &getSprite();
private:
    AcsGameEngine::Sprite m_sprite;
};
