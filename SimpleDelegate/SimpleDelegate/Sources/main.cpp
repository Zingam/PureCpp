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

  // Call the delegate via a smart pointer
  using DoubleAndPrintDelegateType = Delegate<A, decltype(&A::DoubleAndPrint)>;
  std::unique_ptr<DoubleAndPrintDelegateType> delegate_DoubleAndPrint_UPtr =
    std::make_unique<DoubleAndPrintDelegateType>(a, &A::DoubleAndPrint);

  if (delegate_DoubleAndPrint_UPtr) {
    auto a = *delegate_DoubleAndPrint_UPtr;
    a(3);
    (*delegate_DoubleAndPrint_UPtr)(3);
  }

  auto delegate_DoubleAndPrint_Ptr = delegate_DoubleAndPrint_UPtr.release();
  if (!delegate_DoubleAndPrint_UPtr) {
    std::cout << "'delegate_DoubleAndPrint_Ptr' is 'nullptr'" << std::endl;
  }

  // Call the delegate via a raw pointer
  if (delegate_DoubleAndPrint_Ptr)
  {
    (*delegate_DoubleAndPrint_Ptr)(4);
  }

  system("pause");
}
