#include <utility>
#include <iostream>
#include <SDL2\SDL.h>

#include "EntitySpot.h"
#include "../AcsGameEngine/Util/ColorList.h"

EntitySpot::EntitySpot(std::shared_ptr<AcsGameEngine::Texture> t)
    : m_sprite_cross(t)
    , m_sprite_circle(t)
{
}

void EntitySpot::setArea(const int x, const int y, const int w, const int h) noexcept
{
    m_clickAbleArea.x = x;
    m_clickAbleArea.y = y;
    m_clickAbleArea.w = w;
    m_clickAbleArea.h = h;
}

void EntitySpot::reset()
{
    m_type.setType(EntityItemType::Type::not_set);
    m_clicked = false;
    m_disabled = false;
}

std::pair<int, int> EntitySpot::getDrawPoint() const noexcept
{
    return { m_draw_x, m_draw_y };
}

bool EntitySpot::isClicked() const noexcept
{
    return m_clicked;
}

void EntitySpot::setClicked(bool state) noexcept
{    
    m_clicked = state;
}

void EntitySpot::setType(EntityItemType::Type type) {
    m_type.setType(type);
}

EntityItemType::Type EntitySpot::getType() const noexcept
{
    return m_type.getType();
}

bool EntitySpot::isInsideArea(const int x, const int y) const noexcept
{
    return x >= m_clickAbleArea.x && x <= m_clickAbleArea.w + m_clickAbleArea.x && y >= m_clickAbleArea.y && y <= m_clickAbleArea.h + m_clickAbleArea.y;
}

std::ostream& operator<<(std::ostream& out, const SDL_Rect& rect) {
    out << "x:" << rect.x << " y:" << rect.y << " w:" << rect.w << " h:" << rect.h;
    return out;
}

/*
void EntitySpot::draw() const noexcept
{
    if (isClicked() && isTypeSet()) {
        
    }
    m_renderer.DrawRect(m_clickAbleArea, AcsGameEngine::Util::ColorList::red);
}*/

bool EntitySpot::isDisabled() const noexcept
{
    return m_disabled;
}

void EntitySpot::setDisabled(bool state) noexcept
{
    m_disabled = true;
}

bool EntitySpot::isTypeSet() const noexcept
{
    return getType() != EntityItemType::Type::not_set;
}

AcsGameEngine::Sprite & EntitySpot::getSpriteCross()
{
    return m_sprite_cross;
}

AcsGameEngine::Sprite & EntitySpot::getSpriteCircle()
{
    return m_sprite_circle;
}

SDL_Rect EntitySpot::getClickAbleArea() const noexcept
{
    return { m_clickAbleArea.x, m_clickAbleArea.y, m_clickAbleArea.w, m_clickAbleArea.h };
}

std::unordered_map<Uint32, EntitySpot::eventFunc> EntitySpot::fetchEvents() noexcept {
    auto func = [this](SDL_Event & event) {
        if (event.button.button == SDL_BUTTON_LEFT) { 
            int x = event.button.x;
            int y = event.button.y;

            if (!isDisabled() && isInsideArea(x, y) && !isClicked()) {
                setClicked();
            }
        }
    };

    return { { SDL_MOUSEBUTTONUP , func } };
}
