#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <stdexcept>
#include <string>

class GameException
{
    public:
        GameException(const std::string& msg);
        ~GameException( ) {}

       std::string getMessage( ) const;
    private:
        std::string message;
};

#endif // GAMEEXCEPTION_H
