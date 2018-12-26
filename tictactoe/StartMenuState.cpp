#include "StartMenuState.h"

#include "AcsGE/ECS/EntityManager.h"
#include "AcsGE/ECS/Components/SpriteComponent.h" //include Rectangle.h
#include "AcsGE/GameStateManager.h"
#include "AcsGE/Util/Misc.h"
#include "AcsGE/Renderer.h"
#include "AcsGE/EventManager.h"
#include <algorithm>
#include <SDL2/SDL.h>
#include <iostream>

namespace {
    using AcsGameEngine::ECS::EntityManager;
    using AcsGameEngine::ECS::SpriteComponent;
    using AcsGameEngine::Util::Shapes::Rectangle;
}

void StartMenuState::init()
{    
    AcsGameEngine::Util::Misc::imageToSprites(*getAssetManager(), m_image, m_coords, m_sprites);

    const int center_x = getWindow()->getWidth() / 2 - m_sprites["start_btn"]->getSource().w / 2;
    const int center_y = 50;

    m_sprites["start_btn"]->setDestinationXY(center_x, center_y);

    getEventManager()->onMouseMove([](int x, int y)
    {
        std::cout << "MOUSE X: " << x << " MOUSE Y: " << y << '\n';
    });
}

void StartMenuState::handleEvents()
{
}

void StartMenuState::update(std::chrono::milliseconds deltaTime)
{
}

void StartMenuState::render()
{
    getRenderer()->drawSprite(*m_sprites["start_btn"]);
}

std::string StartMenuState::getName() const noexcept
{
    return "StartMenuState";
}
