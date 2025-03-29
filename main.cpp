#include <iostream>
#include <vector>
#include <string>
#include "Character.h"
#include "Hero.h"  
#include "Location.h"
#include "Quest.h"
#include "QuestManager.h"
#include "Potion.h"
#include "Goblin.h"  
#include "Portal.h"
#include "Warrior.h"
#include "Rogue.h"
#include "Mage.h"


void displayMainMenu() {
    std::cout << "\nMain Menu:\n";
    std::cout << "1. Explore Location\n";
    std::cout << "2. View Stats\n";
    std::cout << "3. View Inventory\n";
    std::cout << "4. Save Game\n";
    std::cout << "5. Load Game\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    std::cout << "Welcome to Adventure Quest!\n";

  
    std::string heroName;
    int heroType;

    std::cout << "1. Create Hero\n";
    std::cout << "2. Exit\n";
    std::cout << "Choose an option: ";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Enter hero name: ";
        std::cin >> heroName;

        std::cout << "Choose hero type (1. Warrior, 2. Mage, 3. Rogue): ";
        std::cin >> heroType;

        Character* hero = nullptr;

    
        if (heroType == 1) {
            hero = new Warrior(heroName);
        } else if (heroType == 2) {
            hero = new Mage(heroName);
        } else if (heroType == 3) {
            hero = new Rogue(heroName);
        }

        std::cout << "Hero created: " << heroName << std::endl;
        hero->displayStats();

        QuestManager questManager;
        Quest* quest = nullptr; 

        
        bool running = true;
        while (running) {
            displayMainMenu();
            std::cin >> choice;

            if (choice == 1) {
                
                std::vector<Location*> locations = {
                    new Location("Enchanted Forest"),
                    new Location("Dark Dungeon"),
                    new Location("Quiet Village")
                };

                std::cout << "\nAvailable Locations:\n";
                for (size_t i = 0; i < locations.size(); ++i) {
                    std::cout << (i + 1) << ". " << locations[i]->getName() << "\n";
                }
                std::cout << "Choose a location: ";
                int locationChoice;
                std::cin >> locationChoice;

                Location* chosenLocation = locations[locationChoice - 1];
                std::cout << "\nYou enter the " << chosenLocation->getName() << "...\n";

               
                std::cout << "You encounter a Villager!\n";
                std::cout << "1. Talk to Villager\n";
                std::cout << "2. Ignore\n";
                std::cout << "Choose an action: ";
                std::cin >> choice;

                if (choice == 1) {
                    std::cout << "Villager: \"A Goblin has stolen my amulet! Please retrieve it.\"\n";
                    quest = new Quest("Retrieve the Stolen Amulet");
                    questManager.assignQuest(hero, quest);
                    std::cout << "Quest Accepted: " << quest->getQuestName() << "\n";
                }

                
                std::cout << "\nA Goblin appears! Health: 50 | Attack: 10\n";
                bool inCombat = true;

                while (inCombat) {
                    std::cout << "Your turn:\n";
                    std::cout << "1. Attack\n";
                    std::cout << "2. Cast Fireball\n";
                    std::cout << "3. Defend\n";
                    std::cout << "4. Use Potion\n";
                    std::cout << "Choose an action: ";
                    std::cin >> choice;

                    switch (choice) {
                        case 1:
                            std::cout << heroName << " attacks!\n";
                            break;
                        case 2:
                            std::cout << heroName << " casts Fireball! Deals 30 damage to Goblin.\n";
                            break;
                        case 3:
                            std::cout << heroName << " defends.\n";
                            break;
                        case 4:
                            std::cout << heroName << " uses a potion.\n";
                            break;
                        default:
                            std::cout << "Invalid action.\n";
                            continue;
                    }

                    std::cout << "Goblin attacks! Deals 8 damage to " << heroName << ".\n";
                    std::cout << heroName << " defeats the Goblin! Gained 20 XP and Stolen Amulet.\n";
                    inCombat = false;
                    questManager.completeQuest(hero, quest);
                }
            } else if (choice == 2) {
               
                hero->displayStats();
            } else if (choice == 3) {
            
                std::cout << heroName << "'s Inventory:\n";
                std::cout << "Stolen Amulet\n";
                std::cout << "Game saved!\n";
           
            } else if (choice == 5) {
               
                std::cout << "Game loaded!\n";
                
            } else if (choice == 6) {
                std::cout << "Goodbye!\n";
                running = false;
            } else {
                std::cout << "Invalid choice! Please select a valid option.\n";
            }
        }

    } else {
        std::cout << "Goodbye!\n";
    }

    return 0;
}
