#pragma once

#include "EventType.hpp"

extern size_t eventMapSum;
extern size_t processedEventMapEventsCount;

namespace MapHandler {

struct EventHandler
{
  virtual ~EventHandler(){};
  virtual auto Process(void* event) -> void = 0;
};

struct EventHandler0 : public EventHandler
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    eventMapSum += (int)eventVal;
    ++processedEventMapEventsCount;
  }
};

struct EventHandler1 : public EventHandler
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    eventMapSum += (int)eventVal;
    ++processedEventMapEventsCount;
  }
};

struct EventHandler2 : public EventHandler
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    eventMapSum += (int)eventVal;
    ++processedEventMapEventsCount;
  }
};

struct EventHandler3 : public EventHandler
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    eventMapSum += (int)eventVal;
    ++processedEventMapEventsCount;
  }
};

struct EventHandler4 : public EventHandler
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    eventMapSum += (int)eventVal;
    ++processedEventMapEventsCount;
  }
};

struct EventHandler5 : public EventHandler
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    eventMapSum += (int)eventVal;
    ++processedEventMapEventsCount;
  }
};

struct EventHandler6 : public EventHandler
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    eventMapSum += (int)eventVal;
    ++processedEventMapEventsCount;
  }
};

struct EventHandler7 : public EventHandler
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    eventMapSum += (int)eventVal;
    ++processedEventMapEventsCount;
  }
};

struct EventHandler8 : public EventHandler
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    eventMapSum += (int)eventVal;
    ++processedEventMapEventsCount;
  }
};

struct EventHandler9 : public EventHandler
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    eventMapSum += (int)eventVal;
    ++processedEventMapEventsCount;
  }
};

}
