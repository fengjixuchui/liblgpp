#include <cassert>

#include "lgpp/ops/push.hpp"
#include "lgpp/ops/stop.hpp"
#include "lgpp/stack.hpp"
#include "lgpp/thread.hpp"
#include "lgpp/type.hpp"
#include "lgpp/vm.hpp"

namespace lgpp::types {
    template <>
    bool eq(lgpp::Type<int> &type, const int &x, const Val &y) { return x == y.as(type); }
}

using namespace lgpp;

void vm_tests() {
  VM vm;
  Stack s;
  Type<int> t("Int");
  Val v(t, 42);

  vm.emit<ops::Push>(v);
  vm.emit<ops::Stop>();
  auto &stop(vm.last_op());
  assert(stop.pc == 1);
  assert(&vm.eval(0, s) == &stop); 
  assert(s.size() == 1);
  assert(s.back() == v);
}

int main() {
  vm_tests();
  return 0;
}