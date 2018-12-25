#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include <utility> //std::pair
#include <vector>

#include "AcsGE/GameState.h"
//#include "AcsGE/Renderer.h"
//#include "AcsGE/ECS/Entity.h"
#include "AcsGE/Texture.h"
#include "AcsGE/Sprite.h"
#include <SDL2/SDL.h>

class MainState : public AcsGameEngine::GameState
{
public:
    using itemCoord = std::pair<std::string, SDL_Rect>;
    using AcsGameEngine::GameState::GameState;

    void init() override;
    void handleEvents() override;
    void update(std::chrono::milliseconds deltaTime) override;
    void render() override;
    std::string getName() const noexcept override;
private:
    std::string m_images{ "assets/board_items.png" };
    std::unique_ptr<AcsGameEngine::Texture> m_allAssets;
    std::vector<itemCoord> m_coords{
        itemCoord{"board", {0, 0, 654, 478}},
        itemCoord{"item_x", {655, 0, 96, 114}},
        itemCoord{"item_o", {655, 120, 96, 114}}
    };

    std::unordered_map<std::string, std::unique_ptr<AcsGameEngine::Sprite>> m_sprites;

    //AcsGameEngine::ECS::Entity *m_board;
};
