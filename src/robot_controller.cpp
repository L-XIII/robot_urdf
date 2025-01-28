#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>

// Callback to handle position updates
void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
    double x = msg->pose.pose.position.x;
    double y = msg->pose.pose.position.y;
    RCLCPP_INFO(rclcpp::get_logger("circular_motion_node"),
                "Robot Position - x: %.2f, y: %.2f", x, y);
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    // Create the node
    auto node = rclcpp::Node::make_shared("circular_motion_node");

    // Create a publisher for velocity commands
    auto velocity_publisher = node->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);

    // Create a subscriber for position updates
    auto odom_subscriber = node->create_subscription<nav_msgs::msg::Odometry>(
        "/odom", 10, odom_callback);

    rclcpp::Rate loop_rate(10); // Set loop frequency to 10 Hz

    while (rclcpp::ok())
    {
        // Publish circular motion commands
        auto msg = geometry_msgs::msg::Twist();
        msg.linear.x = 0.5;   // Forward velocity
        msg.angular.z = 0.5; // Angular velocity for circular motion
        velocity_publisher->publish(msg);

        // Process incoming messages (e.g., odometry updates)
        rclcpp::spin_some(node);

        // Sleep for the rest of the loop
        loop_rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}

