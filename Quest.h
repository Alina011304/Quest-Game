#ifndef QUEST
#define QUEST
#include <string>
#include "Character.h"  
#include "Hero.h"      

class Quest {
private:
    std::string questName;
    bool completed;
    int requiredLevel;
    int rewardExperience;
    int rewardGold;

public:
   
    Quest(std::string name, int levelRequirement = 1, int expReward = 100, int goldReward = 50): questName(name), completed(false), requiredLevel(levelRequirement), rewardExperience(expReward), rewardGold(goldReward) {}
   
    std::string getQuestName() const 
    {
        return questName;
    }
    int getRewardExperience() const 
    {

        return rewardExperience;
    }

    int getRewardGold() const 
    {
        return rewardGold;
    }

    bool isCompleted(Hero* player) 
    {
        
        if (player->getLevel() >= requiredLevel && completed) {
            return true;
        }
        return false;
    }

    
    void completeQuest() 
    {
        completed = true;
    }
    void resetQuest() 
    {
        completed = false;
    }

    void setRewards(int exp, int gold) {
        rewardExperience = exp;
        rewardGold = gold;
    }

    bool isQuestCompleted() const {
        return completed;
    }
    void setRequiredLevel(int level)
    {
        requiredLevel = level;
    }
};

#endif
