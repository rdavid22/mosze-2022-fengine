#ifndef FILE_HANDLER_H_
#define FILE_HANDLER_H_

#include "objects/frame.h"

#include <vector>
#include <iostream>
#include <fstream>
// Note: it's temporary, will be deleted later!!!.
#include "json.hpp"

#include "console.h"
using json = nlohmann::json;

/**
 * @brief Reads from json file and creates Item list
 *
 * @return std::vector<Item>
 */

std::vector<Frame> ReadFrames()
{

    std::ifstream file("../frames.json");
    json data = json::parse(file);

    std::vector<Frame> frames = std::vector<Frame>();

    for (auto frame : data["frames"])
    {
        std::vector<Answer> answers = std::vector<Answer>();

        for (auto answer : frame["asnwers"])
        {
            answers.push_back(Answer(answer["reply"],answer["frame_id"]));
        }
        Frame new_frame = Frame(frame["id"],frame["text"],answers);

        frames.push_back(new_frame);
    }

    return frames;
}
/*
void SavePlayer(Player player)
{
    json savefile;
    auto players = ReadPlayers();
    bool thereWasAPlayer = false;
    for (auto p : players)
    {
        if (p.GetPlayerName() == player.GetPlayerName())
        {
            thereWasAPlayer = true;
        }
    }
    if (!thereWasAPlayer)
    {
        players.push_back(player);
    }
    for (auto p : players)
    {
        if (thereWasAPlayer)
        {
            if (p.GetPlayerName() == player.GetPlayerName())
            {
                p = player;
            }
        }
        json inventory;
        json answers;

        auto inv = p.GetInventory();
        auto ans = p.GetAnswers();
        for (auto i : inv)
        {
            inventory.push_back(
                {{"name", i.item_name_},
                 {"amount", i.amount_}});
        }
        for(auto a : ans)
        {
            answers.push_back(
                {{"id", a.conversation_id_},
                {"answer", a.answer_}});
        }

        savefile["players"].push_back(
            {{"playerName", p.GetPlayerName()},
             {"currentRoom", p.GetCurrentRoomId()},
             {"invertoryList", inventory},
             {"conversations", answers}});
    }

    std::ofstream o("../game/savegame.json");
    o << std::setw(4) << savefile << std::endl;
    o.
    close();
}
*/
#endif