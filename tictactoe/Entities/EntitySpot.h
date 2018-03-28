#pragma once

#include <unordered_map>
#include <utility>
#include <vector>

#include "..\AcsGameEngine\Renderer.h"
#include "..\AcsGameEngine\Sprite.h"
#include "..\AcsGameEngine\Texture.h"
#include "Entity.h"
#include "EntityItemType.h"

class EntitySpot : public Entity {
public:
    explicit EntitySpot(std::shared_ptr<AcsGameEngine::Texture>);
    EntitySpot(EntitySpot&& o)
        : m_sprite_cross(std::move(o.m_sprite_cross))
        , m_sprite_circle(std::move(o.m_sprite_circle))        
        , m_type(std::move(o.m_type)) 
        , m_clickAbleArea(std::move(o.m_clickAbleArea))
    {
    }
    EntitySpot(const EntitySpot &) = delete;
    ~EntitySpot() = default;

    void setArea(const int x, const int y, const int w, const int h) noexcept;
    void reset();
    SDL_Rect getClickAbleArea() const noexcept;

    std::pair<int, int> getDrawPoint() const noexcept;

    bool isClicked() const noexcept;

    //void setClicked(EntityItemType::Type type, const int x, const int y) noexcept;
    void setClicked(bool state = true) noexcept;
    void setType(EntityItemType::Type type);
    EntityItemType::Type getType() const noexcept;
    bool isInsideArea(const int x, const int y) const noexcept;
    //void draw() const noexcept;
    std::unordered_map<Uint32, EntitySpot::eventFunc> fetchEvents() noexcept override;
    bool isDisabled() const noexcept;
    void setDisabled(bool state = true) noexcept;

    bool isTypeSet() const noexcept;

    AcsGameEngine::Sprite &getSpriteCross();
    AcsGameEngine::Sprite &getSpriteCircle();

private:
    AcsGameEngine::Sprite m_sprite_cross;
    AcsGameEngine::Sprite m_sprite_circle;
    EntityItemType m_type{ EntityItemType::Type::not_set };

    SDL_Rect m_clickAbleArea{ 0, 0, 0, 0 };

    int m_draw_x{ 0 };
    int m_draw_y{ 0 };
    bool m_clicked{ false };
    bool m_disabled{ false };
};
