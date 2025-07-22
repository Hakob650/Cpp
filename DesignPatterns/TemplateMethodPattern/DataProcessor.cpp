#include <iostream>

class DataProcessor
{
public:
        void execute()
        {
            read_data();
            process_data();
            save_data();
        }

        virtual void read_data() = 0;
        virtual void process_data() = 0;
        virtual void save_data() = 0;

        virtual ~DataProcessor() = default;
};

class CSVProcessor : public DataProcessor
{
public:
        void read_data() override
        {
            std::cout << "Reading Data from CSV file..." << std::endl;
        }

        void process_data() override
        {
            std::cout << "Processing CSV data..." << std::endl;
        }

        void save_data() override
        {
            std::cout << "Saving CSV data..." << std::endl;
        }
};

class JSONProcessor : public DataProcessor
{
public:
        void read_data() override
        {
            std::cout << "Reading data from JSON file..." << std::endl;
        }

        void process_data() override
        {
            std::cout << "Processign JSON data..." << std::endl;
        }

        void save_data() override
        {
            std::cout << "Saving JSON data..." << std::endl;
        }
};

int main()
{
    DataProcessor* csv = new CSVProcessor();
    csv->execute();
    delete csv;

    DataProcessor* json = new JSONProcessor();
    json->execute();
    delete json;

    return 0;
}