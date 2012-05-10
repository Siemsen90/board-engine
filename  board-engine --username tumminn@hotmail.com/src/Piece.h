#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <cctype>

class Piece
{
    public:
        Piece(std::string name = ".", int owner = -1)
            :m_name(name),m_owner(owner)
            {};
        virtual ~Piece();

        int getOwner();
        std::string getName();//Always returns as lower case
    protected:
    private:
        std::string m_name;
        int m_owner;
};

#endif // PIECE_H
