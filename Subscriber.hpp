#pragma once

#include <fstream>
#include <memory>
#include <vector>
#include <queue>
#include <map>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "Figure.hpp"


class Task {
public:
    Task(bool type, const std::vector<std::shared_ptr<Figure>>& data);
    bool isExit() const;
    std::vector<std::shared_ptr<Figure>> getData() const;
private:
    bool type;
    std::vector<std::shared_ptr<Figure>> data;
};

struct Subscriber {
public:    
    virtual void print(std::shared_ptr<Task> task) const = 0;
    virtual ~Subscriber() = default;
};

struct ConsoleSubscriber : public Subscriber {
public:    
    void print(std::shared_ptr<Task> task) const override;
};

struct FileSubscriber : public Subscriber {
public:
    void print(std::shared_ptr<Task> task) const override;
};


class Executor {
public:
    void subscribe(std::shared_ptr<Subscriber>& s);

    void notify(std::shared_ptr<Task> task);
private:
    std::vector<std::shared_ptr<Subscriber>> subscribers;
};
