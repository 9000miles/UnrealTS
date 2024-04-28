#pragma once

// **************************** WIDGET_ARGUMENT_ENUM ****************************
#define _EHorizontalAlignment_ "\"Fill\" | \"Left\" | \"Center\"| \"Right\""
#define _EVerticalAlignment_ "\"Fill\" | \"Top\" | \"Center\" | \"Bottom\""

// **************************** REGISTER_WIDGET_ARGUMENT_TYPE ****************************
#define REGISTER_WIDGET_ARGUMENT_TYPE__Text()\
Arg.Add("Text", "string | (() => string)")

#define REGISTER_WIDGET_ARGUMENT_TYPE__Margin()\
Arg.Add("Margin", "UE.Margin | number | { Horizontal: number, Vertical: number } | { Left: number, Top: number, Right: number, Buttom: number}");