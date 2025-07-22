#include <iostream>
#include <vector>
#include <memory>

class SortStrategy
{
public:
        virtual void sort(std::vector<int>& vec) = 0;
        virtual ~SortStrategy() = default;
};

class BubbleSort : public SortStrategy
{
public:
        void sort(std::vector<int>& vec) override
        {
            std::cout << "Sorting by Bubble Sort" << std::endl;
            for(size_t i = 0; i < vec.size(); ++i)
            {
                for(size_t j = 0; j < vec.size() - i - 1; ++j)
                {
                    if(vec[j] > vec[j + 1])
                    {
                        int temp = vec[j];
                        vec[j] = vec[j + 1];
                        vec[j + 1] = temp;
                    }
                }
            }
        }
};

class SelectionSort : public SortStrategy
{
public:
        void sort(std::vector<int>& vec) override
        {
            std::cout << "Sorting By Selection Sort" << std::endl;
            for(size_t i = 0; i < vec.size() - 1; ++i)
            {
                int min_index = i;

                for(int j = i + 1; j < vec.size(); ++j)
                {
                    if(vec[j] < vec[min_index])
                    {
                        min_index = j;
                    }
                }
                int temp = vec[i];
                vec[i] = vec[min_index];
                vec[min_index] = temp;
            }
        }
};

class InsertionSort : public SortStrategy
{
public:
        void sort(std::vector<int>& vec) override
        {
            std::cout << "Sorting By Insertion Sort" << std::endl;
            for(size_t i = 1; i < vec.size(); ++i)
            {
                int key = vec[i];
                int j = i - 1;

                while(j >= 0 && vec[j] > key)
                {
                    vec[j + 1] = vec[j];
                    j = j - 1;
                }

                vec[j + 1] = key;
            }
        }
};

class Sorter 
{
private:
        std::unique_ptr<SortStrategy> strategy;
public:
        void set_strategy(SortStrategy* strategy_)
        {
            strategy.reset(strategy_);
        } 

        void sort(std::vector<int>& vec)
        {
            if(strategy)
            {
                strategy->sort(vec);
            }
            else
            {
                std::cerr << "No Sorting strategy set" << std::endl;
            }
        }
};

void print_vector(const std::vector<int>& vec)
{
    for(size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Sorter sorter;

    std::vector<int> data = {5,2,9,1,5,6};

    std::vector<int> data1 = data;
    sorter.set_strategy(new BubbleSort());
    sorter.sort(data1);
    print_vector(data1);

    std::vector<int> data2 = data;
    sorter.set_strategy(new InsertionSort());
    sorter.sort(data2);
    print_vector(data2);

    std::vector<int> data3 = data;
    sorter.set_strategy(new SelectionSort());
    sorter.sort(data3);
    print_vector(data3);

    return 0;
}
