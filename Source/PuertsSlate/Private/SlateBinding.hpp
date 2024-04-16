//#include "ScriptBackend.hpp"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBorder.h"
#include "Binding.hpp"
#include "UEDataBinding.hpp"
#include "Widgets/SlateControlledConstruction.h"
#include "JsObject.h"
#include "V8Converter.hpp"
#include "Object.hpp"
#include "V8Utils.h"

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
UsingCppType(STextBlock::FArguments);

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
struct SButtonExtension
{
	static FName WidgetType;
	static TSharedPtr<SButton> Create(FJsObject Arguments)
	{
		//auto Arguments = Object.Get<FJsObject>("args");

		auto ClickFunc = Arguments.Get< std::function<void()>>("OnClicked");
		FString  Text = FString(Arguments.Get<std::string>("Text").c_str());

		return SNew(SButton)
			.Text(FText::FromString(Text))
			.OnClicked_Lambda([ClickFunc]() {ClickFunc(); return FReply::Handled(); })
			;
	}
};

__declspec(selectany) FName SButtonExtension::WidgetType = "SButton";

struct STextBlockExtension
{
	static FName WidgetType;
	static TSharedPtr<STextBlock> Create(/*CallbackInfoType info, */FJsObject Arguments)
	{
		//v8::Isolate* Isolate = info.GetIsolate();
		//v8::Isolate::Scope IsolateScope(Isolate);
		//v8::HandleScope HandleScope(Isolate);
		//v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
		//v8::Context::Scope ContextScope(Context);

		//int xx = Object.Get<int>("xx");
		//std::string cp1 = Object.Get<std::string>("cp1");

		//auto Arguments = Object.Get<FJsObject>("args");
		FString  Text = FString(Arguments.Get<std::string>("Text").c_str());

		return
			SNew(STextBlock)
			.Text(FText::FromString(Text))
			;

		//info.GetReturnValue().Set(
		//	FV8Utils::IsolateData<IObjectMapper>(Isolate)->FindOrAddStruct(Isolate, Context, ScriptStruct, Ptr, false));

		//auto Arguments = Object.Get<FJsObject>("args");


	}
	static void SetText(const TSharedPtr<STextBlock> TextBlock, const FText Text)
	{

		if (TextBlock.IsValid())
		{
			TextBlock->SetText(Text);
		}

	}

	static void SetTextg(STextBlock TextBlock, const FText Text)
	{
		//if (TextBlock.IsValid())
		{
			//TextBlock->SetText(Text);
			TextBlock.SetText(Text);
		}
	}
};

struct SWidgetBuilder
{
	static TSharedPtr<STextBlock> Create(/*CallbackInfoType info, */std::string WidgetType, FJsObject Object)
	{
		if (WidgetType == "STextBlock")
			return STextBlockExtension::Create(Object);
		//else if (WidgetType == "SButton")
		//	return SButtonExtension::Create(Object);

		return nullptr;
	}
	static TSharedPtr<SButton> CreateButton(/*CallbackInfoType info, */std::string WidgetType, FJsObject Object)
	{
		//if (WidgetType == "STextBlock")
		//	return STextBlockExtension::Create(Object);
		if (WidgetType == "SButton")
			return SButtonExtension::Create(Object);

		return nullptr;
	}
};

UsingCppType(SWidgetBuilder);

struct AutoRegisterForSWidgetBuilder
{
	AutoRegisterForSWidgetBuilder()
	{
		//puerts::DefineClass<FAttribute>()
		//	.Register();

		puerts::DefineClass<SWidgetBuilder>()
			.Function("Create", MakeFunction(&SWidgetBuilder::Create))
			.Function("CreateButton", MakeFunction(&SWidgetBuilder::CreateButton))
			.Register();
	}
};
AutoRegisterForSWidgetBuilder __AutoRegisterForSWidgetBuilder;



__declspec(selectany) FName STextBlockExtension::WidgetType = TEXT("STextBlock");

//class FAttribute { FAttribute(); };
//UsingCppType(FAttribute);


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
		puerts::DefineClass<TType>()
			.Register();

		//TAttribute<TType> ff= TAttribute::Create<TType>();

		//puerts::DefineClass<TAttribute<TType>>()
			//.Constructor<TType>()
			//.Constructor(
			//	CombineConstructors(
			//		MakeConstructor(TAttribute<FText>, FText),
			//		MakeConstructor(TAttribute<FMargin>, FMargin)
			//	))
			//.Register();
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
			.Function("SNew", MakeFunction(&SButtonExtension::Create))
			//.Property("OnClicked", MakeProperty(&SButton::OnClicked))
			//.Method("SetOnClicked", MakeFunction(&SButton::SetOnClicked))
			.Variable("WidgetType", MakeReadonlyVariable(&SButtonExtension::WidgetType))
			.Register();

		puerts::DefineClass<SLeafWidget>()
			.Extends<SWidget>()
			.Register();

		puerts::DefineClass<STextBlock>()
			.Extends<SLeafWidget>()
			.Function("SNew", MakeFunction(&STextBlockExtension::Create))
			//.Function("SWidgetNew", MakeExtension(&SWidgetBuilder::New))
			//.Function(
			//	"SNew",
			//	[](::puerts::CallbackInfoType info)
			//	{
			//		::puerts::FuncCallWrapper<decltype(&STextBlockExtension::New), &STextBlockExtension::New>::callExtensionWithDefaultValues(info);
			//	},
			//	::puerts::FuncCallWrapper<decltype(&STextBlockExtension::New), &STextBlockExtension::New>::extensionInfo(puerts::Count())
			//)
			.Method("GetText", MakeFunction(&STextBlock::GetText))
			//.Method("SetText", MakeFunction(&STextBlock::SetText))
			.Method("SetMargin", MakeFunction(&STextBlock::SetMargin))
			//.Method("SetText", MakeFunction(&STextBlockExtension::SetText))
			.Method(
				"SetText",
				[](::puerts::CallbackInfoType info)
				{
					::puerts::FuncCallWrapper<decltype(&STextBlockExtension::SetText), &STextBlockExtension::SetText>::callExtensionWithDefaultValues(info);
				},
				::puerts::FuncCallWrapper<decltype(&STextBlockExtension::SetText), &STextBlockExtension::SetText>::extensionInfo(puerts::Count())
			)
			//.Method("SetText", MakeExtension(&STextBlockExtension::SetText))
			.Variable("WidgetType", MakeReadonlyVariable(&STextBlockExtension::WidgetType))
			.Register();

		auto sfs = SNew(STextBlock);
		TSharedPtr<STextBlock> bsso = SNew(STextBlock);

		//STextBlock::FArguments sfs = SNew(STextBlock);
		puerts::DefineClass<STextBlock::FArguments>()
			.Property("Text", MakeProperty(&STextBlock::FArguments::_Text))
			.Register();

		//RegisterTSharedPtr(STextBlock);
		//RegisterTSharedPtr(FVector);


	}
};
