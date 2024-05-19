#pragma once

// **************************** CALL_SET_ATTRIBUTE_FUNCTION ****************************
#define CALL_FUNCTION_SET__Attribute(Type, Name)\
if (FunctionName == #Name)\
{\
	TAttribute<Type> Parameter = WidgetAttribute2::MakeAttribute<Type>(JsObject);\
	Widget->##Name(Parameter);\
}
#define CALL_FUNCTION_SET__Optional(Type, Name)\
if (FunctionName == #Name)\
{\
	TOptional<Type> Parameter = WidgetAttribute2::MakeOptional<Type>(JsObject);\
	Widget->##Name(Parameter);\
}
#define CALL_FUNCTION_SET__SimpleDelegate(Type, Name)\
if (FunctionName == #Name)\
{\
	FSimpleDelegate Delegate = WidgetAttribute2::MakeSimpleDelegate(JsObject);\
	Widget->##Name(Delegate);\
}
#define CALL_FUNCTION_SET__OnClicked(Type, Name)\
if (FunctionName == #Name)\
{\
	FOnClicked Delegate = WidgetAttribute2::MakeOnClicked(JsObject);\
	Widget->##Name(Delegate);\
}

// **************************** RETURN_MAKE_SHARED_WIDGET_PTR ****************************
#define RETURN_MAKE_SHARED_WIDGET_PTR(WidgetType)\
return MakeTDecl<WidgetType>(#WidgetType, TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;

// **************************** DEFINE_ATTRIBUTE_FUNCTION ****************************
#define CALL_SET_ATTRIBUTE_FUNCTION(FunctionName, EType)\
void $##FunctionName(FJsObject JsObject) { FunctionName(WidgetAttribute2::MakeAttribute<Type>(JsObject)); }
#define CALL_SET_OPTIONAL_FUNCTION(FunctionName, EType)\
void $##FunctionName(FJsObject JsObject) { FunctionName(WidgetOptional::MakeOptional<Type>(JsObject)); }
#define CALL_SET_SIMPLE_DELEGATE_FUNCTION(FunctionName)\
void $##FunctionName(FJsObject JsObject) { FunctionName(WidgetDelegate::MakeSimpleDelegate(JsObject)); }
#define CALL_SET_ON_CLICKED_FUNCTION(FunctionName)\
void $##FunctionName(FJsObject JsObject) { FunctionName(WidgetDelegate::MakeOnClicked(JsObject)); }


// **************************** TypeScript Type ****************************
#define TS_string "string"
#define TS_boolean "boolean"
#define TS_number "number"

// **************************** REGISTER_WIDGET_ARGUMENT_TYPE ****************************
#define REGISTER_WIDGET_ARGUMENT_TYPE__Text(EType)								Arguments.Add<FText>("Text", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__TextStyle(EType)							Arguments.Add<FTextBlockStyle>("TextStyle", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__ButtonStyle(EType)						Arguments.Add<FButtonStyle>("ButtonStyle", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__Font(EType)								Arguments.Add<FSlateFontInfo>("Font", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__StrikeBrush(EType)						Arguments.Add<FSlateBrush>("StrikeBrush", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__ColorAndOpacity(EType)					Arguments.Add<FLinearColor>("ColorAndOpacity", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__ShadowOffset(EType)						Arguments.Add<FVector2D>("ShadowOffset", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__ShadowColorAndOpacity(EType)				Arguments.Add<FLinearColor>("ShadowColorAndOpacity", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__HighlightColor(EType)					Arguments.Add<FLinearColor>("HighlightColor", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__HighlightShape(EType)					Arguments.Add<FSlateBrush>("HighlightShape", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__HighlightText(EType)						Arguments.Add<FText>("HighlightText", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__WrapTextAt(EType)						Arguments.Add<float>("WrapTextAt", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__AutoWrapText(EType)						Arguments.Add<bool>("AutoWrapText", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__WrappingPolicy(EType)					Arguments.Add<ETextWrappingPolicy>("WrappingPolicy", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__TransformPolicy(EType)					Arguments.Add<ETextTransformPolicy>("TransformPolicy", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__Margin(EType)							Arguments.Add<FMargin>("Margin", EType);
#define REGISTER_WIDGET_ARGUMENT_TYPE__Padding(EType)							Arguments.Add<FMargin>("Padding", EType);
#define REGISTER_WIDGET_ARGUMENT_TYPE__ContentPadding(EType)					Arguments.Add<FMargin>("ContentPadding", EType);
#define REGISTER_WIDGET_ARGUMENT_TYPE__LineHeightPercentage(EType)				Arguments.Add<float>("LineHeightPercentage", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__Justification(EType)						Arguments.Add<ETextJustify::Type>("Justification", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__MinDesiredWidth(EType)					Arguments.Add<float>("MinDesiredWidth", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__TextShapingMethod(EType)					Arguments.Add<ETextShapingMethod>("TextShapingMethod", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__TextFlowDirection(EType)					Arguments.Add<ETextFlowDirection>("TextFlowDirection", EType)
//#define REGISTER_WIDGET_ARGUMENT_TYPE__LineBreakPolicy(EType)					Arguments.Add<IBreakIterator>("LineBreakPolicy", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OverflowPolicy(EType)					Arguments.Add<ETextOverflowPolicy>("OverflowPolicy", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__SimpleTextMode(EType)					Arguments.Add<bool>("SimpleTextMode", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__HAlign(EType)							Arguments.Add<EHorizontalAlignment>("HAlign", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__VAlign(EType)							Arguments.Add<EVerticalAlignment>("VAlign", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__DesiredSizeScale(EType)					Arguments.Add<FVector2D>("DesiredSizeScale", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__ContentScale(EType)						Arguments.Add<FVector2D>("ContentScale", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__ButtonColorAndOpacity(EType)				Arguments.Add<FSlateColor>("ButtonColorAndOpacity", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__ClickMethod(EType)						Arguments.Add<EButtonClickMethod::Type>("ClickMethod", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__TouchMethod(EType)						Arguments.Add<EButtonTouchMethod::Type>("TouchMethod", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__PressMethod(EType)						Arguments.Add<EButtonPressMethod::Type>("PressMethod", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__ForegroundColor(EType)					Arguments.Add<FSlateColor>("ForegroundColor", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__IsFocusable(EType)						Arguments.Add<bool>("IsFocusable", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__PressedSoundOverride(EType)				Arguments.Add<FSlateSound>("PressedSoundOverride", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__HoveredSoundOverride(EType)				Arguments.Add<FSlateSound>("HoveredSoundOverride", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__BorderImage(EType)						Arguments.Add<FSlateBrush>("BorderImage", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__BorderBackgroundColor(EType)				Arguments.Add<FSlateColor>("BorderBackgroundColor", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__ShowEffectWhenDisabled(EType)			Arguments.Add<bool>("ShowEffectWhenDisabled", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__FlipForRightToLeftFlowDirection(EType)	Arguments.Add<bool>("FlipForRightToLeftFlowDirection", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__Style(EType)								Arguments.Add<FCheckBoxStyle>("Style", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__Type(EType)								Arguments.Add<ESlateCheckBoxType::Type>("Type", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__CheckBoxContentUsesAutoWidth(EType)		Arguments.Add<bool>("CheckBoxContentUsesAutoWidth", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__IsChecked(EType)							Arguments.Add<ECheckBoxState>("IsChecked", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__CheckedSoundOverride(EType)				Arguments.Add<FSlateBrush>("CheckedSoundOverride", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__UncheckedSoundOverride(EType)			Arguments.Add<FSlateBrush>("UncheckedSoundOverride", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__UncheckedImage(EType)					Arguments.Add<FSlateBrush>("UncheckedImage", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__UncheckedHoveredImage(EType)				Arguments.Add<FSlateBrush>("UncheckedHoveredImage", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__UncheckedPressedImage(EType)				Arguments.Add<FSlateBrush>("UncheckedPressedImage", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__CheckedImage(EType)						Arguments.Add<FSlateBrush>("CheckedImage", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__CheckedHoveredImage(EType)				Arguments.Add<FSlateBrush>("CheckedHoveredImage", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__CheckedPressedImage(EType)				Arguments.Add<FSlateBrush>("CheckedPressedImage", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__UndeterminedImage(EType)					Arguments.Add<FSlateBrush>("UndeterminedImage", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__UndeterminedHoveredImage(EType)			Arguments.Add<FSlateBrush>("UndeterminedHoveredImage", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__UndeterminedPressedImage(EType)			Arguments.Add<FSlateBrush>("UndeterminedPressedImage", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__BackgroundImage(EType)					Arguments.Add<FSlateBrush>("BackgroundImage", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__BackgroundHoveredImage(EType)			Arguments.Add<FSlateBrush>("BackgroundHoveredImage", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__BackgroundPressedImage(EType)			Arguments.Add<FSlateBrush>("BackgroundPressedImage", EType)

/** SLATE_DELEGATE **/
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnClicked(EType)							Arguments.Add<FOnClicked>("OnClicked", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnDoubleClicked(EType)					Arguments.Add<FPointerEventHandler>("OnDoubleClicked", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnPressed(EType)							Arguments.Add<FSimpleDelegate>("OnPressed", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnReleased(EType)						Arguments.Add<FSimpleDelegate>("OnReleased", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnHovered(EType)							Arguments.Add<FSimpleDelegate>("OnHovered", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnUnhovered(EType)						Arguments.Add<FSimpleDelegate>("OnUnhovered", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnMouseButtonDown(EType)					Arguments.Add<FPointerEventHandler>("OnMouseButtonDown", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnMouseButtonUp(EType)					Arguments.Add<FPointerEventHandler>("OnMouseButtonUp", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnMouseMove(EType)						Arguments.Add<FPointerEventHandler>("OnMouseMove", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnMouseDoubleClick(EType)				Arguments.Add<FPointerEventHandler>("OnMouseDoubleClick", EType)
// @TODO
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnCheckStateChanged(EType)				Arguments.Add<FPointerEventHandler>("OnCheckStateChanged", EType)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnGetMenuContent(EType)					Arguments.Add<FPointerEventHandler>("OnGetMenuContent", EType)

namespace WidgetStatic
{
	//template<typename T> static void $SNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { }
	//template<typename T> static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info) { return MakeShared<T>(); }
	//template<typename T> static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) {
	//	ExposeAs = $SNew(JsObject, Filename);
	//}
}

struct FWidgetFunctions
{

	TMap<FString, FString> Functions;
};



enum ESlateArgumentType
{
	SLATE_ATTRIBUTE,
	SLATE_ARGUMENT,
	SLATE_STYLE_ARGUMENT,
	SLATE_EVENT,
};