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

#endif