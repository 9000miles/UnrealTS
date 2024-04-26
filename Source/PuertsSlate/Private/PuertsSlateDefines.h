#pragma once

// **************************** WIDGET_ARGUMENT_ENUM ****************************
#define _EHorizontalAlignment_ "\"Fill\" | \"Left\" | \"Center\"| \"Right\""
#define _EVerticalAlignment_ "\"Fill\" | \"Top\" | \"Center\" | \"Bottom\""

// **************************** WIDGET_ARGUMENT_SET ****************************
#define WIDGET_ARGUMENT_NAME(Name)\
const char* _##Name = #Name;\
if (Arguments.Has(_##Name))

#define WIDGET_ARGUMENT_SET__Text()\
WIDGET_ARGUMENT_NAME(Text)\
{\
	FString TextString = FString(Arguments.Get<std::string>(_Text).c_str());\
	_Arguments.Text(FText::FromString(TextString));\
}

#define WIDGET_ARGUMENT_SET__ColorAndOpacity()\
WIDGET_ARGUMENT_NAME(ColorAndOpacity)\
{\
	FSlateColor ColorAndOpacity = Arguments.Get<FSlateColor>(_ColorAndOpacity);\
	_Arguments.ColorAndOpacity(ColorAndOpacity);\
}

// **************************** REGISTER_WIDGET_ARGUMENT_TYPE ****************************
#define REGISTER_WIDGET_ARGUMENT_TYPE__Text()\
Arg.Add("Text", "string | () => string")

#define REGISTER_WIDGET_ARGUMENT_TYPE__Margin()\
Arg.Add("Margin", "UE.Margin | number | { Horizontal: number, Vertical: number } | { Left: number, Top: number, Right: number, Buttom: number}");