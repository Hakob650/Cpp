#include <iostream>
#include <string>
#include <memory>

class Notification
{
public: 
        virtual void notify() const = 0;
        virtual ~Notification() = default;
};

class EmailNotification : public Notification
{
public:
        void notify() const override
        {
            std::cout << "Sending an Email" << std::endl;
        }
        ~EmailNotification() = default;
};

class SMSNotification : public Notification
{
public:
        void notify() const override
        {
            std::cout << "Sending an SMS" << std::endl;
        }
        ~SMSNotification() = default;
};

class PushNotification : public Notification
{
public:
        void notify() const override
        {
            std::cout << "Sending a Push Notification" << std::endl;
        }
        ~PushNotification() = default;
};

class NotificationFactory
{
public:
        static std::unique_ptr<Notification> create_notification(const std::string& type)
        {
            if(type == "Email")
            {
                std::make_unique<EmailNotification>();
            }
            else if(type == "SMS")
            {
                std::make_unique<SMSNotification>();
            }
            else if(type == "Push")
            {
                std::make_unique<PushNotification>();
            }
            else
            {
                std::cout << "Unknown Notification Type" << std::endl;
            }
            return nullptr;
        }
};

int main()
{
    EmailNotification email;
    
    email.notify();

    SMSNotification SMS;
    SMS.notify();

    PushNotification push;
    push.notify();

    return 0;
}