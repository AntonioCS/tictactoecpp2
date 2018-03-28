#include "EntityBoard.h"

EntityBoard::EntityBoard(std::shared_ptr<AcsGameEngine::Texture> t)
    : m_sprite(t)
{    
}

std::pair<int, int> EntityBoard::getPoint() const noexcept
{
    return m_sprite.getDestinationPoint();
}

AcsGameEngine::Sprite &EntityBoard::getSprite()
{
    return m_sprite;
}

EntityBoard::~EntityBoard()
{
}
