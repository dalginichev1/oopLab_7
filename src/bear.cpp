#include "bear.hpp"

#include "orc.hpp"
#include "squirrel.hpp"

Bear::Bear(int x, int y) : NPC(NpcType::BearType, x, y) {
}
Bear::Bear(std::istream& is) : NPC(NpcType::BearType, 0, 0) {
    int tmp_x, tmp_y;
    is >> tmp_x >> tmp_y;
    x = tmp_x;
    y = tmp_y;
}

bool Bear::accept(const std::shared_ptr<NPC>& attacker) {
    return attacker->visit_bear(std::static_pointer_cast<Bear>(shared_from_this()));
}

bool Bear::visit_orc(const std::shared_ptr<Orc>& defender) {
    bool w = false;
    fight_notify(defender, w);
    return w;
}
bool Bear::visit_bear(const std::shared_ptr<Bear>& defender) {
    bool w = rand() % 2;
    fight_notify(defender, w);
    return w;
}
bool Bear::visit_squirrel(const std::shared_ptr<Squirrel>& defender) {
    bool w = true;
    fight_notify(defender, w);
    return w;
}

void Bear::print() const {
    std::cout << "Bear  (" << x << "," << y << ")";
}
void Bear::save(std::ostream& os) const {
    os << int(type) << ' ' << x << ' ' << y << '\n';
}