#include "tab.hpp"

Inventory::Inventory(QFrame *tab_parent) : QFrame(tab_parent) { build_tab(); }

Inventory::~Inventory() = default;

auto Inventory::build_tab() -> void {}
auto Inventory::set_layout() -> void {}
auto Inventory::set_binding() -> void {}
auto Inventory::set_button() -> void {}
