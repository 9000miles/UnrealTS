#pragma once

#define _EHorizontalAlignment_ "\"Fill\" | \"Left\" | \"Center\"| \"Right\""
#define _EVerticalAlignment_ "\"Fill\" | \"Top\" | \"Center\" | \"Bottom\""

#define ARGUMENT_NAME(Name)\
const char* _##Name = #Name;\
if (Arguments.Has(_##Name))

#define SET_ARGUMENT_Text()\
ARGUMENT_NAME(Text)\
{\
	FString TextString = FString(Arguments.Get<std::string>(_Text).c_str());\
	_Arguments.Text(FText::FromString(TextString));\
}

#define SET_ARGUMENT_ColorAndOpacity()\
ARGUMENT_NAME(ColorAndOpacity)\
{\
	FSlateColor ColorAndOpacity = Arguments.Get<FSlateColor>(_ColorAndOpacity);\
	_Arguments.ColorAndOpacity(ColorAndOpacity);\
}
