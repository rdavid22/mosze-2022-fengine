#ifndef FENGINE_OBJECTS_FRAME_H_
#define FENGINE_OBJECTS_FRAME_H_

#include "iostream"
#include <vector>
#include "answer.h"

class Frame
{
private:
    uint16_t id_;
    std::string text_;
    std::vector<Answer> answers_;

public:
    Frame(uint16_t id, std::string text, std::vector<Answer> answers)
    {
        id_ = id;
        text_ = text;
        answers_ = answers;
    }
    Frame()
    {
    }

    uint16_t GetId()
    {
        return id_;
    }
    std::string GetText()
    {
        return text_;
    }
    std::vector<Answer> GetAnswers()
    {
        return answers_;
    }

    void SetId(uint16_t id)
    {
        id_ = id;
    }
    void SetText(std::string text)
    {
        text_ = text;
    }
    void SetAnswers(std::vector<Answer> answers)
    {
        answers_ = answers;
    }
};

#endif