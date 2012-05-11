#include "Piece.h"

int Piece::getOwner()
{
    return m_owner;
}

std::string Piece::getName()
{
    return m_name;
}

Piece::~Piece()
{
    //dtor
}
