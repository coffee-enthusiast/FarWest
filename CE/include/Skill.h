#pragma once
#include <string>

class Skill
{
public:
    std::string skillName;
    int skillLevel;
    int skillBufferAmount;
    int skillBufferMax;
    int maxSkillLevel;

    Skill();
    Skill(std::string skillName, int skillLevel, int skillBufferAmount, int skillBufferMax, int maxSkillLevel);
    void trainSkill(int amount);
};