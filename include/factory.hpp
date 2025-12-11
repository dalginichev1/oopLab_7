#pragma once
#include "npc.hpp"

struct NPCFactory {
    static std::shared_ptr<NPC> create(NpcType t, int x, int y);
    static std::shared_ptr<NPC> load(std::istream& is);
};