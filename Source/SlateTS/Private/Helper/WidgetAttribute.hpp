#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"
#include "Converter.hpp"


namespace WidgetAttribute
{
	template<typename TType>
	TAttribute<TType> MakeAttribute(v8::Local<v8::Context>& Context, v8::Local<v8::Value> Value, const char* WidgetClass = "") { return TAttribute<TType>(); }

	/** ======================= MakeAttribute ======================= **/
#define MAKE_ATTRIBUTE(Type)\
	template<> TAttribute<Type> MakeAttribute(v8::Local<v8::Context>& Context, v8::Local<v8::Value> Value, const char* WidgetClass)\
	{\
		if (Value->IsFunction())\
		{\
			v8::Local<v8::Function> Function = Value.As<v8::Function>();\
			FJsObject JsObject = FJsObject(Context, Function);\
			TAttribute<Type>::FGetter Getter;\
			Getter.BindLambda([JsObject]() { return JsObject.Func<Type>(nullptr); });\
			return TAttribute<Type>::Create(Getter);\
		}\
		if (puerts::converter::Converter<Type>::accept(Context, Value))\
		{\
			Type Ret = puerts::converter::Converter<Type>::toCpp(Context, Value);\
			return TAttribute<Type>(Ret);\
		}\
		return TAttribute<Type>();\
	}

	MAKE_ATTRIBUTE(FText);
	MAKE_ATTRIBUTE(float);
	MAKE_ATTRIBUTE(bool);
	MAKE_ATTRIBUTE(FSlateFontInfo);
	MAKE_ATTRIBUTE(FSlateBrush*);
	MAKE_ATTRIBUTE(FSlateColor);
	MAKE_ATTRIBUTE(FVector2D);
	MAKE_ATTRIBUTE(FLinearColor);
	MAKE_ATTRIBUTE(ETextWrappingPolicy);
	MAKE_ATTRIBUTE(ETextTransformPolicy);
	MAKE_ATTRIBUTE(FMargin);
	MAKE_ATTRIBUTE(ETextJustify::Type);
	MAKE_ATTRIBUTE(ECheckBoxState);
	MAKE_ATTRIBUTE(EMenuPlacement);
	MAKE_ATTRIBUTE(EMouseCursor::Type);
};