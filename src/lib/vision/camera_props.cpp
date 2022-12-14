#include <RollingRaspberry/vision/camera_props.h>

void to_json(wpi::json& json, const CameraProps& props) {
  json = wpi::json {
    { "name",     props.name },
    { "width",    props.width },
    { "height",   props.height },
    { "fps",      props.fps },
    { "model",    props.model_name },
    { "position", props.robot_to_camera.Translation() },
    { "rotation", wpi::json {
                    { "roll", props.robot_to_camera.Rotation().X().value() },
                    { "pitch", props.robot_to_camera.Rotation().Y().value() },
                    { "yaw", props.robot_to_camera.Rotation().Z().value() }
                  }
    }
  };
}

void from_json(const wpi::json& json, CameraProps& props) {
  props.name   = json.at("name").get<std::string>();
  props.width  = json.at("width").get<std::size_t>();
  props.height = json.at("height").get<std::size_t>();
  props.fps    = json.at("fps").get<std::size_t>();
  props.model_name = json.at("model").get<std::string>();
  frc::Translation3d pos = json.at("position").get<frc::Translation3d>();

  wpi::json rot_json = json.at("rotation");

  units::radian_t roll = units::radian_t(rot_json.at("roll").get<double>());
  units::radian_t pitch = units::radian_t(rot_json.at("pitch").get<double>());
  units::radian_t yaw = units::radian_t(rot_json.at("yaw").get<double>());

  frc::Rotation3d rot(roll, pitch, yaw);

  props.robot_to_camera = frc::Transform3d(pos, rot);
}

void to_json(wpi::json& json, const USBCameraProps& props) {
  json = wpi::json {
    { "dev", props.dev },
    { "host_stream", props.host_stream },
    { "props", props.props }
  };
}

void from_json(const wpi::json& json, USBCameraProps& props) {
  props.dev = json.at("dev").get<int>();
  props.host_stream = json.at("host_stream").get<bool>();
  props.props = json.at("props").get<CameraProps>();
}

void to_json(wpi::json& json, const MJPGCameraProps& props) {
  json = wpi::json {
    { "url", props.url },
    { "props", props.props }
  };
}

void from_json(const wpi::json& json, MJPGCameraProps& props) {
  props.url = json.at("url").get<std::string>();
  props.props = json.at("props").get<CameraProps>();
}
