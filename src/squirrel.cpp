#include "squirrel.hpp"

#include "bear.hpp"
#include "orc.hpp"

Squirrel::Squirrel(int x, int y) : NPC(NpcType::SquirrelType, x, y) {
}
Squirrel::Squirrel(std::istream& is) : NPC(NpcType::SquirrelType, 0, 0) {
    int tmp_x, tmp_y;
    is >> tmp_x >> tmp_y;
    x = tmp_x;
    y = tmp_y;
}

bool Squirrel::accept(const std::shared_ptr<NPC>& attacker) {
    return attacker->visit_squirrel(std::static_pointer_cast<Squirrel>(shared_from_this()));
}

bool Squirrel::visit_orc(const std::shared_ptr<Orc>& defender) {
    bool w = false;
    fight_notify(defender, w);
    return w;
}
bool Squirrel::visit_bear(const std::shared_ptr<Bear>& defender) {
    bool w = false;
    fight_notify(defender, w);
    return w;
}
bool Squirrel::visit_squirrel(const std::shared_ptr<Squirrel>& defender) {
    bool w = rand() % 2;
    fight_notify(defender, w);
    return w;
}

void Squirrel::print() const {
    std::cout << "Squirrel (" << x << "," << y << ")";
}
void Squirrel::save(std::ostream& os) const {
    os << int(type) << ' ' << x << ' ' << y << '\n';
}