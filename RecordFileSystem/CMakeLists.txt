include_directories(spdlog/include)

set (LIB_SOURCE RecordWriter.cpp)

add_library(rfs OBJECT ${LIB_SOURCE})