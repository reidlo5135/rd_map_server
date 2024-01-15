#include "rd_map_server/rd_map_server.hxx"

rd_map_server::server::MapServer::MapServer()
    : Node(NODE_NAME)
{
    this->node_ = std::shared_ptr<rclcpp::Node>(this, [](rclcpp::Node *) {});

    if (this->node_ != nullptr)
    {
        RCLCPP_INFO(this->node_->get_logger(), "[%s] node has been created", NODE_NAME);
    }
    else
    {
        RCUTILS_LOG_ERROR_NAMED(NODE_NAME, "failed to create %s node", NODE_NAME);
        exit(0);
    }

    std::shared_ptr<rd_map_server::reader::MapReader> map_reader = std::make_shared<rd_map_server::reader::MapReader>();

    if (map_reader->read_pgm("/home/reidlo/ros2_ws/src/rd_map_server/map.pgm"))
    {
        RCUTILS_LOG_INFO_NAMED(NODE_NAME, "map width : [%d], height : [%d]", map_reader->width, map_reader->height);

        for (int i = 0; i < map_reader->height; ++i)
        {
            for (int j = 0; j < map_reader->width; ++j)
            {
                RCUTILS_LOG_INFO_NAMED(NODE_NAME, "pixels : [%f]", map_reader->pixels[i][j]);
            }
        }
    }
}

rd_map_server::server::MapServer::~MapServer()
{
}
