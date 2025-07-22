#include <iostream>
#include <vector>
#include <algorithm>

class Observer;
 
class WeatherStation
{
public:
        virtual void add_observer(Observer* observer) = 0;

        virtual void remove_observer(Observer* observer) = 0;

        virtual void notify_observers() = 0;

        virtual ~WeatherStation() = default;
};

class Observer
{
public:
        virtual void update(float temperature) = 0;
        
        virtual ~Observer() = default;
};

class ConcreteWeatherStation : public WeatherStation
{
private:
        std::vector<Observer*> observers;
        float temperature;
public:
        void add_observer(Observer* observer) override
        {
            observers.push_back(observer);
        }

        void remove_observer(Observer* observer) override
        {
            observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
        }

        void notify_observers() override
        {
            for(size_t i = 0; i < observers.size(); ++i)
            {
                observers[i]->update(temperature);
            }
        }

        void set_temperature(float new_temperature)
        {
            if(temperature != new_temperature)
            {
                temperature = new_temperature;
                
                notify_observers();
            }
        }

        float get_temperature() const { return temperature; }
};

class PhoneDisplay : public Observer
{
public:
        void update(float temperature) override
        {
            std::cout << "[PhoneDisplay] New Temperature: " << temperature << "°C" <<std::endl;
        }
};

class LEDDisplay : public Observer
{
public:
        void update(float temperature) override
        {
            std::cout << "[LEDDisplay] New Temperature: " << temperature <<"°C" << std::endl; 
        }
};

int main() {
    ConcreteWeatherStation station;

    PhoneDisplay phone;
    LEDDisplay led;

    // Add observers
    station.add_observer(&phone);
    station.add_observer(&led);

    std::cout << "Setting temperature to 22.5°C\n";
    station.set_temperature(22.5f); 

    std::cout << "\nRemoving LEDDisplay...\n";
    station.remove_observer(&led);

    std::cout << "Setting temperature to 25.0°C\n";
    station.set_temperature(25.0f);  

    return 0;
}
