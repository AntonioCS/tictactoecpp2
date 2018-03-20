#pragma once

#include "AcsGameEngine\Sprite.h"
#include <utility>

class EntityBoard  {
    AcsGameEngine::Sprite m_sprite;
public:
    explicit EntityBoard(AcsGameEngine::Sprite);

    void draw();

    std::pair<int, int> getPoint() const noexcept;

        
    ~EntityBoard();
};
