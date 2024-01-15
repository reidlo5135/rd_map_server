#include "rd_map_server/rd_map_server.hxx"

int main(int argc, const char *const *argv)
{
    rclcpp::init(argc, argv);
    rclcpp::Node::SharedPtr node = std::make_shared<rd_map_server::server::MapServer>();
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();
}