#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "gps_communication/msg/GPSData.hpp" // Include custom message type

class GPSSubscriber : public rclcpp::Node
{
    public:
        GPSSubscriber() : Node("gps_subscriber")
        {
            subscription_ = this->create_subscription<gps_communication::msg::GPSData>(
            "gps_topic", 10, std::bind(&GPSSubscriber::gps_callback, this, std::placeholders::_1));
        }
    private:
        void gps_callback(const gps_communication::msg::GPSData::SharedPtr msg)
        {
            RCLCPP_INFO(this->get_logger(), "Received GPS data: Latitude %.6f, Longitude %.6f, Altitude %.2f",
                    msg->latitude, msg->longitude, msg->altitude);
        }
        rclcpp::Subscription<gps_communication::msg::GPSData>::SharedPtr subscription_;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GPSSubscriber>());
    rclcpp::shutdown();
    return 0;
}
