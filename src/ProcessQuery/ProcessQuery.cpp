#include "ProcessQuery.h"
#include <corecrt_memcpy_s.h>
#include <cstdlib>

//helper function to define if using debug mode or not
void setDebug(bool val){
  debug = val;
}

/*
 * param: DWORD pid --> Process ID to query
 *
 * output: Process Name
 */
extern "C" __declspec(dllexport) const char* GetProcessName(DWORD pid){
 
  return "Hello from C++";
  //const char* ret; 
  //ProcessQuery* pq = new ProcessQuery();
  //std::string name = pq->GetName(pid);
  //ret = std::string(name).c_str();
  //return ret;

}

  /*
   * GetAllProcessSnapShot(): Takes a snap shot of all running processes on the windows machine. 
   * 
   * output: 
   *   - A vector containing all process names and their coresponding PID
   */
//std::vector<ProcessInfo> GetAllProcessSnapShot() {
//
//  if (debug) {
//    std::cout << "GetAllProcessSnapShot()" << std::endl;
//  }
//
//  HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
//  std::vector<ProcessInfo> local_list;
//
//  if (hProcessSnap == INVALID_HANDLE_VALUE) {
//    std::cerr << "Failed to Run CreateToolhelp32Snapshot. " << std::endl;
//    return local_list;
//  }
//
//  PROCESSENTRY32 pe32;
//  pe32.dwSize = sizeof(PROCESSENTRY32);
//
//  if (!Process32First(hProcessSnap, &pe32)) {
//    std::cerr << "Process32First Failed to run." << std::endl;
//    CloseHandle(hProcessSnap);
//    return local_list;
//  }
//
//  do {
//    ProcessInfo info;
//    memcpy_s(info.name, 260, pe32.szExeFile, 260);
//    info.pid = pe32.th32ProcessID;
//    info.parent_pid =  pe32.th32ParentProcessID;
//    local_list.push_back(info);
//  } while (Process32Next(hProcessSnap, &pe32));
//
//
//  if (debug) {
//    for (int i = 0; i < local_list.size(); i++) {
//      std::wcout << "Process Name: " << local_list.at(i).name << std::endl;
//      std::cout << "\tProcess ID: " << local_list.at(i).pid << std::endl;
//    }
//  }
//
//  CloseHandle(hProcessSnap);
//  return local_list;
//}


/*
 * Default Constructor
 *
 */
ProcessQuery::ProcessQuery(){
  memcpy_s(this->name, 260  , "Default", 7);
}
/*
 *
 *
 */
std::string ProcessQuery::GetName(DWORD pid){
  if(debug){
    std::cout << "GetProcessName::Starting -  " << pid << std::endl; 
  }
  TCHAR processName[MAX_PATH] = TEXT("<unknown>"); 
  HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, false, pid);

  if(hProcess != NULL){
    HMODULE hMod;
    DWORD cbNeeded;

    if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded)) {
      GetModuleBaseName(hProcess, hMod, processName, MAX_PATH);
    }
  }

  CloseHandle(hProcess);

  if(debug){
    std::cout << "GetProcessName::End result: " << std::string(processName) << std::endl;
  }

  return std::string(processName);
}
