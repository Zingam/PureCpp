#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// class BaseData
////////////////////////////////////////////////////////////////////////////////

class BaseData
{
public:
  BaseData();
  virtual ~BaseData();

public:
  virtual void CallFunctions() final;
  virtual void PrintData();
  virtual void SetData();

private:
  void Function1();
  void Function2();

protected:
  std::string baseData;
  std::string data;

  std::vector<std::function<void(void)>> functions;
};

BaseData::BaseData()
  : functions{ [this]() { this->Function1(); },
               [this]() { this->Function2(); } }
{
  std::cout << "BaseData: constructed\n";
}

BaseData::~BaseData()
{
  std::cout << "BaseData: destroyed\n";
}

void
BaseData::CallFunctions()
{
  for (auto& function : functions) {
    function();
  }
}

void
BaseData::Function1()
{
  std::cout << "BaseData: Function1()\n";
}

void
BaseData::Function2()
{
  std::cout << "BaseData: Function2()\n";
}

void
BaseData::PrintData()
{
  std::cout << "  BaseData: this->baseData = " << this->baseData << "\n";
  std::cout << "  BaseData: this->data = " << this->data << "\n";
}

void
BaseData::SetData()
{
  this->baseData = std::string{ "baseData" };
  this->data = std::string{ "Base data" };
}

////////////////////////////////////////////////////////////////////////////////
// class DerivedData
////////////////////////////////////////////////////////////////////////////////

class DerivedData : public BaseData
{
public:
  DerivedData();
  ~DerivedData() final;

public:
  void PrintData() final;
  void SetData() final;

private:
  void Function1();
  void Function2();

private:
  std::string data;
  std::string derivedData;
};

DerivedData::DerivedData()
{
  std::cout << "DerivedData: constructed\n";
  BaseData::functions.push_back([this]() { this->Function1(); });
  BaseData::functions.push_back([this]() { this->Function2(); });
}

DerivedData::~DerivedData()
{
  std::cout << "DerivedData: destroyed\n";
}

void
DerivedData::Function1()
{
  std::cout << "DerivedData: Function1()\n";
}

void
DerivedData::Function2()
{
  std::cout << "DerivedData: Function2()\n";
}

void
DerivedData::PrintData()
{
  std::cout << "  DerivedData: BaseData::baseData = " << BaseData::baseData
            << "\n";
  std::cout << "  DerivedData: BaseData::data = " << BaseData::data << "\n";
  std::cout << "  DerivedData: this->baseData = " << this->baseData << "\n";
  std::cout << "  DerivedData: this->data = " << this->data << "\n";
}

void
DerivedData::SetData()
{
  BaseData::SetData();
  BaseData::data = std::string{ "Derived data 1" };
  this->data = std::string{ "Derived data 2" };
  this->derivedData = std::string{ "derivedData" };
}

////////////////////////////////////////////////////////////////////////////////
// class BaseWorker (abstract interface)
////////////////////////////////////////////////////////////////////////////////

class BaseWorker
{
protected:
  BaseWorker();
  virtual ~BaseWorker() = 0;

public:
  void CallFunctions();
  void SetData(std::unique_ptr<BaseData> data);

public:
  virtual void DoDerivedWork() = 0;
  virtual void DoBaseWork();

protected:
  std::unique_ptr<BaseData> data;
};

BaseWorker::BaseWorker()
{
  std::cout << "BaseWorker: constructed\n";
}

BaseWorker::~BaseWorker()
{
  std::cout << "BaseWorker: destroyed\n";
}


void
BaseWorker::CallFunctions()
{
  this->data->CallFunctions();
}

void
BaseWorker::SetData(std::unique_ptr<BaseData> data)
{
  this->data = std::move(data);
}

void
BaseWorker::DoBaseWork()
{
  std::cout << "BaseWorker: base work done\n";
  if (this->data) {
    this->data->SetData();
    this->data->PrintData();
  }
}

////////////////////////////////////////////////////////////////////////////////
// class DerivedWorker
////////////////////////////////////////////////////////////////////////////////

class DerivedWorker : public BaseWorker
{
private:
  DerivedWorker();
  virtual ~DerivedWorker() final;

public:
  void CallFunctions();
  void DoDerivedWork() final;
  void DoBaseWork() final;

public:
  friend BaseWorker& CreateWorker();
};

DerivedWorker::DerivedWorker()
{
  std::cout << "DerivedWorker: constructed\n";
}

DerivedWorker::~DerivedWorker()
{
  std::cout << "DerivedWorker: constructed\n";
}

void
DerivedWorker::DoDerivedWork()
{
  std::cout << "DerivedWorker: derived work done\n";
  if (this->data) {
    this->data->SetData();
    this->data->PrintData();
  }
}

void
DerivedWorker::DoBaseWork()
{
  std::cout << "DerivedWorker: base work done\n";
  if (this->data) {
    this->data->SetData();
    this->data->PrintData();
  }
}

////////////////////////////////////////////////////////////////////////////////
// Factory functions
////////////////////////////////////////////////////////////////////////////////

BaseWorker&
CreateWorker()
{
  static DerivedWorker derived;
  return derived;
}

////////////////////////////////////////////////////////////////////////////////
// main()
////////////////////////////////////////////////////////////////////////////////

int
main(int argc, char* argv[])
{
  auto& worker = CreateWorker();

  worker.SetData(std::make_unique<BaseData>());
  worker.DoDerivedWork();
  worker.DoBaseWork();
  worker.CallFunctions();

  worker.SetData(std::make_unique<DerivedData>());
  worker.DoDerivedWork();
  worker.DoBaseWork();
  worker.CallFunctions();

  system("pause");
}
