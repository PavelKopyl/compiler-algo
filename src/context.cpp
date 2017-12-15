#include "context.h"

namespace wyrm {
WyrmContext GlobalContext{};

string_view internedName(std::string &&name) {
  auto NameIt =
      std::get<0>(GlobalContext.StringStorage.insert(std::move(name)));
  return *NameIt;
}
} // namespace wyrm
