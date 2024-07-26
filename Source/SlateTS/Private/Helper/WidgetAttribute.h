#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"
#include "Converter.hpp"


namespace WidgetAttribute
{
	template<typename TType>
	TAttribute<TType> MakeAttribute(v8::Local<v8::Context>& Context, v8::Local<v8::Value> Value) { return TAttribute<TType>(); }

	/** ======================= MakeAttribute ======================= **/
#define DEFINE_MAKE_ATTRIBUTE(Type)\
	template<> TAttribute<Type> MakeAttribute(v8::Local<v8::Context>& Context, v8::Local<v8::Value> Value);

	DEFINE_MAKE_ATTRIBUTE(FText);
	DEFINE_MAKE_ATTRIBUTE(float);
	DEFINE_MAKE_ATTRIBUTE(bool);
	DEFINE_MAKE_ATTRIBUTE(FSlateFontInfo);
	DEFINE_MAKE_ATTRIBUTE(FSlateBrush*);
	DEFINE_MAKE_ATTRIBUTE(FSlateColor);
	DEFINE_MAKE_ATTRIBUTE(FVector2D);
	DEFINE_MAKE_ATTRIBUTE(FLinearColor);
	DEFINE_MAKE_ATTRIBUTE(ETextWrappingPolicy);
	DEFINE_MAKE_ATTRIBUTE(ETextTransformPolicy);
	DEFINE_MAKE_ATTRIBUTE(FMargin);
	DEFINE_MAKE_ATTRIBUTE(ETextJustify::Type);
	DEFINE_MAKE_ATTRIBUTE(ECheckBoxState);
	DEFINE_MAKE_ATTRIBUTE(EMenuPlacement);
	DEFINE_MAKE_ATTRIBUTE(EMouseCursor::Type);
};
