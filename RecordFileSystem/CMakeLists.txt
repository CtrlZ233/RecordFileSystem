include_directories(spdlog/include)

set (LIB_SOURCE DiskKVStoreClient.cpp)

add_library(rfs OBJECT ${LIB_SOURCE})