#include "box.h"

namespace prj
{

box::box(const category& cat): category_{cat}, contract_{std::unique_ptr<contract>(new contract())}
{

}

}