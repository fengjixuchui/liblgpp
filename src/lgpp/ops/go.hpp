#ifndef LGPP_OPS_GO_HPP
#define LGPP_OPS_GO_HPP

#include "../val.hpp"
#include "../op.hpp"

namespace lgpp::ops {

  struct Go {
    Go(Label& target): target(target) {}
    Label& target;
  };

  template <>
  inline const Op* eval(const Op& op, const Go& imp, lgpp::Thread& thread, lgpp::Stack& stack) {
    return &op - op.pc + *imp.target.pc;
  }

}

#endif
