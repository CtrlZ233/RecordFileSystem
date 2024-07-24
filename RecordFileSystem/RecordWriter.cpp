#include "RecordWriter.hpp"

#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

#include "spdlog/spdlog.h"

namespace record_file_system {
    RecordWriter::RecordWriter(const std::string &filename) : filename_(filename) {
        struct stat fileStat;
        int fd;
        if (stat(filename.c_str(), &fileStat) == -1) {
            spdlog::info("file <{}> not found, start to create it", filename);
            fd = open(filename.c_str(), O_CREAT | O_WRONLY, 0666);
            if (fd == -1) {
                spdlog::error("Error creating file");
                exit(EXIT_FAILURE);
            }

            spdlog::info("start expand file for init: {}", fileStat.st_size);
            if (ftruncate(fd, fileStat.st_size + META_DATA_SIZE) == -1) {
                spdlog::error("Fail to expand file for init");
                exit(EXIT_FAILURE);
            }
            metaData_ = reinterpret_cast<FileMetaData *>(mmap(0, META_DATA_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0));
            metaData_->init();
            curIdx_ = 0;
            fileOffset_ = META_DATA_SIZE;
        } else {
            if (fileStat.st_size <= META_DATA_SIZE) {
                spdlog::info("This file <{}> is not a record file.", filename);
                exit(EXIT_FAILURE);
            }
            fd = open(filename.c_str(), O_WRONLY, 0666);
            if (fd == -1) {
                spdlog::error("file <{}> open failed", filename);
                exit(EXIT_FAILURE);
            }

            metaData_ = reinterpret_cast<FileMetaData *>(mmap(0, META_DATA_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0));
            if (metaData_->magicNumber != RAF_MAGIC_NUMBER) {
                spdlog::error("invalid metaData");
                exit(EXIT_FAILURE);
            }
            int64_t offset = metaData_->nextFileMetaDataOffset;
            int64_t index = 0;
            while (offset != 0) {
                index += RAF_MAX_RECORD_PER_CHUNK;
                if (munmap(metaData_, META_DATA_SIZE) == -1) {
                    spdlog::error("fail to stride metadata");
                    exit(EXIT_FAILURE);
                }
                if (offset % BYTES_PER_BLOCK) {
                    spdlog::error("invaild offset: {}", offset);
                    exit(EXIT_FAILURE);
                }
                metaData_ = reinterpret_cast<FileMetaData *>(mmap(0, META_DATA_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, offset));
                if (metaData_->magicNumber != RAF_MAGIC_NUMBER) {
                    spdlog::error("invalid metaData");
                    exit(EXIT_FAILURE);
                }
                offset = metaData_->nextFileMetaDataOffset;
            }
            
        }
    }

}