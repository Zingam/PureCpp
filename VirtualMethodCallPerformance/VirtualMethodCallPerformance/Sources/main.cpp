#include "EventHandlers.hpp"
#include "EventType.hpp"
#include "Events.hpp"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

int
main(int argc, char* argv[])
{
  //////////////////////////////////////////////////////////////////////////////
  // Constants
  //////////////////////////////////////////////////////////////////////////////

  size_t repeats = 1;
  repeats = 2;
  repeats = 1'000;
  repeats = 10'000'000;

  //////////////////////////////////////////////////////////////////////////////

  std::vector<EventType> events{
    EventType::EventType1, EventType::EventType2, EventType::EventType2,
    EventType::EventType3, EventType::EventType1, EventType::EventType1,
    EventType::EventType2, EventType::EventType2, EventType::EventType3,
    EventType::EventType1, EventType::EventType1, EventType::EventType2,
    EventType::EventType2, EventType::EventType3, EventType::EventType1,
    EventType::EventType1, EventType::EventType2, EventType::EventType2,
    EventType::EventType3, EventType::EventType1, EventType::EventType1,
    EventType::EventType2, EventType::EventType2, EventType::EventType3,
    EventType::EventType1, EventType::EventType1, EventType::EventType2,
    EventType::EventType2, EventType::EventType3, EventType::EventType1,
    EventType::EventType1, EventType::EventType2, EventType::EventType2,
    EventType::EventType3, EventType::EventType1, EventType::EventType1,
    EventType::EventType2, EventType::EventType2, EventType::EventType3,
    EventType::EventType1, EventType::EventType1, EventType::EventType2,
    EventType::EventType2, EventType::EventType3, EventType::EventType1,
    EventType::EventType1, EventType::EventType2, EventType::EventType2,
    EventType::EventType3, EventType::EventType1, EventType::EventType1,
    EventType::EventType2, EventType::EventType2, EventType::EventType3,
    EventType::EventType1, EventType::EventType1, EventType::EventType2,
    EventType::EventType2, EventType::EventType3, EventType::EventType1,
    EventType::EventType1, EventType::EventType2, EventType::EventType2,
    EventType::EventType3, EventType::EventType1, EventType::EventType1,
    EventType::EventType2, EventType::EventType2, EventType::EventType3,
    EventType::EventType1, EventType::EventType1, EventType::EventType2,
    EventType::EventType2, EventType::EventType3, EventType::EventType1,
    EventType::EventType1, EventType::EventType2, EventType::EventType2,
    EventType::EventType3, EventType::EventType1, EventType::EventType1,
    EventType::EventType1, EventType::EventType2, EventType::EventType3,
  };

  //////////////////////////////////////////////////////////////////////////////
  // EventHandlers
  //////////////////////////////////////////////////////////////////////////////

  std::vector<std::unique_ptr<EventHandler>> eventHandlers;
  eventHandlers.emplace_back(new EventHandler0());
  eventHandlers.emplace_back(new EventHandler1());
  eventHandlers.emplace_back(new EventHandler2());
  eventHandlers.emplace_back(new EventHandler3());
  eventHandlers.emplace_back(new EventHandler4());
  eventHandlers.emplace_back(new EventHandler5());
  eventHandlers.emplace_back(new EventHandler6());
  eventHandlers.emplace_back(new EventHandler7());
  eventHandlers.emplace_back(new EventHandler8());
  eventHandlers.emplace_back(new EventHandler9());

  auto time_EventHandlers_steady_clock_Start = std::chrono::steady_clock::now();
  auto time_EventHandlers_high_resolution_clock_Start =
    std::chrono::high_resolution_clock::now();

  for (size_t a = 0; a < repeats; ++a) {
    size_t i = 0;
    while (i < events.size() && 0 < events.size()) {
      for (auto& eh : eventHandlers) {
        auto r = eh->Process(&events[i]);
        if (r == true) {
          break;
        }
      }
      ++i;
    }
  }
  auto time_EventHandlers_steady_clock =
    std::chrono::steady_clock::now() - time_EventHandlers_steady_clock_Start;
  auto time_EventHandlers_high_resolution_clock =
    std::chrono::high_resolution_clock::now() -
    time_EventHandlers_high_resolution_clock_Start;

  // Reset counters
  std::cout << "EventHandlers sum:    " << eventHandlersSum << "\n";
  eventHandlersSum = 0;
  auto proccessedEventHandlers = processedEventHandlersCount;
  processedEventHandlersCount = 0;

  //////////////////////////////////////////////////////////////////////////////
  // Events
  //////////////////////////////////////////////////////////////////////////////

  Event0 eh0;
  Event1 eh1;
  Event2 eh2;
  Event3 eh3;
  Event4 eh4;
  Event1 eh5;
  Event1 eh6;
  Event1 eh7;
  Event1 eh8;
  Event1 eh9;

  auto time_Events_if_else_steady_clock_Start =
    std::chrono::steady_clock::now();
  auto time_Events_if_else_high_resolution_clock_Start =
    std::chrono::high_resolution_clock::now();

  for (size_t a = 0; a < repeats; ++a) {
    size_t j = 0;
    while (j < events.size() && 0 < events.size()) {
      if (events[j] == EventType::EventType0) {
        eh0.Process((void*)&events[j++]);
        continue;
      }
      if (events[j] == EventType::EventType1) {
        eh1.Process((void*)&events[j++]);
        continue;
      }
      if (events[j] == EventType::EventType2) {
        eh2.Process((void*)&events[j++]);
        continue;
      }
      if (events[j] == EventType::EventType3) {
        eh3.Process((void*)&events[j++]);
        continue;
      }
      if (events[j] == EventType::EventType4) {
        eh4.Process((void*)&events[j++]);
        continue;
      }
      if (events[j] == EventType::EventType5) {
        eh5.Process((void*)&events[j++]);
        continue;
      }
      if (events[j] == EventType::EventType6) {
        eh6.Process((void*)&events[j++]);
        continue;
      }
      if (events[j] == EventType::EventType7) {
        eh7.Process((void*)&events[j++]);
        continue;
      }
      if (events[j] == EventType::EventType8) {
        eh8.Process((void*)&events[j++]);
        continue;
      }
      if (events[j] == EventType::EventType9) {
        eh9.Process((void*)&events[j++]);
        continue;
      }
      ++j;
    }
  }
  auto time_Events_if_else_steady_clock =
    std::chrono::steady_clock::now() - time_Events_if_else_steady_clock_Start;
  auto time_Events_if_else_high_resolution_clock =
    std::chrono::high_resolution_clock::now() -
    time_Events_if_else_high_resolution_clock_Start;

  // Reset counters
  std::cout << "Events 'if/else' sum: " << eventsSum << "\n";
  eventsSum = 0;
  auto proccessedEvents_if_else = processedEventsCount;
  processedEventsCount = 0;

  //////////////////////////////////////////////////////////////////////////////
  // Events handled with 'switch'
  //////////////////////////////////////////////////////////////////////////////

  auto time_Events_switch_steady_clock_Start = std::chrono::steady_clock::now();
  auto time_Events_switch_high_resolution_clock_Start =
    std::chrono::high_resolution_clock::now();

  for (size_t a = 0; a < repeats; ++a) {
    size_t j = 0;
    while (j < events.size() && 0 < events.size()) {
      switch (events[j]) {
        case EventType::EventType0: {
          eh3.Process((void*)&events[j]);
          break;
        }
        case EventType::EventType1: {
          eh3.Process((void*)&events[j]);
          break;
        }
        case EventType::EventType2: {
          eh4.Process((void*)&events[j]);
          break;
        }
        case EventType::EventType3: {
          eh3.Process((void*)&events[j]);
          break;
        }
        case EventType::EventType4: {
          eh3.Process((void*)&events[j]);
          break;
        }
        case EventType::EventType5: {
          eh3.Process((void*)&events[j]);
          break;
        }
        case EventType::EventType6: {
          eh3.Process((void*)&events[j]);
          break;
        }
        case EventType::EventType7: {
          eh3.Process((void*)&events[j]);
          break;
        }
        case EventType::EventType8: {
          eh3.Process((void*)&events[j]);
          break;
        }
        case EventType::EventType9: {
          eh3.Process((void*)&events[j]);
          break;
        }
        default: {
          break;
        }
      }
      ++j;
    }
  }

  auto time_Events_switch_steady_clock =
    std::chrono::steady_clock::now() - time_Events_switch_steady_clock_Start;
  auto time_Events_switch_high_resolution_clock =
    std::chrono::high_resolution_clock::now() -
    time_Events_switch_high_resolution_clock_Start;

  // Reset counters
  std::cout << "Events 'if/else' sum: " << eventsSum << "\n";
  eventsSum = 0;
  auto proccessedEvents_switch = processedEventsCount;
  processedEventsCount = 0;

  //////////////////////////////////////////////////////////////////////////////
  // Results
  //////////////////////////////////////////////////////////////////////////////

  std::cout << "EventHandler:          " << std::setw(20)
            << time_EventHandlers_steady_clock.count() << " ns, "
            << std::setw(8)
            << std::chrono::duration_cast<std::chrono::milliseconds>(
                 time_EventHandlers_steady_clock)
                 .count()
            << " ms, processed events: " << proccessedEventHandlers << "\n";
  std::cout << "EventHandler:          " << std::setw(20)
            << time_EventHandlers_high_resolution_clock.count() << " ns, "
            << std::setw(8)
            << std::chrono::duration_cast<std::chrono::milliseconds>(
                 time_EventHandlers_high_resolution_clock)
                 .count()
            << " ms, processed events: " << proccessedEventHandlers << "\n";
  std::cout << "Events with 'if/else': " << std::setw(20)
            << time_Events_if_else_steady_clock.count() << " ns, "
            << std::setw(8)
            << std::chrono::duration_cast<std::chrono::milliseconds>(
                 time_Events_if_else_steady_clock)
                 .count()
            << " ms, processed events: " << proccessedEvents_if_else << "\n";
  std::cout << "Events with 'if/else': " << std::setw(20)
            << time_Events_if_else_high_resolution_clock.count() << " ns, "
            << std::setw(8)
            << std::chrono::duration_cast<std::chrono::milliseconds>(
                 time_Events_if_else_high_resolution_clock)
                 .count()
            << " ms, processed events: " << proccessedEvents_if_else << "\n";
  std::cout << "Events with 'switch':  " << std::setw(20)
            << time_Events_switch_steady_clock.count() << " ns, "
            << std::setw(8)
            << std::chrono::duration_cast<std::chrono::milliseconds>(
                 time_Events_switch_steady_clock)
                 .count()
            << " ms, processed events: " << proccessedEvents_switch << "\n";
  std::cout << "Events with 'switch':  " << std::setw(20)
            << time_Events_switch_high_resolution_clock.count() << " ns, "
            << std::setw(8)
            << std::chrono::duration_cast<std::chrono::milliseconds>(
                 time_Events_switch_high_resolution_clock)
                 .count()
            << " ms, processed events: " << proccessedEvents_switch << "\n";

  system("pause");
}
