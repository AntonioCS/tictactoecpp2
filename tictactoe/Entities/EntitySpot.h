#pragma once

#include "AcsGameEngine\Renderer.h"
#include "AcsGameEngine\Sprite.h"
#include "Entity.h"
#include "EntityItemType.h"
#include <unordered_map>
#include <utility>
#include <vector>

class EntitySpot : public Entity {
public:
    explicit EntitySpot(const AcsGameEngine::Texture& texture);

    EntitySpot(EntitySpot&& o)
        : m_sprite_cross(std::move(o.m_sprite_cross))
        , m_sprite_circle(std::move(o.m_sprite_circle))
        , m_renderer(std::move(o.m_renderer))
        , m_type(std::move(o.m_type))
        , m_clickAbleArea(std::move(o.m_clickAbleArea))
    {
    }

    ~EntitySpot();

    void setArea(const int x, const int y, const int w, const int h) noexcept;

    void reset();

    SDL_Rect getClickAbleArea() const noexcept;

    std::pair<int, int> getDrawPoint() const noexcept;

    bool isClicked() const noexcept;

    //void setClicked(EntityItemType::Type type, const int x, const int y) noexcept;
    void setClicked() noexcept;

    void setType(EntityItemType::Type type);

    EntityItemType::Type getType() const noexcept;

    bool isInsideArea(const int x, const int y) const noexcept;

    void draw() const noexcept;

    std::unordered_map<Uint32, EntitySpot::eventFunc> fetchEvents() noexcept override;
    bool isDisabled() const noexcept;
    void setDisabled() noexcept;

    bool isTypeSet() const noexcept;
private:
    AcsGameEngine::Sprite m_sprite_cross;
    AcsGameEngine::Sprite m_sprite_circle;
    const AcsGameEngine::Renderer& m_renderer;

    EntityItemType m_type{ EntityItemType::Type::not_set };

    SDL_Rect m_clickAbleArea{ 0, 0, 0, 0 };
    int m_draw_x{ 0 };
    int m_draw_y{ 0 };
    bool m_clicked{ false };
    bool m_disabled{ false };
};
