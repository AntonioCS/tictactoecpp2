#pragma once

#include "..\AcsGameEngine\Sprite.h"
#include "..\AcsGameEngine\Texture.h"
#include <memory>
#include <array>

class EntityLeaderboard
{
public:
    enum spriteType {
        turn,
        winner,
        draw,
        cross,
        circle
    };

    EntityLeaderboard(std::shared_ptr<AcsGameEngine::Texture>);
    ~EntityLeaderboard();

    AcsGameEngine::Sprite &getSprite(spriteType);
private:
    const int total_sprites = 5;
    AcsGameEngine::Sprite m_turnSprite;
    AcsGameEngine::Sprite m_WinnerSprite;
    AcsGameEngine::Sprite m_DrawSprite;
    AcsGameEngine::Sprite m_smallCross;
    AcsGameEngine::Sprite m_smallCircle;
};

