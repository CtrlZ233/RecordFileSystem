#pragma once

#include <stdlib.h>
#include <string.h>
#define RAF_MAGIC_NUMBER 0xABCDEF12345
#define RAF_MAX_RECORD_PER_CHUNK 4095
#define BYTES_PER_BLOCK 4096
#define META_DATA_SIZE BYTES_PER_BLOCK * 16

namespace record_file_system {
    

#pragma pack(1)
    struct RecordDescEntry {
        int64_t offset;
        int32_t len;
        int32_t checksum;
    };

    struct FileMetaData {
        int64_t magicNumber;
        int64_t nextFileMetaDataOffset;
        RecordDescEntry descEntries[RAF_MAX_RECORD_PER_CHUNK];

        void init() {
            magicNumber             = RAF_MAGIC_NUMBER;
            nextFileMetaDataOffset  = 0;
            memset(descEntries, 0, sizeof(RecordDescEntry) * RAF_MAX_RECORD_PER_CHUNK);
        }
    };

#pragma pack()
}