/// \file
/// \brief Compatibility with old versions of the standard library.
/// Provide aliases for STL types introduced in C++17 in wyrm namespace so that
/// if the version of the standard library used to build wyrm doesn't support a
/// type boost analog is used instead.
#ifndef COMPATIBILITY_H
#define COMPATIBILITY_H

#if __has_include(<variant>) && !defined(USE_BOOST_CONTAINERS)
#include <variant>
#else
#include <boost/variant.hpp>
#endif
#include <iostream>
#if __has_include(<optional>) && !defined(USE_BOOST_CONTAINERS)
#include <optional>
#else
#include <boost/optional.hpp>
#endif
#if __has_include(<string_view>) && !defined(USE_BOOST_CONTAINERS)
#include <string_view>
#elif __has_include(<experimental/string_view>) && !defined(USE_BOOST_CONTAINERS)
#include <experimental/string_view>
#else
#include <boost/utility/string_view.hpp>
#endif

namespace wyrm {
#if __has_include(<variant>) && !defined(USE_BOOST_CONTAINERS)
template <typename... Args> using variant = std::variant<Args...>;
template <typename... ArgTys> inline auto visit(ArgTys &&... Args) {
  return std::visit(std::forward<ArgTys>(Args)...);
};
template <typename T, typename... ArgTys> inline auto get(ArgTys &&... Args) {
  return std::get<T>(std::forward<ArgTys>(Args)...);
};
#else
template <typename... Args> using variant = boost::variant<Args...>;
template <typename... ArgTys> inline auto visit(ArgTys &&... Args) {
  return boost::apply_visitor(std::forward<ArgTys>(Args)...);
};
template <typename T, typename... ArgTys> inline auto get(ArgTys &&... Args) {
  return boost::get<T>(std::forward<ArgTys>(Args)...);
};
#endif

#if __has_include(<optional>) && !defined(USE_BOOST_CONTAINERS)
template <typename ValueT> using optional = std::optional<ValueT>;
#else
template <typename ValueT> using optional = boost::optional<ValueT>;
#endif

#if __has_include(<string_view>) && !defined(USE_BOOST_CONTAINERS)
using string_view = std::string_view;
#elif __has_include(<experimental/string_view>) && !defined(USE_BOOST_CONTAINERS)
using string_view = std::experimental::string_view;
#else
using string_view = boost::string_view;
#endif
}

#endif // COMPATIBILITY_H
