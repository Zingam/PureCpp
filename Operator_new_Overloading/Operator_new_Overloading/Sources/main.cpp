#include <iostream>

// Static memory
static char g_memoryPool[1028]{ 0 };

class MemUserBase
{
public:
  MemUserBase() {}
  virtual ~MemUserBase(){};

public:
  void* operator new(std::size_t count) { return g_memoryPool; }

public:
  virtual void Exec() = 0;
};

class MemUser : public MemUserBase
{
public:
  MemUser() {}
  virtual ~MemUser(){};

public:
  void* operator new(std::size_t count);
  void operator delete(void* ptr);

public:
  void Exec() final { std::cout << "MemUser!\n"; }
};

void*
MemUser::operator new(std::size_t count)
{
  return g_memoryPool;
}

void
MemUser::operator delete(void* ptr){};

int
main(int argc, char* argv[])
{
  // Memory is already statically allocated and operator 'new' returns a pointer
  // to it.
  MemUser* memUser = new MemUser();
  MemUserBase* memUserBase = memUser;
  memUserBase->Exec();
  // Operator 'delete' is overloaded to prevent crash as statically allocated
  // memory cannot be deleted.
  delete memUserBase;

  system("pause");
}
