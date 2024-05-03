#pragma once

// **************************** WIDGET_ARGUMENT_ENUM ****************************
#define _EHorizontalAlignment_ "\"Fill\" | \"Left\" | \"Center\"| \"Right\""
#define _EVerticalAlignment_ "\"Fill\" | \"Top\" | \"Center\" | \"Bottom\""

// **************************** CALL_SET_ATTRIBUTE_FUNCTION ****************************
#define CALL_SET_ATTRIBUTE_FUNCTION(Type, Name)\
if (FunctionName == #Name)\
{\
	TAttribute<Type> Parameter = WidgetAttribute2::MakeAttribute<Type>(JsObject);\
	Widget->##Name(Parameter);\
}

#define TS_FUNCTION_RET_ANY FString( " | (() => any)")
#define TS_ATTRIBUTE_TYPE_Vector2D FString("UE.Vector2D | {X: number, Y: number}") + TS_FUNCTION_RET_ANY
#define TS_ATTRIBUTE_TYPE_Vector3 FString("UE.Vector3 | {X: number, Y: number, Z: number}") + TS_FUNCTION_RET_ANY

// **************************** REGISTER_WIDGET_ARGUMENT_TYPE ****************************
#define REGISTER_WIDGET_ARGUMENT_TYPE__Text()\
Arguments.Add("Text", "string" + TS_FUNCTION_RET_ANY)
#define REGISTER_WIDGET_ARGUMENT_TYPE__TextStyle()\
Arguments.Add("TextStyle", "UE.TextBlockStyle")
#define REGISTER_WIDGET_ARGUMENT_TYPE__Font()\
Arguments.Add("Font", "UE.SlateFontInfo")
#define REGISTER_WIDGET_ARGUMENT_TYPE__StrikeBrush()\
Arguments.Add("StrikeBrush", "UE.SlateBrush")
#define REGISTER_WIDGET_ARGUMENT_TYPE__ColorAndOpacity()\
Arguments.Add("ColorAndOpacity", "string | UE.LinearColor | { R: number, G: number, B:number, A: number } | (() => any)")
#define REGISTER_WIDGET_ARGUMENT_TYPE__ShadowOffset()\
Arguments.Add("ShadowOffset", TS_ATTRIBUTE_TYPE_Vector2D)
#define REGISTER_WIDGET_ARGUMENT_TYPE__ShadowColorAndOpacity()\
Arguments.Add("ShadowColorAndOpacity", "UE.LinearColor")
#define REGISTER_WIDGET_ARGUMENT_TYPE__HighlightColor()\
Arguments.Add("HighlightColor", "UE.LinearColor")
#define REGISTER_WIDGET_ARGUMENT_TYPE__HighlightShape()\
Arguments.Add("HighlightShape", "UE.SlateBrush")
#define REGISTER_WIDGET_ARGUMENT_TYPE__HighlightText()\
Arguments.Add("HighlightText", "string" + TS_FUNCTION_RET_ANY)
#define REGISTER_WIDGET_ARGUMENT_TYPE__WrapTextAt()\
Arguments.Add("WrapTextAt", "number" + TS_FUNCTION_RET_ANY)
#define REGISTER_WIDGET_ARGUMENT_TYPE__AutoWrapText()\
Arguments.Add("AutoWrapText", "boolean" + TS_FUNCTION_RET_ANY)
#define REGISTER_WIDGET_ARGUMENT_TYPE__WrappingPolicy()\
Arguments.Add("WrappingPolicy", "UE.ETextWrappingPolicy")
#define REGISTER_WIDGET_ARGUMENT_TYPE__TransformPolicy()\
Arguments.Add("TransformPolicy", "UE.ETextTransformPolicy")
#define REGISTER_WIDGET_ARGUMENT_TYPE__Margin()\
Arguments.Add("Margin", "UE.Margin | number | { Horizontal: number, Vertical: number } | { Left: number, Top: number, Right: number, Buttom: number}");
#define REGISTER_WIDGET_ARGUMENT_TYPE__LineHeightPercentage()\
Arguments.Add("LineHeightPercentage", "number" + TS_FUNCTION_RET_ANY)
#define REGISTER_WIDGET_ARGUMENT_TYPE__Justification()\
Arguments.Add("Justification", "UE.ETextJustify")
#define REGISTER_WIDGET_ARGUMENT_TYPE__MinDesiredWidth()\
Arguments.Add("MinDesiredWidth", "number")
#define REGISTER_WIDGET_ARGUMENT_TYPE__TextShapingMethod()\
Arguments.Add("TextShapingMethod", "UE.ETextShapingMethod")
#define REGISTER_WIDGET_ARGUMENT_TYPE__TextFlowDirection()\
Arguments.Add("TextFlowDirection", "UE.ETextFlowDirection")
#define REGISTER_WIDGET_ARGUMENT_TYPE__LineBreakPolicy()\
Arguments.Add("LineBreakPolicy", "cpp.IBreakIterator")
#define REGISTER_WIDGET_ARGUMENT_TYPE__OverflowPolicy()\
Arguments.Add("OverflowPolicy", "UE.ETextOverflowPolicy")
#define REGISTER_WIDGET_ARGUMENT_TYPE__SimpleTextMode()\
Arguments.Add("SimpleTextMode", "boolean")
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnDoubleClicked()\
Arguments.Add("OnDoubleClicked", "() => void")