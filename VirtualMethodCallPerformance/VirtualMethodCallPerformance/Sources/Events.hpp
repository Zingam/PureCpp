#pragma once

#include "EventType.hpp"

extern size_t eventsSum;
extern size_t processedEventsCount;

struct Event0
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    eventsSum += (int)eventVal;
    ++processedEventsCount;
  }
};

struct Event1
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    eventsSum += (int)eventVal;
    ++processedEventsCount;
  }
};

struct Event2
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    eventsSum += (int)eventVal;
    ++processedEventsCount;
  }
};

struct Event3
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    eventsSum += (int)eventVal;
    ++processedEventsCount;
  }
};

struct Event4
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    eventsSum += (int)eventVal;
    ++processedEventsCount;
  }
};

struct Event5
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    eventsSum += (int)eventVal;
    ++processedEventsCount;
  }
};

struct Event6
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    eventsSum += (int)eventVal;
    ++processedEventsCount;
  }
};

struct Event7
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    eventsSum += (int)eventVal;
    ++processedEventsCount;
  }
};

struct Event8
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    eventsSum += (int)eventVal;
    ++processedEventsCount;
  }
};

struct Event9
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    eventsSum += (int)eventVal;
    ++processedEventsCount;
  }
};
