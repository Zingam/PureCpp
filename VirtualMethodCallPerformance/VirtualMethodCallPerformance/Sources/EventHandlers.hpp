#pragma once

#include "EventType.hpp"

extern size_t eventHandlersSum;
extern size_t processedEventHandlersCount;

struct EventHandler
{
  virtual ~EventHandler(){};
  virtual auto Process(void* event) -> bool = 0;
};

struct EventHandler0 : public EventHandler
{
  auto Process(void* event) -> bool
  {
    auto eventVal = *(EventType*)event;
    if (*(EventType*)event == EventType::EventType0) {
      eventHandlersSum += (int)eventVal;
      ++processedEventHandlersCount;
      return true;
    } else {
      return false;
    }
  }
};

struct EventHandler1 : public EventHandler
{
  auto Process(void* event) -> bool
  {
    auto eventVal = *(EventType*)event;
    if (*(EventType*)event == EventType::EventType1) {
      eventHandlersSum += (int)eventVal;
      ++processedEventHandlersCount;
      return true;
    } else {
      return false;
    }
  }
};

struct EventHandler2 : public EventHandler
{
  auto Process(void* event) -> bool
  {
    auto eventVal = *(EventType*)event;
    if (eventVal == EventType::EventType2) {
      eventHandlersSum += (int)eventVal;
      ++processedEventHandlersCount;
      return true;
    } else {
      return false;
    }
  }
};

struct EventHandler3 : public EventHandler
{
  auto Process(void* event) -> bool
  {
    auto eventVal = *(EventType*)event;
    if (*(EventType*)event == EventType::EventType3) {
      eventHandlersSum += (int)eventVal;
      ++processedEventHandlersCount;
      return true;
    } else {
      return false;
    }
  }
};

struct EventHandler4 : public EventHandler
{
  auto Process(void* event) -> bool
  {
    auto eventVal = *(EventType*)event;
    if (*(EventType*)event == EventType::EventType4) {
      eventHandlersSum += (int)eventVal;
      ++processedEventHandlersCount;
      return true;
    } else {
      return false;
    }
  }
};

struct EventHandler5 : public EventHandler
{
  auto Process(void* event) -> bool
  {
    auto eventVal = *(EventType*)event;
    if (*(EventType*)event == EventType::EventType5) {
      eventHandlersSum += (int)eventVal;
      ++processedEventHandlersCount;
      return true;
    } else {
      return false;
    }
  }
};

struct EventHandler6 : public EventHandler
{
  auto Process(void* event) -> bool
  {
    auto eventVal = *(EventType*)event;
    if (*(EventType*)event == EventType::EventType6) {
      eventHandlersSum += (int)eventVal;
      ++processedEventHandlersCount;
      return true;
    } else {
      return false;
    }
  }
};

struct EventHandler7 : public EventHandler
{
  auto Process(void* event) -> bool
  {
    auto eventVal = *(EventType*)event;
    if (*(EventType*)event == EventType::EventType7) {
      eventHandlersSum += (int)eventVal;
      ++processedEventHandlersCount;
      return true;
    } else {
      return false;
    }
  }
};

struct EventHandler8 : public EventHandler
{
  auto Process(void* event) -> bool
  {
    auto eventVal = *(EventType*)event;
    if (*(EventType*)event == EventType::EventType8) {
      eventHandlersSum += (int)eventVal;
      ++processedEventHandlersCount;
      return true;
    } else {
      return false;
    }
  }
};

struct EventHandler9 : public EventHandler
{
  auto Process(void* event) -> bool
  {
    auto eventVal = *(EventType*)event;
    if (*(EventType*)event == EventType::EventType9) {
      eventHandlersSum += (int)eventVal;
      ++processedEventHandlersCount;
      return true;
    } else {
      return false;
    }
  }
};
