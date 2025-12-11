#pragma once

#include "npc.hpp"
#include <iostream>
#include <fstream>
#include <memory>
#include <mutex>

extern std::mutex g_cout_mutex;

struct ConsoleObserver : public IFightObserver {
    static std::shared_ptr<IFightObserver> get();
    void on_fight(const std::shared_ptr<NPC>& attacker,
                  const std::shared_ptr<NPC>& defender,
                  bool win) override;

private:
    ConsoleObserver() = default;
};

struct FileObserver : public IFightObserver {
    static std::shared_ptr<IFightObserver> get();
    void on_fight(const std::shared_ptr<NPC>& attacker,
                  const std::shared_ptr<NPC>& defender,
                  bool win) override;

private:
    FileObserver();
    ~FileObserver();

    std::ofstream logfile;
    std::mutex file_mutex;
};