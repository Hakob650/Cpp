#include <iostream>
#include <string>
#include <memory>

class Notification
{
public:
        virtual void notify() const = 0;
        virtual ~Notification() = default;
};

class WindowsEmailNotification : public Notification
{
public:
        void notify() const override
        {
            std::cout << "Windows-Style Email Notification" << std::endl;
        }
        ~WindowsEmailNotification() = default;
};

class WindowsSMSNotification : public Notification
{
public:
        void notify() const override
        {
            std::cout << "Windows-Style SMS Notification" << std::endl;
        }
        ~WindowsSMSNotification() = default;
};

class WindowsPushNotification : public Notification
{
public:
        void notify() const override
        {
            std::cout << "Windows-Style Push Notification" << std::endl;
        }
        ~WindowsPushNotification() = default;
};

class MacOsEmailNotification : public Notification
{
public:
        void notify() const override
        {
            std::cout << "MacOs-Style Email Notification" << std::endl;
        }
        ~MacOsEmailNotification() = default;
};


class MacOsSMSNotification : public Notification
{
public:
        void notify() const override
        {
            std::cout << "MacOs-Style SMS Notification" << std::endl;
        }
        ~MacOsSMSNotification() = default;
};


class MacOsPushNotification : public Notification
{
public:
        void notify() const override
        {
            std::cout << "MacOs-Style Push Notification" << std::endl;
        }
        ~MacOsPushNotification() = default;
};


class LinuxEmailNotification : public Notification
{
public:
        void notify() const override
        {
            std::cout << "Linux-Style Email Notification" << std::endl;
        }
        ~LinuxEmailNotification() = default;
};

class LinuxSMSNotification : public Notification
{
public:
        void notify() const override
        {
            std::cout << "Linux-Style SMS Notification" << std::endl;
        }
        ~LinuxSMSNotification() = default;
};

class LinuxPushNotification : public Notification
{
public:
        void notify() const override
        {
            std::cout << "Linux-Style Push Notification" << std::endl;
        }
        ~LinuxPushNotification() = default;
};

class NotificationFactory 
{
public:
    		virtual std::unique_ptr<Notification> createEmailNotification() const = 0;
    		
            virtual std::unique_ptr<Notification> createSMSNotification() const = 0;
    		
            virtual std::unique_ptr<Notification> createPushNotification() const = 0;
    		
            virtual ~NotificationFactory() = default;
};


class WindowsNotificationFactory : public NotificationFactory
{
public:
    		std::unique_ptr<Notification> createEmailNotification() const
            {
                return std::make_unique<WindowsEmailNotification>();
            }
    		
             std::unique_ptr<Notification> createSMSNotification() const
            {
                return std::make_unique<WindowsSMSNotification>();
            }
    		
             std::unique_ptr<Notification> createPushNotification() const 
            {
                return std::make_unique<WindowsPushNotification>();
            }
    		
            ~WindowsNotificationFactory() = default;
};

class MacOsNotificationFactory : public NotificationFactory
{
public:
         std::unique_ptr<Notification> createEmailNotification() const override
            {
                return std::make_unique<MacOsEmailNotification>();
            }
    		
             std::unique_ptr<Notification> createSMSNotification() const override
            {
                return std::make_unique<MacOsSMSNotification>();
            }
    		
             std::unique_ptr<Notification> createPushNotification() const override
            {
                return std::make_unique<MacOsPushNotification>();
            }
    		
            ~MacOsNotificationFactory() = default;
};

class LinuxNotificationFactory : public NotificationFactory
{
public:
         std::unique_ptr<Notification> createEmailNotification() const override
            {
                return std::make_unique<LinuxEmailNotification>();
            }
    	
             std::unique_ptr<Notification> createSMSNotification() const override
            {
                return std::make_unique<LinuxSMSNotification>();
            }
    		
             std::unique_ptr<Notification> createPushNotification() const override
            {
                return std::make_unique<LinuxPushNotification>();
            }
    		
            ~LinuxNotificationFactory() = default;
};

int main()
{
    std::unique_ptr<NotificationFactory> factory;

    factory = std::make_unique<WindowsNotificationFactory>();
    std::cout << "--- Windows Notifications ---" << std::endl;
    factory->createEmailNotification()->notify();
    factory->createSMSNotification()->notify();
    factory->createPushNotification()->notify();

    factory = std::make_unique<MacOsNotificationFactory>();
    std::cout << "\n--- MacOS Notifications ---" << std::endl;
    factory->createEmailNotification()->notify();
    factory->createSMSNotification()->notify();
    factory->createPushNotification()->notify();

    factory = std::make_unique<LinuxNotificationFactory>();
    std::cout << "\n--- Linux Notifications ---" << std::endl;
    factory->createEmailNotification()->notify();
    factory->createSMSNotification()->notify();
    factory->createPushNotification()->notify();

    return 0;
}
