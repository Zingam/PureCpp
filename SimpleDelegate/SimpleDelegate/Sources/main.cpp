#include <iostream>
#include <type_traits>

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

private:
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
  std::cout << "2 + 2 = " << delegate_Double(2) << std::endl;

  Delegate<A, decltype(&A::DoubleAndPrint)> delegate_DoubleAndPrint{
    a, &A::DoubleAndPrint
  };
  delegate_DoubleAndPrint(2);

  system("pause");
}
