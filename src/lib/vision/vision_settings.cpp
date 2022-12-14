#include <RollingRaspberry/vision/vision_settings.h>

void to_json(wpi::json& json, const VisionSettings& settings) {
  json = wpi::json{
    {"apriltag_family", settings.tag_family},
    {"apriltag_size", settings.tag_size.value()},
    {"field_layout", settings.field_layout_name},
    {"min_decision_margin", settings.min_decision_margin},
    {"pose_estimate_iterations", settings.estimate_iters},
    {"max_frame_delay", settings.max_frame_delay},
    {"max_robot_elevation", settings.max_robot_elevation.value()},
    {"robot_pose_tolerance", settings.robot_pose_tolerance.value()},
    {"usb_cameras", settings.usb_camera_props},
    {"mjpg_cameras", settings.mjpg_camera_props},
  };
}

void from_json(const wpi::json& json, VisionSettings& settings) {
  settings.tag_family = json.at("apriltag_family").get<std::string>();
  settings.tag_size = units::meter_t(json.at("apriltag_size").get<double>());
  settings.field_layout_name = json.at("field_layout").get<std::string>();
  settings.min_decision_margin = json.at("min_decision_margin").get<double>();
  settings.estimate_iters = json.at("pose_estimate_iterations").get<int>();
  settings.max_frame_delay = json.at("max_frame_delay").get<double>();
  settings.max_robot_elevation = units::meter_t(json.at("max_robot_elevation").get<double>());
  settings.robot_pose_tolerance = units::meter_t(json.at("robot_pose_tolerance").get<double>());
  settings.usb_camera_props = json.at("usb_cameras").get<std::vector<USBCameraProps>>();
  settings.mjpg_camera_props = json.at("mjpg_cameras").get<std::vector<MJPGCameraProps>>();
}
