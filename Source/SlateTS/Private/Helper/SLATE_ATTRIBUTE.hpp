#pragma once
#include "JsObject.h"
#include "v8.h"
#include "V8Utils.h"
#include "Converter.hpp"

#define $SLATE_ATTRIBUTE(Type, Name, Tag)\
$SLATE_ATTRIBUTE$::Set_##Name##_##Tag(Arguments, Isolate, JsObject, #Name)

/** ======================= SET_SLATE_ATTRIBUTE ======================= **/
namespace $SLATE_ATTRIBUTE$
{
#define DEFINE_FUNCTION_SLATE_ATTRIBUTE(Type, Name, Tag)\
	template<typename TArgumentType>\
	void Set_##Name##_##Tag(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName)\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).FromMaybe(false);\
		if (!bHas) return;\
		v8::Local<v8::Value> JsValue = JsObject->Get(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).ToLocalChecked();\
		Arguments._##Name = WidgetAttribute::MakeAttribute<Type>(Context, JsValue);\
	}

	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, Text, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateFontInfo, Font, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(const FSlateBrush*, StrikeBrush, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, ColorAndOpacity, FSlateColor);
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FLinearColor, ColorAndOpacity, FLinearColor);
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FVector2D, ShadowOffset, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FLinearColor, ShadowColorAndOpacity, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FLinearColor, HighlightColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(const FSlateBrush*, HighlightShape, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, HighlightText, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, WrapTextAt, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, AutoWrapText, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(ETextWrappingPolicy, WrappingPolicy, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(ETextTransformPolicy, TransformPolicy, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FMargin, Margin, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FMargin, Padding, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, LineHeightPercentage, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(ETextJustify::Type, Justification, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(float, MinDesiredWidth, float);
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FVector2D, DesiredSizeScale, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FVector2D, ContentScale, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, ButtonColorAndOpacity, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, ForegroundColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, BorderBackgroundColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(ECheckBoxState, IsChecked, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(bool, ShowEffectWhenDisabled, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(EMenuPlacement, MenuPlacement, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(const FSlateBrush*, BorderImage, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FMargin, ContentPadding, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(EMenuPlacement, Placement, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FOptionalSize, WidthOverride, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FOptionalSize, HeightOverride, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FOptionalSize, MinDesiredHeight, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FOptionalSize, MinDesiredWidth, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FOptionalSize, MaxDesiredWidth, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FOptionalSize, MaxDesiredHeight, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FOptionalSize, MinAspectRatio, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FOptionalSize, MaxAspectRatio, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateColor, BodyBorderBackgroundColor, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FText, AreaTitle, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FMargin, AreaTitlePadding, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FMargin, HeaderPadding, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(FSlateFontInfo, AreaTitleFont, );
	DEFINE_FUNCTION_SLATE_ATTRIBUTE(TOptional<EMouseCursor::Type>, HeaderCursor, );
}
