#include "MainState.h"
#include "AcsGE/ECS/Entity.h"
#include "AcsGE/ECS/EntityManager.h"
#include "AcsGE/ECS/Components/SpriteComponent.h" //include Rectangle.h
#include "AcsGE/GameStateManager.h"
#include "AcsGE/Renderer.h"
#include <algorithm>
#include <SDL2/SDL.h>
#include <iostream>
#include "AcsGE/Util/Misc.h"
#include "AcsGE/Util/CollisionDetection.h"

namespace {
    using AcsGameEngine::ECS::EntityManager;
    using AcsGameEngine::ECS::SpriteComponent;
    using AcsGameEngine::Util::Shapes::Rectangle;
}

void MainState::init()
{

    AcsGameEngine::Util::Misc::imageToSprites(*getAssetManager(), m_images, m_coords, m_sprites);

    /*
    AcsGameEngine::ECS::EntityManager em;    
    auto board = &(em.make_entity());
    auto texture = getRenderer()->make_texture("assets/board_items.png");
    Rectangle rect{ {20, 20}, {653, 480} };

    board->addComponent<SpriteComponent>(texture, rect, 0, 0);
    board->getComponent<SpriteComponent>().getSprite();
    */

    const int board_x = getWindow()->getWidth() / 2 - m_sprites["board"]->getSource().w / 2;
    const int board_y = 50;

    m_sprites["board"]->setDestinationXY(board_x, board_y);
}

void MainState::handleEvents()
{
}

void MainState::update(std::chrono::milliseconds deltaTime)
{
}

void MainState::render()
{
    auto *r = getRenderer();

    r->drawSprite(*m_sprites["board"]);

    //r->DrawSprite();
}

std::string MainState::getName() const noexcept
{
    return "MainState";
}
