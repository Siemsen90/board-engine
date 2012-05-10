#include "GameException.h"

GameException::GameException(const std::string& msg)
{
    message = msg;
}

std::string GameException::getMessage( ) const
{
    return(message);
}
