//#include "ScriptBackend.hpp"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBorder.h"
#include "Binding.hpp"
#include "UEDataBinding.hpp"
#include "Widgets/SlateControlledConstruction.h"

UsingCppType(TAttribute<FText>);
UsingCppType(TAttribute<FMargin>);

//UsingCppType(FMargin);

UsingCppType(FSlateWidgetClassData);


UsingCppType(FSlateControlledConstruction);
UsingCppType(SWidget);
UsingTSharedPtr(SWidget);

UsingCppType(SCompoundWidget);
UsingTSharedPtr(SCompoundWidget);

UsingCppType(SBorder);
UsingTSharedPtr(SBorder);

UsingCppType(SButton);
UsingTSharedPtr(SButton);


UsingCppType(SLeafWidget);
UsingTSharedPtr(SLeafWidget);

UsingCppType(STextBlock);
UsingTSharedPtr(STextBlock);

UsingUStruct(FMargin);
UsingTSharedPtr(FVector);


//UsingCppType(TSharedPtr<STextBlock>);
//namespace puerts {
//	template <> struct ScriptTypeName<TSharedPtr<STextBlock>> {
//		static constexpr auto value() {
//			return Literal("TSharedPtr<STextBlock>");
//		}
//	};
//} namespace puerts {
//	//template <> struct is_objecttype<TSharedPtr<STextBlock>> : public std::true_type { };
//} namespace puerts {
//	namespace converter {
//		template <> struct Converter<TSharedPtr<STextBlock>*> {
//			static v8::Local<v8::Value> toScript(v8::Local<v8::Context> context, TSharedPtr<STextBlock>* value) {
//				return ::puerts::DataTransfer::FindOrAddCData(context->GetIsolate(), context, puerts::DynamicTypeId<TSharedPtr<STextBlock>>::get(value), value, true);
//			} static TSharedPtr<STextBlock>* toCpp(v8::Local<v8::Context> context, const v8::Local<v8::Value>& value) {
//				return ::puerts::DataTransfer::GetPointerFast<TSharedPtr<STextBlock>>(value.As<v8::Object>());
//			} static bool accept(v8::Local<v8::Context> context, const v8::Local<v8::Value>& value) {
//				return ::puerts::DataTransfer::IsInstanceOf<TSharedPtr<STextBlock>>(context->GetIsolate(), value->ToObject(context).ToLocalChecked());
//			}
//		};
//	}
//};


struct STextBlockExtension
{
	static void SetText(const TSharedPtr<STextBlock> TextBlock, const FText Text)
	{
		if (TextBlock.IsValid())
		{
			TextBlock->SetText(Text);
		}
	}
};

//class FAttribute { FAttribute(); };
//UsingCppType(FAttribute);


struct AutoRegisterForSlate
{
	AutoRegisterForSlate()
	{
		//puerts::DefineClass<FAttribute>()
		//	.Register();

		puerts::DefineClass<TAttribute<FText>>()
			.Constructor()
			.Register();
		//puerts::DefineClass<TAttribute<FMargin>>()
		//	.Register();



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

		puerts::DefineClass<SCompoundWidget>()
			.Extends<SWidget>()
			.Register();

		puerts::DefineClass<SBorder>()
			.Extends<SCompoundWidget>()
			.Register();

		puerts::DefineClass<SButton>()
			.Extends<SBorder>()
			//.Property("OnClicked", MakeProperty(&SButton::OnClicked))
			//.Method("SetOnClicked", MakeFunction(&SButton::SetOnClicked))
			.Register();

		puerts::DefineClass<SLeafWidget>()
			.Extends<SWidget>()
			.Register();

		puerts::DefineClass<STextBlock>()
			.Extends<SLeafWidget>()
			.Method("GetText", MakeFunction(&STextBlock::GetText))
			.Method("SetText", MakeFunction(&STextBlock::SetText))
			.Method("SetMargin", MakeFunction(&STextBlock::SetMargin))
			//.Method("SetText", MakeExtension(&STextBlockExtension::SetText))
			.Register();

		RegisterTSharedPtr(STextBlock);
		//RegisterTSharedPtr(FVector);
	}
};
