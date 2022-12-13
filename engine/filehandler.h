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

/*
std::vector<Item> ReadItems()
{

    std::vector<Item> items = std::vector<Item>();
    std::ifstream file("../game/items.json");
    json data = json::parse(file);

    for (auto item : data["items"])
    {
        Item new_item = Item();

        new_item.SetId(item["id"]);
        new_item.SetDescription(item["description"]);
        new_item.SetDisplayName(item["displayName"]);
        new_item.SetName(item["name"]);

        items.push_back(new_item);
    }

    file.close();

    return items;
}

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