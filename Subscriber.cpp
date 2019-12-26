
#include "Subscriber.hpp"


    Task::Task(bool type, const std::vector<std::shared_ptr<Figure>>& data) : type(type), data(data) {};
    bool Task::isExit() const {
        return type;
    }
    std::vector<std::shared_ptr<Figure>> Task::getData() const {
        return data;
    }



   
    void ConsoleSubscriber::print(std::shared_ptr<Task> task) const  {
        for (size_t i = 0; i<task->getData().size(); ++i) {
            task->getData()[i]->print(std::cout);
        }      
    }

    void FileSubscriber::print(std::shared_ptr<Task> task) const  {
        // auto data = task->getData();
        std::ofstream os(std::to_string(rand() % 1337) + ".txt");
        
        for (size_t i = 0; i<task->getData().size(); ++i) {
            task->getData()[i]->print(os);
        }  
    }


    void Executor::subscribe(std::shared_ptr<Subscriber>& s) {
        subscribers.push_back(s);
    }

    void Executor::notify(std::shared_ptr<Task> task) {
        for(const auto& subscriber : subscribers) {
            task->getData()[0]->print(std::cout);
            subscriber->print(task);
        }
    }
