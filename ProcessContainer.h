#ifndef PROCESS_CONTAINER_H
#define PROCESS_CONTAINER_H

#include <string>
#include <vector>
#include "Process.h"
using std::string;
using std::vector;

class ProcessContainer
{
private:
    vector<Process> _list; 

public:
    ProcessContainer()
    {
        this->refreshList();
    }
    void refreshList();
    string printList();
    vector<string> getList();
};

void ProcessContainer::refreshList()
{
    vector<string> pids = ProcessParser::getPidList();
    this->_list.clear();
    for (auto pid : pids) {
        Process proc(pid);
        this->_list.push_back(proc);
    }
}

string ProcessContainer::printList()
{
    std::string result = "";
    for (auto i : _list) {
        result += i.getProcess();
    }
    return result;
}

#endif