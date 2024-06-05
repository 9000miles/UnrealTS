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
#define SET_SLATE_ATTRIBUTE(Type, Name, Tag)\
	template<typename TArgumentType>\
	void Set_##Name##_##Tag(TArgumentType& Arguments, v8::Isolate* Isolate, v8::Local<v8::Object>& JsObject, const char* VariableName)\
	{\
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();\
		const bool bHas = JsObject->Has(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).FromMaybe(false);\
		if (!bHas) return;\
		v8::Local<v8::Value> JsValue = JsObject->Get(Context, puerts::FV8Utils::ToV8String(Isolate, VariableName)).ToLocalChecked();\
		Arguments._##Name = WidgetAttribute::MakeAttribute<Type>(Context, JsValue);\
	}

	SET_SLATE_ATTRIBUTE(FText, Text, );
	SET_SLATE_ATTRIBUTE(FSlateFontInfo, Font, );
	SET_SLATE_ATTRIBUTE(const FSlateBrush*, StrikeBrush, );
	SET_SLATE_ATTRIBUTE(FSlateColor, ColorAndOpacity, FSlateColor);
	SET_SLATE_ATTRIBUTE(FLinearColor, ColorAndOpacity, FLinearColor);
	SET_SLATE_ATTRIBUTE(FVector2D, ShadowOffset, );
	SET_SLATE_ATTRIBUTE(FLinearColor, ShadowColorAndOpacity, );
	SET_SLATE_ATTRIBUTE(FLinearColor, HighlightColor, );
	SET_SLATE_ATTRIBUTE(const FSlateBrush*, HighlightShape, );
	SET_SLATE_ATTRIBUTE(FText, HighlightText, );
	SET_SLATE_ATTRIBUTE(float, WrapTextAt, );
	SET_SLATE_ATTRIBUTE(bool, AutoWrapText, );
	SET_SLATE_ATTRIBUTE(ETextWrappingPolicy, WrappingPolicy, );
	SET_SLATE_ATTRIBUTE(ETextTransformPolicy, TransformPolicy, );
	SET_SLATE_ATTRIBUTE(FMargin, Margin, );
	SET_SLATE_ATTRIBUTE(FMargin, Padding, );
	SET_SLATE_ATTRIBUTE(float, LineHeightPercentage, );
	SET_SLATE_ATTRIBUTE(ETextJustify::Type, Justification, );
	SET_SLATE_ATTRIBUTE(float, MinDesiredWidth, float);
	SET_SLATE_ATTRIBUTE(FVector2D, DesiredSizeScale, );
	SET_SLATE_ATTRIBUTE(FVector2D, ContentScale, );
	SET_SLATE_ATTRIBUTE(FSlateColor, ButtonColorAndOpacity, );
	SET_SLATE_ATTRIBUTE(FSlateColor, ForegroundColor, );
	SET_SLATE_ATTRIBUTE(FSlateColor, BorderBackgroundColor, );
	SET_SLATE_ATTRIBUTE(ECheckBoxState, IsChecked, );
	SET_SLATE_ATTRIBUTE(bool, ShowEffectWhenDisabled, );
	SET_SLATE_ATTRIBUTE(EMenuPlacement, MenuPlacement, );
	SET_SLATE_ATTRIBUTE(const FSlateBrush*, BorderImage, );
	SET_SLATE_ATTRIBUTE(FMargin, ContentPadding, );
	SET_SLATE_ATTRIBUTE(EMenuPlacement, Placement, );
	SET_SLATE_ATTRIBUTE(FOptionalSize, WidthOverride, );
	SET_SLATE_ATTRIBUTE(FOptionalSize, HeightOverride, );
	SET_SLATE_ATTRIBUTE(FOptionalSize, MinDesiredHeight, );
	SET_SLATE_ATTRIBUTE(FOptionalSize, MinDesiredWidth, );
	SET_SLATE_ATTRIBUTE(FOptionalSize, MaxDesiredWidth, );
	SET_SLATE_ATTRIBUTE(FOptionalSize, MaxDesiredHeight, );
	SET_SLATE_ATTRIBUTE(FOptionalSize, MinAspectRatio, );
	SET_SLATE_ATTRIBUTE(FOptionalSize, MaxAspectRatio, );
	SET_SLATE_ATTRIBUTE(FSlateColor, BodyBorderBackgroundColor, );
	SET_SLATE_ATTRIBUTE(FText, AreaTitle, );
	SET_SLATE_ATTRIBUTE(FMargin, AreaTitlePadding, );
	SET_SLATE_ATTRIBUTE(FMargin, HeaderPadding, );
	SET_SLATE_ATTRIBUTE(FSlateFontInfo, AreaTitleFont, );
	SET_SLATE_ATTRIBUTE(TOptional<EMouseCursor::Type>, HeaderCursor, );
}
