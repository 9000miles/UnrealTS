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
#define CALL_SET_ATTRIBUTE_FUNCTION(FunctionName, Type)\
void $##FunctionName(FJsObject JsObject) { FunctionName(WidgetAttribute2::MakeAttribute<Type>(JsObject)); }
#define CALL_SET_OPTIONAL_FUNCTION(FunctionName, Type)\
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
#define REGISTER_WIDGET_ARGUMENT_TYPE__Text(Type)								Arguments.Add("Text", TS_string, Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__TextStyle(Type)							Arguments.Add("TextStyle", "UE.TextBlockStyle", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__ButtonStyle(Type)						Arguments.Add("ButtonStyle", "UE.ButtonStyle", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__Font(Type)								Arguments.Add("Font", "UE.SlateFontInfo", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__StrikeBrush(Type)						Arguments.Add("StrikeBrush", "UE.SlateBrush", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__ColorAndOpacity(Type)					Arguments.Add("ColorAndOpacity", "UE.LinearColor", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__ShadowOffset(Type)						Arguments.Add("ShadowOffset", "UE.Vector2D", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__ShadowColorAndOpacity(Type)				Arguments.Add("ShadowColorAndOpacity", "UE.LinearColor", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__HighlightColor(Type)						Arguments.Add("HighlightColor", "UE.LinearColor", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__HighlightShape(Type)						Arguments.Add("HighlightShape", "UE.SlateBrush", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__HighlightText(Type)						Arguments.Add("HighlightText", TS_string, Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__WrapTextAt(Type)							Arguments.Add("WrapTextAt", TS_number, Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__AutoWrapText(Type)						Arguments.Add("AutoWrapText", TS_boolean, Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__WrappingPolicy(Type)						Arguments.Add("WrappingPolicy", "UE.ETextWrappingPolicy", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__TransformPolicy(Type)					Arguments.Add("TransformPolicy", "UE.ETextTransformPolicy", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__Margin(Type)								Arguments.Add("Margin", "UE.Margin", Type);
#define REGISTER_WIDGET_ARGUMENT_TYPE__Padding(Type)							Arguments.Add("Padding", "UE.Margin", Type);
#define REGISTER_WIDGET_ARGUMENT_TYPE__ContentPadding(Type)						Arguments.Add("ContentPadding", "UE.Margin", Type);
#define REGISTER_WIDGET_ARGUMENT_TYPE__LineHeightPercentage(Type)				Arguments.Add("LineHeightPercentage", TS_number, Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__Justification(Type)						Arguments.Add("Justification", "UE.ETextJustify", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__MinDesiredWidth(Type)					Arguments.Add("MinDesiredWidth", TS_number, Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__TextShapingMethod(Type)					Arguments.Add("TextShapingMethod", "UE.ETextShapingMethod", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__TextFlowDirection(Type)					Arguments.Add("TextFlowDirection", "UE.ETextFlowDirection", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__LineBreakPolicy(Type)					Arguments.Add("LineBreakPolicy", "cpp.IBreakIterator", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OverflowPolicy(Type)						Arguments.Add("OverflowPolicy", "UE.ETextOverflowPolicy", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__SimpleTextMode(Type)						Arguments.Add("SimpleTextMode", TS_boolean, Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__HAlign(Type)								Arguments.Add("HAlign", "UE.EHorizontalAlignment", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__VAlign(Type)								Arguments.Add("VAlign", "UE.EVerticalAlignment", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__DesiredSizeScale(Type)					Arguments.Add("DesiredSizeScale", "UE.Vector2D", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__ContentScale(Type)						Arguments.Add("ContentScale", "UE.Vector2D", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__ButtonColorAndOpacity(Type)				Arguments.Add("ButtonColorAndOpacity", "UE.SlateColor", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__ClickMethod(Type)						Arguments.Add("ClickMethod", "UE.EButtonClickMethod", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__TouchMethod(Type)						Arguments.Add("TouchMethod", "UE.EButtonTouchMethod", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__PressMethod(Type)						Arguments.Add("PressMethod", "UE.EButtonPressMethod", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__ForegroundColor(Type)					Arguments.Add("ForegroundColor", "UE.SlateColor", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__IsFocusable(Type)						Arguments.Add("IsFocusable", TS_boolean, Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__PressedSoundOverride(Type)				Arguments.Add("PressedSoundOverride", "UE.SlateSound", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__HoveredSoundOverride(Type)				Arguments.Add("HoveredSoundOverride", "UE.SlateSound", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__BorderImage(Type)						Arguments.Add("BorderImage", "UE.SlateBrush", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__BorderBackgroundColor(Type)				Arguments.Add("BorderBackgroundColor", "UE.SlateColor", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__ShowEffectWhenDisabled(Type)				Arguments.Add("ShowEffectWhenDisabled", TS_boolean, Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__FlipForRightToLeftFlowDirection(Type)	Arguments.Add("FlipForRightToLeftFlowDirection", TS_boolean, Type)

/** SLATE_DELEGATE **/
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnClicked(Type)							Arguments.Add("OnClicked", "() => cpp.FReply", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnDoubleClicked(Type)					Arguments.Add("OnDoubleClicked", "() => cpp.FReply", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnPressed(Type)							Arguments.Add("OnPressed", "() => void", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnReleased(Type)							Arguments.Add("OnReleased", "() => void", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnHovered(Type)							Arguments.Add("OnHovered", "() => void", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnUnhovered(Type)						Arguments.Add("OnUnhovered", "() => void", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnMouseButtonDown(Type)					Arguments.Add("OnMouseButtonDown", "(Geometry: UE.Geometry, PointerEvent: UE.PointerEvent) => cpp.FReply", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnMouseButtonUp(Type)					Arguments.Add("OnMouseButtonUp", "(Geometry: UE.Geometry, PointerEvent: UE.PointerEvent) => cpp.FReply", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnMouseMove(Type)						Arguments.Add("OnMouseMove", "(Geometry: UE.Geometry, PointerEvent: UE.PointerEvent) => cpp.FReply", Type)
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnMouseDoubleClick(Type)					Arguments.Add("OnMouseDoubleClick", "(Geometry: UE.Geometry, PointerEvent: UE.PointerEvent) => cpp.FReply", Type)