#pragma once


#include "CoreMinimal.h"
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"
#include "Converter.hpp"
#include "Styling/SlateTypes.h"

#include "$SLATE_ATTRIBUTE.hpp"
#include "$SLATE_DEFAULT_SLOT.hpp"
#include "$SLATE_ARGUMENT_DEFAULT.hpp"
#include "$SLATE_SLOT_ARGUMENT.hpp"
#include "$SLATE_ARGUMENT.hpp"
#include "$SLATE_EVENT.hpp"
#include "$SLATE_NAMED_SLOT.hpp"
#include "$SLATE_STYLE_ARGUMENT.hpp"

#define SET_VARIABLE__(Name);\
WidgetArgument4::Set_##Name(Arguments, Isolate, JsObject, #Name, "")

#define SET_VARIABLE___WITH_TYPE(Name, Type);\
WidgetArgument4::Set_##Name##Type(Arguments, Isolate, JsObject, #Name, "")

#define SET_VARIABLE___A_Type(Name, Type);\
WidgetArgument4::Set_##Name<Type>(Arguments, Info,JsObject, #Type)

namespace WidgetOptional
{
	template<typename TType>
	TOptional<TType> MakeOptional(FJsObject& JsObject) { return TOptional<TType>(); }

	template<>	TOptional<FSlateSound> MakeOptional(FJsObject& JsObject) { return TOptional<FSlateSound>(); }
}

namespace WidgetDelegate
{
	//FSimpleDelegate MakeSimpleDelegate(FJsObject& JsObject)
	//{
	//	return FSimpleDelegate();
	//}

	//FOnClicked MakeOnClicked(FJsObject& JsObject)
	//{
	//	return FOnClicked();
	//}
}
