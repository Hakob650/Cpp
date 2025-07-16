#include <iostream>
#include <string>

class Logger
{
private:
        Logger()
        {
            std::cout << "[LOG]: Application is running" << std::endl;
        }

        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;

        static Logger* instance;
public:
        static Logger* get_instance()
        {
            if(!instance)
            {
                return new Logger();
            }
            return instance;
        }

        static void log(const std::string& message)
        {
                std::cout << message << std::endl;
        }

        ~Logger()
        {
            std::cout << "[LOG]: Application Exited" << std::endl;
        }
};

Logger* Logger::instance = nullptr;

int main()
{
    Logger* logger = Logger::get_instance();

    logger->log("[LOG]: Performing Some Operation");

    delete logger;
    
    return 0;
}
