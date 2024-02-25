//ProcessQuery.h
#pragma once

#include <iostream>
#include <string>
#include <windows.h>
#include <tlHelp32.h>
#include <psapi.h>
#include <vector>

bool debug;

struct ProcessInfo {
    char name[260];
    DWORD pid;
    DWORD parent_pid;
} typedef ProcessInfo;

void setDebug(bool);

// Get a Process Name from PID
//extern "C" __declspec(dllexport) std::string GetProcessName(DWORD pid);
//std::string GetProcessName(DWORD pid);

//Get all Processes currently Running
//extern "C" __declspec(dllexport) std::vector<ProcessInfo> GetAllProcessSnapShot();
//std::vector<ProcessInfo> GetAllProcessSnapShot();


// Experiment #2

class ProcessQuery {
  public:
    ProcessQuery();
    std::string GetName(DWORD pid);
  private: 
    char name[260];
    DWORD pid;
    DWORD parent_pid;
};



// exported Libaries to be used. 

// Get a Process Name from PID
extern "C" __declspec(dllexport) const char* GetProcessName(DWORD pid);
//
//class ProcessQueryList {
//  public:
//    ProcessQueryList();
//    void addItem(ProcessQuery);
//  private:
//    std::vector<ProcessQuery> data;
//};
