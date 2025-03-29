#ifndef QUESTMANAGER
#define QUESTMANAGER

#include <vector>
#include "Quest.h"
#include "Character.h"

class QuestManager {
private:
    std::vector<Quest*> activeQuests;       
    std::vector<Quest*> completedQuests;    

public:

    QuestManager();  
    ~QuestManager();  
    
    void assignQuest(Character* hero, Quest* quest);  
    void checkQuestCompletion(Character* player);  
    void distributeRewards(Character* player);  
    void displayActiveQuests() const;
    void displayCompletedQuests() const;
    bool isQuestCompleted(Quest* quest) const;  
    void completeQuest(Character* hero, Quest* quest);
};

#endif
