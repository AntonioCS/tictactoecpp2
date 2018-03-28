#include "Game.h"
#include <iostream>
#include "AcsGameEngine\Window.h"
#include "AcsGameEngine/Sprite.h"

Game::Game(AcsGameEngine::Renderer& renderer, AcsGameEngine::EventManager& em)
    : m_renderer(renderer)
    , m_em(em)
    , m_mainTexture("assets/board_items.png")
    , m_board(m_renderer.MakeTexture(m_mainTexture))
    , m_selectedType(EntityItemType::Type::circle)
    , m_leaderBoard(m_renderer.MakeTexture(m_mainTexture))
{
    setupBoardEntity();

    createSpots();
    setupSpotEntities();

    setupLeaderBoardEntity();
}

Game::~Game()
{
}


void Game::update()
{
    for (auto& spot : m_spots) {
        if (spot.isClicked() && !spot.isTypeSet()) {
            spot.setType(m_selectedType.getType());

            m_selectedType.switchType();
        }
    }
}

void Game::draw()
{
    m_renderer.DrawSprite(m_board.getSprite());   

    for (auto& spot : m_spots) {
        if (spot.isClicked()) {            
            if (spot.getType() == EntityItemType::Type::circle) {
                m_renderer.DrawSprite(spot.getSpriteCircle());
            }
            else {
                m_renderer.DrawSprite(spot.getSpriteCross());
            }
        }
        //spot.draw();
    }
}

void Game::setupBoardEntity()
{
    constexpr int board_w = 653;
    constexpr int board_h = 480;
    auto[win_w, win_h] = m_renderer.getWindow().getSize();
    int board_x = win_w / 2 - board_w / 2;
    int board_y = win_h / 2 - board_h / 2 + 50;

    m_board.getSprite().setSourceXYWH(0, 0, board_w, board_h);
    m_board.getSprite().setDestinationXYWH(board_x, board_y, board_w, board_h);
}

void Game::createSpots() noexcept
{
    auto main_texture = m_renderer.MakeTexture(m_mainTexture);
    constexpr uint16_t  spot_w = 208;
    constexpr uint16_t  spot_h = 150;
    constexpr uint16_t  space = 16;

    constexpr SDL_Rect circle_source{ 656, 120, 95, 120 };
    constexpr uint16_t  circle_width = 95;
    constexpr uint16_t  circle_height = 120;
    constexpr uint16_t  circle_center_x = spot_w / 2 - circle_width / 2;
    constexpr uint16_t  circle_center_y = spot_h / 2 - circle_height / 2;

    constexpr SDL_Rect cross_source{ 656, 0, 95, 117 };
    constexpr uint16_t  cross_width = 95;
    constexpr uint16_t  cross_height = 117;
    constexpr uint16_t  cross_center_x = spot_w / 2 - cross_width / 2;
    constexpr uint16_t  cross_center_y = spot_h / 2 - cross_height / 2;

    auto[board_x, board_y] = m_board.getPoint();

    for (int iY = 0; iY < 3; iY++) {
        for (int iX = 0; iX < 3; iX++) {
            int x = board_x + (spot_w * iX) + (space * iX) - (1 * iX);
            int y = board_y + (spot_h * iY) + (space * iY) - (1 * iY);

            auto& spot = m_spots.emplace_back(main_texture);
            spot.setArea(x, y, spot_w, spot_h);

            auto &circleSprite = spot.getSpriteCircle();
            auto &crossSprite = spot.getSpriteCross();

            circleSprite.setSource(circle_source);
            circleSprite.setDestinationXYWH(x + circle_center_x, y + circle_center_y, circle_width, circle_height);

            crossSprite.setSource(cross_source);
            crossSprite.setDestinationXYWH(x + cross_center_x, y + cross_center_y, cross_width, cross_height);
        }
    }
}

void Game::setupSpotEntities() {
    for (auto& spot : m_spots) {
        auto events = spot.fetchEvents();
        for (auto[eventName, func] : events) {
            m_em.attach(eventName, func);
        }
    }
}

void Game::setupLeaderBoardEntity() noexcept
{
}

void Game::resetGame()
{
    for (auto& spot : m_spots) {
        spot.setClicked(false);
        spot.setDisabled(false);
        spot.setType(EntityItemType::Type::circle);
    }
}
