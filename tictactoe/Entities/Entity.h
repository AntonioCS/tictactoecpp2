#pragma once
#include "AcsGameEngine/Texture.h"
#include "AcsGameEngine/Sprite.h"
#include <functional>
#include <vector>

class Entity
{
protected:
    using eventFunc = std::function<void(SDL_Event &)>;    
public:
    ~Entity() = default;
    virtual std::unordered_map<Uint32, eventFunc> fetchEvents() noexcept = 0;
};

