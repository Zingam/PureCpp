#include <chrono>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <vector>

template<typename ClassName, typename MethodPointerType>
class Delegate
{
public:
  Delegate(ClassName& object, MethodPointerType method)
    : method{ method }
    , object{ object }
  {}

public:
  template<typename... Args>
  inline auto operator()(Args... args)
    -> std::enable_if_t<std::is_same_v<void, decltype(this->Invoke(args...))>,
                        decltype(this->Invoke(args...))>
  {
    return this->Invoke(std::forward<Args>(args)...);
  }

  template<typename... Args>
  inline auto operator()(Args... args)
    -> std::enable_if_t<!std::is_same_v<void, decltype(this->Invoke(args...))>,
                        decltype(this->Invoke(args...))>
  {
    return this->Invoke(std::forward<Args>(args)...);
  }

public:
  template<typename... Args>
  inline auto Invoke(Args... args) -> std::enable_if_t<
    std::is_same_v<void, decltype((object.*method)(args...))>,
    decltype((object.*method)(args...))>
  {
    (object.*method)(std::forward<Args>(args)...);
  }

  template<typename... Args>
  inline auto Invoke(Args... args) -> std::enable_if_t<
    !std::is_same_v<void, decltype((object.*method)(args...))>,
    decltype((object.*method)(args...))>
  {
    return (object.*method)(std::forward<Args>(args)...);
  }

private:
  MethodPointerType method;
  ClassName& object;
};

class A
{
public:
  auto Double(int i) -> int { return 2 * i; }

  void DoubleAndPrint(int i)
  {
    auto doubleResult = 2 * i;
    std::cout << i << " + " << i << " = " << doubleResult << std::endl;
  }
};

int
main(int argc, char* argv[])
{
  A a;
  Delegate<A, decltype(&A::Double)> delegate_Double{ a, &A::Double };
  auto result1 = delegate_Double.Invoke(1);
  std::cout << "1 + 1 = " << result1 << std::endl;
  auto result2 = delegate_Double(2);
  std::cout << "2 + 2 = " << result2 << std::endl;

  Delegate<A, decltype(&A::DoubleAndPrint)> delegate_DoubleAndPrint{
    a, &A::DoubleAndPrint
  };
  delegate_DoubleAndPrint.Invoke(3);
  delegate_DoubleAndPrint(4);

  system("pause");
}
