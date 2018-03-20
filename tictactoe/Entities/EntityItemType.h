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

private:
    Type m_type;
};
