#include <chrono>
#include <iostream>
#include <memory>
#include <vector>

enum class EventType
{
  EventType1,
  EventType2,
  EventType3
};

volatile size_t u = 0;
volatile size_t processedItems = 0;

struct EventHandler
{
  virtual ~EventHandler(){};
  virtual auto Process(void* event) -> bool = 0;
};

struct Event1 : public EventHandler
{
  auto Process(void* event) -> bool
  {
    auto eventVal = *(EventType*)event;
    if (*(EventType*)event == EventType::EventType1) {
      u += (int)eventVal;
      ++processedItems;
      return true;
    } else {
      return false;
    }
  }
};

struct Event2 : public EventHandler
{
  auto Process(void* event) -> bool
  {
    auto eventVal = *(EventType*)event;
    if (eventVal == EventType::EventType2) {
      u += (int)eventVal;
      ++processedItems;
      return true;
    } else {
      return false;
    }
  }
};

struct Event3
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    u += (int)eventVal;
    ++processedItems;
  }
};

struct Event4
{
  auto Process(void* event) -> void
  {
    auto eventVal = *(EventType*)event;
    u += (int)eventVal;
    ++processedItems;
  }
};

int
main(int argc, char* argv[])
{
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
  std::vector<std::unique_ptr<EventHandler>> eh1s;
  eh1s.emplace_back(new Event1());
  eh1s.emplace_back(new Event2());

  size_t repeats = 10'000'000;
  repeats = 20;

  auto start1 = std::chrono::steady_clock::now();
  auto start11 = std::chrono::high_resolution_clock::now();

  for (size_t a = 0; a < repeats; ++a) {
    size_t i = 0;
    while (i < events.size()) {
      for (auto& eh : eh1s) {
        auto r = eh->Process(&events[i]);
        if (r == true) {
          break;
        }
      }
      ++i;
    }
  }
  auto time1 = std::chrono::steady_clock::now() - start1;
  auto time11 = std::chrono::high_resolution_clock::now() - start11;
  auto u1 = u;
  u = 0;
  auto proccessed1 = processedItems;
  processedItems = 0;

  Event3 eh3;
  Event4 eh4;
  auto start2 = std::chrono::steady_clock::now();
  auto start21 = std::chrono::high_resolution_clock::now();
  for (size_t a = 0; a < repeats; ++a) {
    size_t j = 0;
    while (j < events.size()) {
      if (events[j] == EventType::EventType1) {
        eh3.Process((void*)&events[j++]);
        continue;
      }
      if (events[j] == EventType::EventType2) {
        eh4.Process((void*)&events[j++]);
        continue;
      }
      ++j;
    }
  }
  auto time2 = std::chrono::steady_clock::now() - start2;
  auto time21 = std::chrono::high_resolution_clock::now() - start21;
  auto u2 = u;
  auto proccessed2 = processedItems;
  u = 0;
  processedItems = 0;

  auto start3 = std::chrono::steady_clock::now();
  auto start31 = std::chrono::high_resolution_clock::now();
  for (size_t a = 0; a < repeats; ++a) {
    size_t j = 0;
    while (j < events.size()) {
      switch (events[j]) {
        case EventType::EventType1: {
          eh3.Process((void*)&events[j]);
          break;
        }
        case EventType::EventType2: {
          eh4.Process((void*)&events[j]);
          break;
        }
        default: {
          break;
        }
      }
      ++j;
    }
  }
  auto time3 = std::chrono::steady_clock::now() - start3;
  auto time31 = std::chrono::high_resolution_clock::now() - start31;
  auto u3 = u;
  auto proccessed3 = processedItems;
  u = 0;
  processedItems = 0;

  std::cout
    << "time1: " << time1.count() << " ns, "
    << std::chrono::duration_cast<std::chrono::milliseconds>(time1).count()
    << " ms, total: " << u1 << ", processed items: " << proccessed1 << "\n";
  std::cout
    << "time1: " << time2.count() << " ns, "
    << std::chrono::duration_cast<std::chrono::milliseconds>(time2).count()
    << " ms, total: " << u2 << ", processed items: " << proccessed2 << "\n";
  std::cout
    << "time1: " << time3.count() << " ns, "
    << std::chrono::duration_cast<std::chrono::milliseconds>(time3).count()
    << " ms, total: " << u3 << ", processed items: " << proccessed3 << "\n";
  std::cout
    << "time11: " << time11.count() << " ns, "
    << std::chrono::duration_cast<std::chrono::milliseconds>(time11).count()
    << " ms, total: " << u1 << ", processed items: " << proccessed1 << "\n";
  std::cout
    << "time21: " << time21.count() << " ns, "
    << std::chrono::duration_cast<std::chrono::milliseconds>(time21).count()
    << " ms, total: " << u2 << ", processed items: " << proccessed2 << "\n";
  std::cout
    << "time21: " << time31.count() << " ns, "
    << std::chrono::duration_cast<std::chrono::milliseconds>(time31).count()
    << " ms, total: " << u3 << ", processed items: " << proccessed3 << "\n";

  system("pause");
}
