#include "observers.hpp"

std::mutex g_cout_mutex;

// ConsoleObserver — синглтон
std::shared_ptr<IFightObserver> ConsoleObserver::get() {
    static ConsoleObserver instance;
    return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver*) {});
}

void ConsoleObserver::on_fight(const std::shared_ptr<NPC>& attacker,
                               const std::shared_ptr<NPC>& defender, bool win) {
    std::lock_guard<std::mutex> lock(g_cout_mutex);
    std::cout << "=== БОЙ ===\n";
    attacker->print();
    std::cout << (win ? " ПОБЕДИЛ " : " ПРОИГРАЛ ");
    defender->print();
    std::cout << "\n\n";
}

// FileObserver — синглтон
FileObserver::FileObserver() {
    logfile.open("fight_log.txt", std::ios::app);
}

FileObserver::~FileObserver() {
    if (logfile.is_open()) {
        logfile.close();
    }
}

std::shared_ptr<IFightObserver> FileObserver::get() {
    static FileObserver instance;
    return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver*) {});
}

void FileObserver::on_fight(const std::shared_ptr<NPC>& attacker,
                            const std::shared_ptr<NPC>& defender, bool win) {
    std::lock_guard<std::mutex> lock(file_mutex);
    if (!logfile.is_open())
        return;

    logfile << "Fight: ";
    attacker->print();
    logfile << " ";
    logfile << (win ? "wins against " : "loses to ");
    defender->print();
    logfile << "\n";
    logfile.flush();
}