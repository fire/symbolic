/**
 * proposition.h
 *
 * Copyright 2018. All Rights Reserved.
 *
 * Created: November 28, 2018
 * Authors: Toki Migimatsu
 */

#ifndef SYMBOLIC_PROPOSITION_H_
#define SYMBOLIC_PROPOSITION_H_

#include <ostream>  // std::ostream
#include <set>      // std::set
#include <string>   // std::string
#include <vector>   // std::vector
#include <utility>  // std::tie

#include "ptree.h"

#include "symbolic/object.h"

namespace symbolic {

class Pddl;

class Proposition {

 public:

  Proposition() {}

  Proposition(const std::string& name_predicate, std::vector<Object>&& arguments)
      :  name_(name_predicate), arguments_(std::move(arguments)) {}

  Proposition(const std::string& name_predicate, const std::vector<Object>& arguments)
      :  name_(name_predicate), arguments_(arguments) {}

  Proposition(const Pddl& pddl, const std::string& str_prop);

  // Properties
  const std::string& name() const { return name_; }

  const std::vector<Object>& arguments() const { return arguments_; }

  std::string to_string() const;

 private:

  std::string name_;
  std::vector<Object> arguments_;

};

inline std::string ParseHead(const std::string& atom) {
  return atom.substr(0, atom.find_first_of('('));
}

std::ostream& operator<<(std::ostream& os, const Proposition& P);

inline bool operator<(const Proposition& lhs, const Proposition& rhs) {
  return std::tie(lhs.name(), lhs.arguments()) < std::tie(rhs.name(), rhs.arguments());
}
inline bool operator==(const Proposition& lhs, const Proposition& rhs) {
  return std::tie(lhs.name(), lhs.arguments()) == std::tie(rhs.name(), rhs.arguments());
}
inline bool operator!=(const Proposition& lhs, const Proposition& rhs) { return !(lhs == rhs); }

}  // namespace symbolic

#endif  // SYMBOLIC_PROPOSITION_H_
