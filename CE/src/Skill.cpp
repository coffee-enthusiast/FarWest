#include "../include/Skill.h"
#include "../../UI/include/Trace.h"

Skill::Skill()
{

}

Skill::Skill(std::string skillName, int skillLevel, int skillBufferAmount, int skillBufferMax, int maxSkillLevel)
{
    this->skillName = skillName;
    this->skillLevel = skillLevel;
    this->skillBufferAmount = skillBufferAmount;
    this->skillBufferMax = skillBufferMax;
    this->maxSkillLevel = maxSkillLevel;
}

void Skill::trainSkill(int amount)
{
    // Can't train it any more
    if(skillLevel == maxSkillLevel)
        return;

    fTrace("Train "+ skillName+" for " + std::to_string(amount));
    skillBufferAmount += amount;
    if(skillBufferAmount >= skillBufferMax)
    {
        int newSkills = skillBufferAmount / skillBufferMax;
        
        skillLevel += newSkills;

        if(skillLevel >= maxSkillLevel)
        {
            skillLevel = maxSkillLevel;
            skillBufferAmount = 0;
            return;
        }
        skillBufferAmount -= newSkills * skillBufferMax;
    }
    
}