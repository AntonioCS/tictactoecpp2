#include "EntityBoard.h"

EntityBoard::EntityBoard(const AcsGameEngine::Sprite sprite)
    : m_sprite(std::move(sprite))
{
    m_sprite.setCenter();    
}

void EntityBoard::draw()
{
    m_sprite.draw();
}

std::pair<int, int> EntityBoard::getPoint() const noexcept
{
    return m_sprite.getDestinationPoint();
}

EntityBoard::~EntityBoard()
{
}
