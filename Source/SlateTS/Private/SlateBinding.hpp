//#include "ScriptBackend.hpp"
#include "Input/Reply.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBorder.h"
#include "Binding.hpp"
#include "UEDataBinding.hpp"
#include "Widgets/SlateControlledConstruction.h"
#include "JsObject.h"
#include "V8Converter.hpp"
#include "Object.hpp"
#include "V8Utils.h"
#include "TemplateBindingGenerator.h"

#include "STextBlockBinding.hpp"
#include "SButtonBinding.hpp"
#include "SBorderBinding.hpp"
#include "SCheckBoxBinding.hpp"



UsingCppType(TAttribute<FText>);
UsingCppType(TAttribute<FMargin>);
UsingCppType(TAttribute<FVector2D>);

//UsingCppType(FMargin);

UsingCppType(FSlateWidgetClassData);


UsingCppType(FSlateControlledConstruction);
UsingCppType(SWidget);
UsingTSharedPtr(SWidget);
UsingTSharedRef(SWidget);

UsingCppType(SCompoundWidget);
UsingTSharedPtr(SCompoundWidget);

UsingCppType(SLeafWidget);
UsingTSharedPtr(SLeafWidget);

UsingTSharedPtr(FVector);

//UsingCppType(FReplyBase);
//UsingCppType(TReplyBase<FReply>);
UsingCppType(FReply);


class TType {
	TType() {}
	TType(const TType&) = default;
	TType(TType&&) = default;
	TType& operator=(const TType&) = default;
	TType& operator=(TType&&) = default;
};
UsingCppType(TType);

struct AutoRegisterForSlate
{
	AutoRegisterForSlate()
	{
		puerts::DefineClass<FReply>()
			//.Function("Handled", MakeFunction(&FReply::Handled))
			//.Function("Unhandled", MakeFunction(&FReply::Unhandled))
			.Register();

		puerts::DefineClass<FSlateWidgetClassData>()
			.Method("GetWidgetType", MakeFunction(&FSlateWidgetClassData::GetWidgetType))
			.Register();

		puerts::DefineClass<FSlateControlledConstruction>()
			//.Function("StaticWidgetClass", MakeFunction(&FSlateControlledConstruction::StaticWidgetClass))
			//.Method("GetWidgetClass", MakeFunction(&FSlateControlledConstruction::GetWidgetClass))
			.Register();

		puerts::DefineClass<SWidget>()
			.Extends<FSlateControlledConstruction>()
			//.Function("StaticWidgetClass", MakeFunction(&SWidget::StaticWidgetClass))
			//.Method("GetWidgetClass", MakeFunction(&SWidget::GetWidgetClass))
			.Register();
		RegisterTSharedPtr(SWidget);
		RegisterTSharedRef(SWidget);

		puerts::DefineClass<SCompoundWidget>()
			.Extends<SWidget>()
			.Register();

		puerts::DefineClass<SLeafWidget>()
			.Extends<SWidget>()
			.Register();
	}
};

AutoRegisterForSlate __AutoRegisterForSlate__;


namespace puerts
{
	template <> struct ScriptTypeName<FSlateColor> { static constexpr auto value() { return Literal("object"); } };
	template <> struct ScriptTypeName<const FSlateBrush*> { static constexpr auto value() { return Literal("object"); } };
	template <> struct ScriptTypeName<const FButtonStyle*> { static constexpr auto value() { return Literal("object"); } };

	namespace converter
	{
		//template <>
		//struct Converter<FSlateColor>
		//{
		//	static v8::Local<v8::Value> toScript(v8::Local<v8::Context> context, FJsObject value)
		//	{
		//		return value.GetJsObject();
		//	}

		//	static FSlateColor toCpp(v8::Local<v8::Context> context, const v8::Local<v8::Value>& value)
		//	{
		//		return FSlateColor();
		//		//return FSlateColor(context, value.As<v8::Object>());
		//	}

		//	static bool accept(v8::Local<v8::Context> context, const v8::Local<v8::Value>& value)
		//	{
		//		return value->IsObject();
		//	}
		//};
	}    // namespace converter
}    // namespace puerts