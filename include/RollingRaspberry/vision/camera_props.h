#pragma once

#include <RollingRaspberry/rolling_raspberry.h>
#include <frc/geometry/Pose3d.h>

struct CameraProps {
  // The identifier string of the camera.
  std::string name = "the_camera";
  
  // The pixel dimensions of the camera.
  std::size_t width = 320,
              height = 240;
  
  // The fps of the camera.
  std::size_t fps = 30;
  
  // Field of view of the camera.
  units::degree_t fov = 68.5_deg;
  
  frc::Pose3d pose;
};

void to_json(wpi::json& json, const CameraProps& props);
void from_json(const wpi::json& json, CameraProps& props);

struct USBCameraProps {
  std::size_t dev;
  bool host_stream = true;
  CameraProps props;
};

void to_json(wpi::json& json, const USBCameraProps& props);
void from_json(const wpi::json& json, USBCameraProps& props);

struct MJPGCameraProps {
  std::string url;
  CameraProps props;
};

void to_json(wpi::json& json, const MJPGCameraProps& props);
void from_json(const wpi::json& json, MJPGCameraProps& props);