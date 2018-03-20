#include "EntityItemType.h"



EntityItemType::EntityItemType(Type type) : m_type(type)
{
}


EntityItemType::~EntityItemType()
{
}

void EntityItemType::setType(Type type)
{
    m_type = type;
}

EntityItemType::Type EntityItemType::getType() const noexcept
{
    return m_type;
}
