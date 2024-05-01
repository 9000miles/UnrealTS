#pragma once

// **************************** WIDGET_ARGUMENT_ENUM ****************************
#define _EHorizontalAlignment_ "\"Fill\" | \"Left\" | \"Center\"| \"Right\""
#define _EVerticalAlignment_ "\"Fill\" | \"Top\" | \"Center\" | \"Bottom\""

// **************************** CALL_SET_ATTRIBUTE_FUNCTION ****************************
#define CALL_SET_ATTRIBUTE_FUNCTION(Type, Name)\
if (FunctionName == #Name)\
{\
	TAttribute<Type> Parameter = WidgetFunctionCall::MakeAttribute<Type>(JsObject);\
	Widget->##Name(Parameter);\
}

// **************************** REGISTER_WIDGET_ARGUMENT_TYPE ****************************
#define REGISTER_WIDGET_ARGUMENT_TYPE__Text()\
Arg.Add("Text", "string | (() => any)")
#define REGISTER_WIDGET_ARGUMENT_TYPE__TextStyle()\
Arg.Add("TextStyle", "UE.TextBlockStyle")
#define REGISTER_WIDGET_ARGUMENT_TYPE__Font()\
Arg.Add("Font", "UE.SlateFontInfo")
#define REGISTER_WIDGET_ARGUMENT_TYPE__StrikeBrush()\
Arg.Add("StrikeBrush", "UE.SlateBrush")
#define REGISTER_WIDGET_ARGUMENT_TYPE__ColorAndOpacity()\
Arg.Add("ColorAndOpacity", "string | UE.LinearColor | { R: number, G: number, B:number, A: number } | (() => any)")
#define REGISTER_WIDGET_ARGUMENT_TYPE__ShadowOffset()\
Arg.Add("ShadowOffset", "UE.Vector2D")
#define REGISTER_WIDGET_ARGUMENT_TYPE__ShadowColorAndOpacity()\
Arg.Add("ShadowColorAndOpacity", "UE.LinearColor")
#define REGISTER_WIDGET_ARGUMENT_TYPE__HighlightColor()\
Arg.Add("HighlightColor", "UE.LinearColor")
#define REGISTER_WIDGET_ARGUMENT_TYPE__HighlightShape()\
Arg.Add("HighlightShape", "UE.SlateBrush")
#define REGISTER_WIDGET_ARGUMENT_TYPE__HighlightText()\
Arg.Add("HighlightText", "string")
#define REGISTER_WIDGET_ARGUMENT_TYPE__WrapTextAt()\
Arg.Add("WrapTextAt", "number")
#define REGISTER_WIDGET_ARGUMENT_TYPE__AutoWrapText()\
Arg.Add("AutoWrapText", "boolean")
#define REGISTER_WIDGET_ARGUMENT_TYPE__WrappingPolicy()\
Arg.Add("WrappingPolicy", "UE.ETextWrappingPolicy")
#define REGISTER_WIDGET_ARGUMENT_TYPE__TransformPolicy()\
Arg.Add("TransformPolicy", "UE.ETextTransformPolicy")
#define REGISTER_WIDGET_ARGUMENT_TYPE__Margin()\
Arg.Add("Margin", "UE.Margin | number | { Horizontal: number, Vertical: number } | { Left: number, Top: number, Right: number, Buttom: number}");
#define REGISTER_WIDGET_ARGUMENT_TYPE__LineHeightPercentage()\
Arg.Add("LineHeightPercentage", "number")
#define REGISTER_WIDGET_ARGUMENT_TYPE__Justification()\
Arg.Add("Justification", "UE.ETextJustify")
#define REGISTER_WIDGET_ARGUMENT_TYPE__MinDesiredWidth()\
Arg.Add("MinDesiredWidth", "number")
#define REGISTER_WIDGET_ARGUMENT_TYPE__TextShapingMethod()\
Arg.Add("TextShapingMethod", "UE.ETextShapingMethod")
#define REGISTER_WIDGET_ARGUMENT_TYPE__TextFlowDirection()\
Arg.Add("TextFlowDirection", "UE.ETextFlowDirection")
#define REGISTER_WIDGET_ARGUMENT_TYPE__LineBreakPolicy()\
Arg.Add("LineBreakPolicy", "cpp.IBreakIterator")
#define REGISTER_WIDGET_ARGUMENT_TYPE__OverflowPolicy()\
Arg.Add("OverflowPolicy", "UE.ETextOverflowPolicy")
#define REGISTER_WIDGET_ARGUMENT_TYPE__SimpleTextMode()\
Arg.Add("SimpleTextMode", "boolean")
#define REGISTER_WIDGET_ARGUMENT_TYPE__OnDoubleClicked()\
Arg.Add("OnDoubleClicked", "() => void")