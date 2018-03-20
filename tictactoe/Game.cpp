#include "Game.h"
#include <iostream>

Game::Game(const AcsGameEngine::Renderer& renderer, AcsGameEngine::EventManager& em)
    : m_renderer(renderer)
    , m_em(em)
    , m_mainTexture(m_renderer.MakeTexture("assets/board_items.png"))
    , m_board(m_renderer.MakeSprite(m_mainTexture))
{
    createSpots();
    setupEntities();

   
}

Game::~Game()
{
}



void Game::update()
{
    for (auto& spot : m_spots) {
        if (spot.isClicked() && !spot.isTypeSet()) {            
            spot.setType(EntityItemType::Type::cross);
        }
    }
}

void Game::draw()
{
    m_board.draw();

    for (const auto& spot : m_spots) {
        spot.draw();
    }
}

void Game::createSpots() noexcept
{
    constexpr int spot_w = 208;
    constexpr int spot_h = 150;
    constexpr int space = 16;
    auto[board_x, board_y] = m_board.getPoint();

    m_spots.reserve(m_totalSpots);

    for (int iY = 0; iY < 3; iY++) {
        for (int iX = 0; iX < 3; iX++) {
            int x = board_x + (spot_w * iX) + (space * iX) - (1 * iX);
            int y = board_y + (spot_h * iY) + (space * iY) - (1 * iY);

            auto& spot = m_spots.emplace_back(m_mainTexture);
            spot.setArea(x, y, spot_w, spot_h);
        }
    }
}

void Game::setupEntities() {
    for (auto& spot : m_spots) {
        auto events = spot.fetchEvents();
        for (auto[eventName, func] : events) {
            m_em.attach(eventName, func);
        }
    }
}