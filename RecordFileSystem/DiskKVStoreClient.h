#pragma once

#include "IKVStoreClient.h"

namespace market_data_loader {
    class DiskKVStoreClient : public IKVStoreClient {
    public:
        DiskKVStoreClient();

        void get(const std::string &key, std::string &value) override;

        void put(const std::string &key, std::string &value, Option option) override;
    };
}