//
#include "WidgetAttribute.h"
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"
#include "Converter.hpp"



/** ======================= MakeAttribute ======================= **/
#define IMPL_MAKE_ATTRIBUTE(Type)\
template<> TAttribute<Type> WidgetAttribute::MakeAttribute(v8::Local<v8::Context>& Context, v8::Local<v8::Value> Value)\
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

IMPL_MAKE_ATTRIBUTE(FText);
IMPL_MAKE_ATTRIBUTE(float);
IMPL_MAKE_ATTRIBUTE(bool);
IMPL_MAKE_ATTRIBUTE(FSlateFontInfo);
IMPL_MAKE_ATTRIBUTE(FSlateBrush*);
IMPL_MAKE_ATTRIBUTE(FSlateColor);
IMPL_MAKE_ATTRIBUTE(FVector2D);
IMPL_MAKE_ATTRIBUTE(FLinearColor);
IMPL_MAKE_ATTRIBUTE(ETextWrappingPolicy);
IMPL_MAKE_ATTRIBUTE(ETextTransformPolicy);
IMPL_MAKE_ATTRIBUTE(FMargin);
IMPL_MAKE_ATTRIBUTE(ETextJustify::Type);
IMPL_MAKE_ATTRIBUTE(ECheckBoxState);
IMPL_MAKE_ATTRIBUTE(EMenuPlacement);
IMPL_MAKE_ATTRIBUTE(EMouseCursor::Type);

