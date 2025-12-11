#include "factory.hpp"

#include "bear.hpp"
#include "observers.hpp" // ← добавим наблюдателей
#include "orc.hpp"
#include "squirrel.hpp"

std::shared_ptr<NPC> NPCFactory::create(NpcType t, int x, int y) {
    std::shared_ptr<NPC> npc;
    switch (t) {
    case NpcType::OrcType:
        npc = std::make_shared<Orc>(x, y);
        break;
    case NpcType::BearType:
        npc = std::make_shared<Bear>(x, y);
        break;
    case NpcType::SquirrelType:
        npc = std::make_shared<Squirrel>(x, y);
        break;
    default:
        return nullptr;
    }
    npc->subscribe(ConsoleObserver::get());
    npc->subscribe(FileObserver::get());
    return npc;
}

std::shared_ptr<NPC> NPCFactory::load(std::istream& is) {
    int t, x, y;
    if (!(is >> t >> x >> y))
        return nullptr;
    return create(static_cast<NpcType>(t), x, y);
}