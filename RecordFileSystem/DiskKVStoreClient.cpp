#include "DiskKVStoreClient.h"
#include <parquet/properties.h>
#include <arrow/api.h>
#include <parquet/api/writer.h>
#include "parquet/metadata.h"
#include "arrow/io/api.h"
#include "parquet/schema.h"
#include "parquet/com"
namespace market_data_loader {
    DiskKVStoreClient::DiskKVStoreClient() {
        
    }

    void DiskKVStoreClient::get(const std::string &key, std::string &value) {

    }

    void DiskKVStoreClient::put(const std::string &key, std::string &value, Option option) {
         // 创建一个 FileOutputStream 对象
        std::shared_ptr<arrow::io::FileOutputStream> file_output_stream;

        PARQUET_ASSIGN_OR_THROW(file_output_stream, arrow::io::FileOutputStream::Open("example.parquet"));

        // 创建一个 Schema 对象
        // auto schema = arrow::schema({arrow::field("column1", arrow::int32())});
        std::shared_ptr<parquet::schema::GroupNode> schema;
        parquet::schema::NodeVector fields;
        fields.push_back(parquet::schema::PrimitiveNode::Make("column1", parquet::Repetition::REQUIRED, parquet::Type::INT32));
        schema = std::shared_ptr<parquet::schema::GroupNode>(dynamic_cast<parquet::schema::GroupNode *>(parquet::schema::GroupNode::Make("schema", parquet::Repetition::REQUIRED, fields).get()));

        // 配置写入器的参数
        parquet::WriterProperties::Builder props_builder;
        props_builder.compression(parquet::Compression::SNAPPY);
        auto props = props_builder.build();

        // 创建一个 ParquetFileWriter 对象
        std::unique_ptr<parquet::ParquetFileWriter> writer = parquet::ParquetFileWriter::Open(file_output_stream, schema, props);

        // 写入数据到行组中
        int64_t num_rows = 100;
        auto array = arrow::MakeRandomInt32Array(num_rows, 0, 100);
        auto table = arrow::Table::Make(arrow::schema({arrow::field("column1", arrow::int32())}), {array});
        PARQUET_ASSIGN_OR_THROW(auto chunk, row_group_writer->WriteTable(*table));


        // 创建一个 RowGroupWriter 对象
        auto  row_group_writer = writer->AppendRowGroup();
        row_group_writer-
        PARQUET_ASSIGN_OR_THROW(row_group_writer, writer->AppendRowGroup());
    }
}