#pragma once

#include <memory>
#include <string>
#include <vector>

class Overview
{
public:
    class OverviewStep
    {
    private:
        int step;
        std::string title;
        std::vector<std::string> info;
    public:
        OverviewStep(int step, std::string title) : step{ step }, title{ title } {}
        int GetStep() const { return step; }
        std::string GetTitle() const { return title; }
        void AddInfo(std::string infoString) { info.push_back(infoString); }
    };

    Overview();
    ~Overview();

    std::vector<std::shared_ptr<OverviewStep>> const& GetSteps() const { return steps; }

private:
    std::vector<std::shared_ptr<OverviewStep>> steps;
};
