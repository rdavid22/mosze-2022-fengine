#ifndef FENGINE_OBJECTS_PLAYER_H_
#define FENGINE_OBJECTS_PLAYER_H_

#include <iostream>

class Player
{
private:
    std::string name_;
    uint16_t text_id_;

public:
    Player(std::string name, uint16_t text_id)
    {
        name_ = name;
        text_id_ = text_id;
    }

    Player() {}

    std::string GetName()
    {
        return name_;
    }

    uint16_t GetTextId()
    {
        return text_id_;
    }

    void SetName(std::string name)
    {
        name_ = name;
    }

    void SetTextId(uint16_t text_id)
    {
        text_id_ = text_id;
    }
};

#endif