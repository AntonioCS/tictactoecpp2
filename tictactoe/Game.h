#pragma once

#include <vector>

#include "AcsGameEngine/Renderer.h"
#include "AcsGameEngine/Sprite.h"
#include "AcsGameEngine/Texture.h"
#include "AcsGameEngine/EventManager.h"
#include "Entities/EntityBoard.h"
#include "Entities/EntitySpot.h"


class Game {
private:
    const int m_totalSpots{ 9 };
    const AcsGameEngine::Renderer &m_renderer;
    AcsGameEngine::EventManager &m_em;
    AcsGameEngine::Texture m_mainTexture;
    EntityBoard m_board;
    std::vector<EntitySpot> m_spots;

    void createSpots() noexcept;
public:
    Game(const AcsGameEngine::Renderer &, AcsGameEngine::EventManager &);
    ~Game();

    void setupEntities();
    void update();
    void draw();
};
