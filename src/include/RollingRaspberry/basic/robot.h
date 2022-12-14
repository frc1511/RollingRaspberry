#pragma once

#include <RollingRaspberry/rolling_raspberry.h>
#include <RollingRaspberry/basic/subsystem.h>
#include <RollingRaspberry/vision/vision.h>

class Robot {
public:
  Robot();
  ~Robot();

  void robot_process();

  void auto_init();
  void auto_process();
  
  void teleop_init();
  void teleop_process();
  
  void disabled_init();
  void disabled_process();
  
  void test_init();
  void test_process();
  
private:
  Vision vision;
  
  std::vector<Subsystem*> subsystems {
    &vision
  };
  
  void reset(NTHandler::MatchMode mode);
};
