#pragma once

#include <string>
#include <vector>

#include "FileMetaData.hpp"

namespace record_file_system {
    class RecordWriter {
    public:
        explicit RecordWriter(const std::string &filename);

        int append(const std::string &record);

        std::vector<int> appendBatch(const std::vector<std::string> &records);

    private:
        std::string filename_;
        int64_t curIdx_;
        int64_t fileOffset_;
        FileMetaData *metaData_;

    };

}