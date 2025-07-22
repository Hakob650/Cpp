#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <memory>

class ChatMediator;

class User : public std::enable_shared_from_this<User>
{
protected:
        std::string m_name;
        std::shared_ptr<ChatMediator> chat_mediator;
public:
        User(const std::string& name)
            : m_name(name) {}

        virtual void send_msg(const std::string& message, const std::string& reciever) = 0;
        virtual void recieve_msg(const std::string& message, const std::string& sender) = 0;

        virtual void set_mediator(std::shared_ptr<ChatMediator> mediator_)
        {
            chat_mediator = mediator_;
        }

        std::string get_name() const
        {
            return m_name;
        }

        virtual ~User() = default;
};

class ChatMediator
{
public:
        virtual void register_user(std::shared_ptr<User> user) = 0;
        virtual void send_message(const std::string& reciever, const std::string& sender, const std::string& message) = 0;
        virtual ~ChatMediator() = default;    
};

class ConcreteUser : public User
{
public:
    ConcreteUser(const std::string& name_)
        : User(name_) {}

    void send_msg(const std::string& message, const std::string& reciever) override
    {
        if (chat_mediator)
        {
            chat_mediator->send_message(get_name(), reciever, message); // Sending message through mediator
        }
    }

    void recieve_msg(const std::string& message, const std::string& sender) override
    {
        std::cout << "[" << get_name() << "'s Inbox] Message From " << sender << ": " << message << "\n"; 
    }
};


class ConcreteChatMediator : public ChatMediator, public std::enable_shared_from_this<ConcreteChatMediator>
{
private:
        std::unordered_map<std::string,std::shared_ptr<User>> users;
public:
        void register_user(std::shared_ptr<User> user) override
    {
        user->set_mediator(shared_from_this());
        users[user->get_name()] = user;
    }

        void send_message(const std::string& sender, const std::string& reciever, const std::string& message) override
        {
            auto it = users.find(reciever);
            if(it != users.end())
            {
                it->second->recieve_msg(message, sender);
            }
            else
            {
                std::cout << "[System] User " << reciever << "Not Found\n"; 
            }
        }
};

int main()
{
    std::shared_ptr<ConcreteChatMediator> chat_mediator = std::make_shared<ConcreteChatMediator>();

    std::shared_ptr<ConcreteUser> Alice = std::make_shared<ConcreteUser>("Alice");
    std::shared_ptr<ConcreteUser> Bob = std::make_shared<ConcreteUser>("Bob");
    std::shared_ptr<ConcreteUser> David = std::make_shared<ConcreteUser>("David");

    chat_mediator->register_user(Alice);
    chat_mediator->register_user(Bob);
    chat_mediator->register_user(David);

    Alice->send_msg("Hello", "Bob");
    Bob->send_msg("Hi", "Alice");
    David->send_msg("Hello", "Bob");
    Bob->send_msg("Hi", "David");

    return 0;
}
