#pragma once


#include "CoreMinimal.h"
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"
#include "Converter.hpp"
#include "Styling/SlateTypes.h"
#include "SLATE_ATTRIBUTE.hpp"
#include "SLATE_ARGUMENT.hpp"
#include "SLATE_STYLE_ARGUMENT.hpp"
#include "SLATE_EVENT_GLUE.hpp"

#define SET_WIDGET_ARGUMENT_VARIABLE_A(Name);\
WidgetArgument4::Set_##Name(Arguments, Isolate, JsObject, #Name, "")

#define SET_WIDGET_ARGUMENT_VARIABLE_A_Type(Name, Type);\
WidgetArgument4::Set_##Name<Type>(Arguments, Info,JsObject, #Type)

namespace WidgetOptional
{
	template<typename TType>
	TOptional<TType> MakeOptional(FJsObject& JsObject) { return TOptional<TType>(); }

	template<>	TOptional<FSlateSound> MakeOptional(FJsObject& JsObject) { return TOptional<FSlateSound>(); }
}

namespace WidgetDelegate
{
	FSimpleDelegate MakeSimpleDelegate(FJsObject& JsObject)
	{
		return FSimpleDelegate();
	}

	FOnClicked MakeOnClicked(FJsObject& JsObject)
	{
		return FOnClicked();
	}
}
