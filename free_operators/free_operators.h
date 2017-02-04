#ifndef _FREE_OPERATORS_H_
#define _FREE_OPERATORS_H_

#include <type_traits>
#include <iostream> // required for stream insertion/extraction operators.

/*
Trait class.
Any class that derives from FreeOperators
shows its intent to define all free operators
that can be defined for it.
 */
class FreeOperators
{};

#include "operator+.f"
#include "operator-.f"
#include "operator*.f"
#include "operator_div.f"
#include "operator%.f"
#include "operator|.f"
#include "operator&.f"
#include "operator^.f"
#include "operator>>.f"
#include "operator<<.f"
#include "operator_insert.f"
#include "operator_extract.f"

#endif //_FREE_OPERATORS_H_
