#pragma once

#include <vector>
#include <unordered_map>
#include <string>
#include <utility> //std::pair

#include "AcsGE/Sprite.h"
#include "AcsGE/GameState.h"


class StartMenuState : public AcsGameEngine::GameState
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

    enum class ButtonState
    {
        NORMAL,
        HOVER,
        PRESSED
    };

    std::string m_image{ "assets/menu_buttons.png" };
    std::unordered_map<std::string, std::unique_ptr<AcsGameEngine::Sprite>> m_sprites;

    std::vector<itemCoord> m_coords{
        itemCoord{"start_btn", {1, 3, 72, 38}},
        itemCoord{"start_btn_hover", {75, 3, 72, 38}},
        itemCoord{"start_btn_pressed", {149, 3, 72, 38}},
        itemCoord{"quit_btn", {1, 47, 72, 38}},
        itemCoord{"quit_btn_hover", {75, 3, 72, 38}},
        itemCoord{"quit_btn_pressed", {149, 3, 72, 38}}
    };
    std::unordered_map<std::string, std::vector<std::unordered_map<ButtonState, std::string>>> btnStates{
        {
            "startBtn", 
            {
                {
                    {ButtonState::NORMAL, "start_btn"},
                    {ButtonState::HOVER, "start_btn_hover"},
                    {ButtonState::PRESSED, "start_btn_pressed"}
                }
            }
        },
        {
            "quitBtn",  
            {
                {
                    {ButtonState::NORMAL, "quit_btn"},
                    {ButtonState::HOVER, "quit_btn_hover"},
                    {ButtonState::PRESSED, "quit_btn_pressed"}
                }
            }
        }
    };
};
