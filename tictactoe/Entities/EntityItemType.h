#pragma once

class EntityItemType {
public:
    enum class Type {
        cross,
        circle,
        not_set
    };
    explicit EntityItemType(Type type);
    ~EntityItemType();

    void setType(Type type);
    Type getType() const noexcept;
    void switchType();

private:
    Type m_type;
};
