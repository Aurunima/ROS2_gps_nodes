#include <chrono>
#include <functional>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "gps_communication/msg/GPSData.hpp" // Include custom message type

using namespace std::chrono_literals;

class GPSPublisher : public rclcpp::Node
{
    public:
        GPSPublisher() : Node("gps_publisher"), count_(0)
        {
            publisher_ = this->create_publisher<gps_communication::msg::GPSData>("gps_topic", 10);
            timer_ = this->create_wall_timer(100ms, std::bind(&GPSPublisher::timer_callback, this));
        }
    private:
        void timer_callback()
        {
            auto message = gps_communication::msg::GPSData();
            message.latitude = 37.7749; // Latitude value
            message.longitude = -122.4194; // Longitude value
            message.altitude = 100.0; // Altitude value
            publisher_->publish(message);
        }
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<gps_communication::msg::GPSData>::SharedPtr publisher_;
        size_t count_;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GPSPublisher>());
    rclcpp::shutdown();
    return 0;
}
