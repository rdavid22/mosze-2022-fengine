#ifndef FILE_HANDLER_H_
#define FILE_HANDLER_H_

#include "objects/frame.h"
#include "objects/player.h"


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

        for (auto answer : frame["answers"])
        {
            answers.push_back(Answer(answer["reply"],answer["frame_id"]));
        }
        Frame new_frame = Frame(frame["id"],frame["text"],answers);

        frames.push_back(new_frame);
    }

    return frames;
}
std::vector<Player> ReadPlayers()
{
     std::ifstream file("../players.json");
    json data = json::parse(file);

    std::vector<Player> players = std::vector<Player>();

    for (auto player : data["players"])
    {
        players.push_back(Player(player["name"],player["frame_id"]));
    }
    return players;
}

void SavePlayer(Player player)
{
    json savefile;
    auto players = ReadPlayers();
    bool thereWasAPlayer = false;
    for (auto p : players)
    {
        if (p.GetName() == player.GetName())
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
            if (p.GetName() == player.GetName())
            {
                p = player;
            }
        }
        json answers;

        savefile["players"].push_back(
            {{"name", p.GetName()},
             {"frame_id", p.GetFrameId()}});
    }

    std::ofstream o("../players.json");
    o << std::setw(4) << savefile << std::endl;
    o.
    close();
}
#endif