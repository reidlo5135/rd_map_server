#include "rd_map_reader/rd_map_reader.hxx"

rd_map_server::reader::MapReader::MapReader()
{
}

rd_map_server::reader::MapReader::~MapReader()
{
}

bool rd_map_server::reader::MapReader::read_pgm(const char *file_name)
{
    std::ifstream file(file_name, std::ios::binary);

    if (!file)
    {
        RCUTILS_LOG_ERROR_NAMED(NODE_NAME, "파일을 열 수 없습니다.");
        return false;
    }

    // 헤더 정보 읽기
    std::string magicNumber;
    file >> magicNumber;
    if (magicNumber != "P2" && magicNumber != "P5")
    {
        RCUTILS_LOG_ERROR_NAMED(NODE_NAME, "올바른 PGM 파일이 아닙니다.");
        file.close();
        return false;
    }

    file >> width >> height >> maxVal;

    if (width <= 0 || height <= 0 || maxVal <= 0)
    {
        RCUTILS_LOG_ERROR_NAMED(NODE_NAME, "잘못된 이미지 크기 또는 최대값입니다.");
        file.close();
        return false;
    }

    // 이미지 데이터 읽기
    pixels.resize(height, std::vector<int>(width));
    if (magicNumber == "P2")
    {
        // ASCII 형식
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                if (!(file >> pixels[i][j]))
                {
                    RCUTILS_LOG_ERROR_NAMED(NODE_NAME, "이미지 데이터를 읽는 도중 오류가 발생했습니다.");
                    file.close();
                    return false;
                }
            }
        }
    }
    else
    {
        // 이진 형식
        file.read(reinterpret_cast<char *>(pixels.data()[0].data()), width * height);
        if (!file)
        {
            RCUTILS_LOG_ERROR_NAMED(NODE_NAME, "이미지 데이터를 읽는 도중 오류가 발생했습니다.");
            file.close();
            return false;
        }
    }

    file.close();
    return true;
}