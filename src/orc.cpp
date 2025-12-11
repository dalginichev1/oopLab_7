#include "orc.hpp"

#include "bear.hpp"
#include "squirrel.hpp"

Orc::Orc(int x, int y) : NPC(NpcType::OrcType, x, y) {
}
Orc::Orc(std::istream& is) : NPC(NpcType::OrcType, 0, 0) {
    int tmp_x, tmp_y;
    is >> tmp_x >> tmp_y;
    x = tmp_x;
    y = tmp_y;
}

bool Orc::accept(const std::shared_ptr<NPC>& attacker) {
    return attacker->visit_orc(std::static_pointer_cast<Orc>(shared_from_this()));
}

bool Orc::visit_orc(const std::shared_ptr<Orc>& defender) {
    bool w = rand() % 2;
    fight_notify(defender, w);
    return w;
}
bool Orc::visit_bear(const std::shared_ptr<Bear>& defender) {
    bool w = true;
    fight_notify(defender, w);
    return w;
}
bool Orc::visit_squirrel(const std::shared_ptr<Squirrel>& defender) {
    bool w = true;
    fight_notify(defender, w);
    return w;
}

void Orc::print() const {
    std::cout << "Orc   (" << x << "," << y << ")";
}
void Orc::save(std::ostream& os) const {
    os << int(type) << ' ' << x << ' ' << y << '\n';
}