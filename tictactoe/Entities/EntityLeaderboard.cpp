#include "EntityLeaderboard.h"

EntityLeaderboard::EntityLeaderboard(std::shared_ptr<AcsGameEngine::Texture> t)
    : m_turnSprite(t, { 654, 325, 98, 40 }, {300, 100, 98, 40})
    , m_WinnerSprite(t, { 654, 242, 160, 39 }, { 300, 100, 160, 39 })
    , m_DrawSprite(t, { 654, 284, 114, 39 }, { 300, 100, 114, 39 })
    , m_smallCross(t, { 657, 367, 35, 38 }, { 400, 100, 35, 38 })
    , m_smallCircle(t, { 702, 367, 33, 40 }, { 400, 100, 33, 40 })
{
}

EntityLeaderboard::~EntityLeaderboard()
{
}

AcsGameEngine::Sprite &EntityLeaderboard::getSprite(EntityLeaderboard::spriteType type)
{    
    switch (type) {
    case turn:
        return m_turnSprite;        
        break;
    case winner:
        return m_WinnerSprite;
        break;
    case draw:
        return m_DrawSprite;
        break;
    case cross:
        return m_smallCross;
        break;
    default:
        return m_smallCircle;
    }
}
