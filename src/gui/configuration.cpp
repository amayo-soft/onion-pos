#include "tab.hpp"

Configuration::Configuration(QFrame *tab_parent) : QFrame(tab_parent) { build_tab(); }

Configuration::~Configuration() = default;

auto Configuration::build_tab() -> void {}
auto Configuration::set_layout() -> void {}
auto Configuration::set_binding() -> void {}
auto Configuration::set_button() -> void {}
