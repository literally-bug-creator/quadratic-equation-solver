#pragma once

#include <any>
#include <functional>

using Selector = std::function<std::any( int index )>;
