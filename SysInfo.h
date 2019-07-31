#ifndef SYS_INFO_H
#define SYS_INFO_H

#include <vector>
#include <string>
#include "ProcessParser.h"

using std::vector;
using std::string;
using std::to_string;

class SysInfo {
private:
    vector<string> lastCpuStats;
    vector<string> currentCpuStats;
    vector<string> coresStats;
    vector<vector<string>> lastCpuCoresStats;
    vector<vector<string>> currentCpuCoresStats;
    string cpuPercent;
    float memPercent;
    string osName;
    string kernelVer;
    long upTime;
    int totalProc;
    int runningProc;
    int threads;

public:
    SysInfo() {
        this->getOtherCores(ProcessParser::getNumberOfCores());
        this->setLastCpuMeasures();
        this->setAttributes();
        this->osName = ProcessParser::getOsName();
        this->kernelVer = ProcessParser::getSysKernelVersion();
    }

    void setAttributes();
    void setLastCpuMeasures();
    string getMemPercent() const;
    long getUpTime() const;
    string getThreads() const;
    string getTotalProc() const;
    string getRunningProc() const;
    string getKernelVersion() const;
    string getOsName() const;
    string getCpuPercent() const;
    void getOtherCores(int _size);
    void setCpuCoresStats();
    vector<string> getCoresStats() const;
};

string SysInfo::getCpuPercent() const 
{
    return this->cpuPercent;
}

string SysInfo::getMemPercent() const
{
    return to_string(this->memPercent);
}

string SysInfo::getCpuPercent() const
{
    return this->cpuPercent;
}

long SysInfo::getUpTime() const
{
    return this->upTime;
}

string SysInfo::getKernelVersion() const
{
    return this->kernelVer;
}

string SysInfo::getTotalProc() const
{
    return to_string(this->totalProc);
}

string SysInfo::getRunningProc() const
{
    return to_string(this->runningProc);
}

string SysInfo::getThreads() const
{
    return to_string(this->threads);
}

string SysInfo::getOsName() const
{
    return this->osName;
}

void SysInfo::setLastCpuMeasures()
{
    this->lastCpuCoresStats = ProcessParser::getSysCpuPercent();
}

#endif