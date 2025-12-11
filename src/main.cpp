#include <iostream>
#include <chrono>
#include <thread>
#include "world.hpp"

int main() {
    std::cout << "=== Симуляция NPC (30 секунд) ===\n";
    std::cout << "O — Orc, B — Bear, S — Squirrel\n\n";

    World world;
    world.start();

    std::this_thread::sleep_for(std::chrono::seconds(World::GAME_DURATION_SEC + 5));

    std::cout << "Программа завершена.\n";
    return 0;
}