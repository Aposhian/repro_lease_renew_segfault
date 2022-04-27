#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/bool.hpp>

int main(int argc, char const * argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("node");
    auto pub = node->create_publisher<std_msgs::msg::Bool>("test_topic",
        rclcpp::QoS(10)
        .liveliness(rclcpp::LivelinessPolicy::ManualByTopic)
    );
    for (size_t i = 0u; i < 10u; ++i) {
        pub->publish(std::move(std_msgs::msg::Bool()));
        rclcpp::spin_some(node);
    }
    rclcpp::shutdown();
    return 0;
}