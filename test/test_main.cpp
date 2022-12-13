#include <gtest/gtest.h>

#include "../engine/filehandler.h"
#include "../engine/objects/frame.h"
#include "../engine/objects/player.h"
#include "../engine/objects/answer.h"

TEST(TestPlayer, PlayerTest)
{
    Player test_player("Test", 0);
    EXPECT_EQ(test_player.GetName(), "Test");
    EXPECT_EQ(test_player.GetFrameId(), 0);
}

TEST(TestFrame, FrameTest)
{
    std::vector<Answer> test_answers;
    Answer answer;
    answer.SetId(1);
    for (int i = 0; i < 5; i++)
    {
        test_answers.push_back(answer);
    }
    Frame test_frame(1, "Teszt", test_answers);
    EXPECT_EQ(test_frame.GetId(), 1);
    EXPECT_EQ(test_frame.GetText(), "Teszt");
}