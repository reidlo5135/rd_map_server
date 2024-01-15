#ifndef RD_MAP_READER__HXX
#define RD_MAP_READER__HXX

#include <fstream>
#include <vector>
#include <rcutils/logging_macros.h>

#define NODE_NAME "rd_map_server"

namespace rd_map_server
{
    namespace reader
    {
        class MapReader
        {
        public:
            explicit MapReader();
            virtual ~MapReader();
            int width, height, maxVal;
            std::vector<std::vector<int>> pixels;
            bool read_pgm(const char *file_name);
        };
    }
}

#endif