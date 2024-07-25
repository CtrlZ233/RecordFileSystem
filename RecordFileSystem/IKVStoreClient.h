#pragma once

#include <string>

namespace market_data_loader {
    class IKVStoreClient {
    public:
        virtual void get(const std::string &key, std::string &value) = 0;

        enum class Option {
            None,
            Gzip,
            LZO,
            Snappy
        };

        virtual void put(const std::string &key, std::string &value, Option option) = 0;
    };
}