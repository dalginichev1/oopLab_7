#pragma once
#include "npc.hpp"

struct Orc : public NPC {
    Orc(int x, int y);
    Orc(std::istream& is);

    bool accept(const std::shared_ptr<NPC>& attacker) override;

    bool visit_orc(const std::shared_ptr<Orc>&) override;
    bool visit_bear(const std::shared_ptr<Bear>&) override;
    bool visit_squirrel(const std::shared_ptr<Squirrel>&) override;

    void print() const override;
    void save(std::ostream& os) const override;

    int get_move_distance() const override { return 20; }
    int get_kill_distance() const override { return 10; }
};