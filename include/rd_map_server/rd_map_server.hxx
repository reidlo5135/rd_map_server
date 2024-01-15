#ifndef RD_MAP_SERVER__HXX
#define RD_MAP_SERVER__HXX

#include <chrono>
#include <iostream>
#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/executors.hpp>
#include <rcutils/logging_macros.h>
#include <nav_msgs/srv/get_map.hpp>

#include "rd_map_reader/rd_map_reader.hxx"

#define NODE_NAME "rd_map_server"

namespace rd_map_server
{
    namespace server
    {
        class MapServer : public rclcpp::Node
        {
        private:
            rclcpp::Node::SharedPtr node_;
            // rclcpp::Service<nav_msgs::srv::GetMap>::SharedPtr service_;
            // void get_map_cb(const std::shared_ptr<rmw_request_id_t> request_header, const std::shared_ptr<nav_msgs::srv::GetMap::Request> request, std::shared_ptr<nav_msgs::srv::GetMap::Response> response);
        public:
            explicit MapServer();
            virtual ~MapServer();
        };
    }
}

#endif