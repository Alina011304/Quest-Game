#include "QuestManager.h"
#include <iostream>
#include <algorithm>  

QuestManager::QuestManager() {}

QuestManager::~QuestManager() {
    for (size_t i = 0; i < activeQuests.size(); ++i) {
        delete activeQuests[i];
    }
    for (size_t i = 0; i < completedQuests.size(); ++i) {
        delete completedQuests[i];
    }
}

void QuestManager::assignQuest(Character* hero, Quest* quest) {
    if (hero == nullptr || quest == nullptr) {
        std::cerr << "Error: Invalid hero or quest." << std::endl;
        return;
    }

    if (isQuestCompleted(quest)) {
        std::cout << "This quest has already been completed." << std::endl;
        return;
    }

    activeQuests.push_back(quest);
    std::cout << "Quest '" << quest->getQuestName() << "' assigned to " << hero->getname() << std::endl;
}

void QuestManager::checkQuestCompletion(Character* player) {
    Hero* hero = dynamic_cast<Hero*>(player); 
    
    if (hero) {
        for (size_t i = 0; i < activeQuests.size(); ++i) {
            if (activeQuests[i]->isCompleted(hero)) {
                completedQuests.push_back(activeQuests[i]);
                activeQuests.erase(activeQuests.begin() + i);
                std::cout << "Quest '" << activeQuests[i]->getQuestName() <<  std::endl;
                break;
            }
        }
    } else {
        std::cerr << "Error: Player is not a Hero!" << std::endl;
    }
}

void QuestManager::distributeRewards(Character* player) {
    for (size_t i = 0; i < completedQuests.size(); ++i) {
        if (completedQuests[i]->isQuestCompleted()) {
            int rewardExperience = completedQuests[i]->getRewardExperience();
            int rewardGold = completedQuests[i]->getRewardGold();

            std::cout << "Distributing rewards for completed quest: " << completedQuests[i]->getQuestName() << std::endl;
            std::cout << "Experience Reward: " << rewardExperience << std::endl;
            std::cout << "Gold Reward: " << rewardGold << std::endl;
        }
    }
}

void QuestManager::completeQuest(Character* hero, Quest* quest) {
    if (quest == nullptr || hero == nullptr) {
        std::cerr << "Error: Invalid quest or hero." << std::endl;
        return;
    }

    for (size_t i = 0; i < activeQuests.size(); ++i) {
        if (activeQuests[i] == quest) {
            activeQuests.erase(activeQuests.begin() + i);
            completedQuests.push_back(quest);

            std::cout << "Quest '" << quest->getQuestName() << "' completed by " << hero->getname() << std::endl;
            return;
        }
    }

    std::cout << "Quest '" << quest->getQuestName() << "' not found in active list." << std::endl;
}

void QuestManager::displayActiveQuests() const {
    std::cout << "Active Quests:" << std::endl;
    for (size_t i = 0; i < activeQuests.size(); ++i) {
        std::cout << "  - " << activeQuests[i]->getQuestName() << std::endl;
    }
}

void QuestManager::displayCompletedQuests() const {
    std::cout << "Completed Quests:" << std::endl;
    for (size_t i = 0; i < completedQuests.size(); ++i) {
        std::cout << "  - " << completedQuests[i]->getQuestName() << std::endl;
    }
}

bool QuestManager::isQuestCompleted(Quest* quest) const {
    for (size_t i = 0; i < completedQuests.size(); ++i) {
        if (completedQuests[i] == quest) {
            return true;
        }
    }
    return false;
}
