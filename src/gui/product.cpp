#include "tab.hpp"

Product::Product(QFrame *tab_parent) : QFrame(tab_parent) { build_tab(); }

Product::~Product() = default;

auto Product::build_tab() -> void {}
auto Product::set_layout() -> void {}
auto Product::set_binding() -> void {}
auto Product::set_button() -> void {}
