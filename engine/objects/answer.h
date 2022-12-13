#ifndef FENGINE_OBJECTS_ANSWER_H_
#define FENGINE_OBJECTS_ANSWER_H_

#include "iostream"
#include <vector>

class Answer
{
private:
    uint16_t id_;
    std::string text_;

public:
    Answer()
    {
    }
    Answer(uint16_t id, std::string text)
    {
        text_ = text;
        id_ = id;
    }

    uint16_t GetId()
    {
        return id_;
    }
    std::string GetText()
    {
        return text_;
    }

    void SetId(uint16_t id)
    {
        id_ = id;
    }
    void SetText(std::string text)
    {
        text_ = text;
    }
};

#endif