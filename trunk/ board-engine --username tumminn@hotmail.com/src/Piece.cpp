#include "Piece.h"

int Piece::getOwner()
{
    return m_owner;
}

std::string Piece::getName()
{
    std::string::iterator it = m_name.begin();

    for(; it != m_name.end(); ++it)
    {
        *it = std::tolower(*it);
    }
    return m_name;
}

Piece::~Piece()
{
    //dtor
}
