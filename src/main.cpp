/*
 * Process Analyzer Program
 *
 *   - This Program is the main runner of the Process Analyzer, It takes a PID as the ARGV[1] and 
 *     returns information about the process. 
 *
 *
 */

#include "ProcessQuery/ProcessQuery.h"

int main(int ARGC, char *ARGV[]) {

  setDebug(false);
  if(ARGC <= 1){
    std::cerr << "Usage ./main.cpp [PROCESS ID] [DEBUG FLAG]" << std::endl;
  }
  if(ARGC == 3){
    setDebug(true);
  }

  if (debug){
    std::cout << "Process ID: " << ARGV[1] << std::endl;
    std::cout << "Debug: " << debug << std::endl;
  }

  // Start of actual Logic
  DWORD pid = std::stoul(ARGV[1]);
  std::vector<ProcessInfo> global_Processes = GetAllProcessSnapShot();

  if (global_Processes.size() > 0) {
      std::string myProcessName = GetProcessName(global_Processes[2].pid);
  }
  return 0;
}
