#include "JadeManager.hh"
#include "JadeRegCtrl.hh"
#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>

using namespace std::chrono_literals;

int main(int argc, char **argv){
  std::string opt_data_input = "//./xillybus_read_32";
  std::string opt_reg = "//./xillybus_mem_8";
  std::string opt_data_output = "output";
  std::string opt_time_run = "60";

  for(int i = 1; i < argc; i++){
    std::string opt(argv[i]);
    if(opt=="-i"){
      if(i+1<argc){
	i++;
	opt_data_input = argv[i];
      }
    }
    if(opt=="-o"){ 
      if(i+1<argc){
	i++;
	opt_data_output = argv[i];
      }
    }
    if(opt=="-r"){ 
      if(i+1<argc){
	i++;
	opt_reg = argv[i];
      }
    }
    if(opt=="-s"){ 
      if(i+1<argc){
	i++;
	opt_time_run = argv[i];
      }
    }
  }

  size_t time_run = std::stoul(opt_time_run);
  
  std::time_t time_now = std::time(nullptr);
  char time_buff[13];
  time_buff[12] = 0;
  std::strftime(time_buff, sizeof(time_buff),
		"%y%m%d%H%M%S", std::localtime(&time_now));
  std::string time_str(time_buff);
  std::string data_output_path = opt_data_output+"_"+time_str +".df";
  
  auto preg = new JadeRegCtrl(opt_reg);
  preg->WriteByte(4, 15);
  std::this_thread::sleep_for(100ms);
  preg->WriteByte(3, 15);
  auto pman = new JadeManager();
  pman->Start(opt_data_input, data_output_path);
  preg->WriteByte(4, 15);
  std::this_thread::sleep_for(std::chrono::milliseconds(time_run));
  pman->Stop();
  delete pman;
  return 0;
}
