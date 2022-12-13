#ifndef FENGINE_OBJECTS_PLAYER_H_
#define FENGINE_OBJECTS_PLAYER_H_

#include <iostream>

class Player
{
private:
    std::string name_;
    uint16_t frame_id_;

public:
    Player(std::string name, uint16_t frame_id)
    {
        name_ = name;
        frame_id_ = frame_id;
    }

    Player() {}

    std::string GetName()
    {
        return name_;
    }

    uint16_t GetFrameId()
    {
        return frame_id_;
    }

    void SetName(std::string name)
    {
        name_ = name;
    }

    void SetFrameId(uint16_t frame_id)
    {
        frame_id_ = frame_id;
    }
};

#endif