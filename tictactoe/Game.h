#pragma once

#include <vector>
#include <string>

#include "AcsGameEngine/Renderer.h"
#include "AcsGameEngine/Texture.h"
#include "AcsGameEngine/EventManager.h"
#include "Entities/EntityBoard.h"
#include "Entities/EntitySpot.h"
#include "Entities/EntityItemType.h"
#include "Entities/EntityLeaderboard.h"


class Game {
private:
    const int m_totalSpots{ 9 };
    AcsGameEngine::Renderer &m_renderer;
    AcsGameEngine::EventManager &m_em;
    const std::string m_mainTexture;
    EntityBoard m_board;
    std::vector<EntitySpot> m_spots;
    EntityItemType m_selectedType;
    EntityLeaderboard m_leaderBoard;

    void setupBoardEntity() noexcept;
    void createSpots() noexcept;
    void setupSpotEntities() noexcept;
    void setupLeaderBoardEntity() noexcept;
    void resetGame() noexcept;
public:
    Game(AcsGameEngine::Renderer &, AcsGameEngine::EventManager &);
    ~Game();

    void update();
    void draw();
};
