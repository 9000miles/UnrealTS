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
#include "TemplateBindingGenerator.h"

UsingCppType(TAttribute<FText>);
UsingCppType(TAttribute<FMargin>);
UsingCppType(TAttribute<FVector2D>);

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
//UsingCppType(STextBlock::FArguments);

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


const FString TS_String = "string";
const FString TS_Boolean = "boolean";
const FString TS_Number = "number";

#define ADD_ARGUMENT(Name, Type) Arguments.Add(#Name, #Type)
#define ADD_ARGUMENT_MUST_FILL(Name, Type) Arguments.Add(#Name, #Type, false)

#define UsingWidgetArgumentsType(Name) UsingNamedCppType(##Name##::FArguments, ##Name##_FArguments);

UsingWidgetArgumentsType(STextBlock);

struct STextBlockExtension
{
	STextBlockExtension()
	{
		FWidgetArguments Arguments;
		//Arguments.Add("Text", TS_String);
		ADD_ARGUMENT(Text, string);
		ADD_ARGUMENT(ColorAndOpacity, cpp.SlateColor);
		ADD_ARGUMENT(Margin, UE.Margin);
		UTemplateBindingGenerator::AllWidget().Add("STextBlock", Arguments);

		//puerts::DefineClass<STextBlock::FArguments>()
		//	.Property("Text", MakeProperty(&STextBlock::FArguments::_Text))
		//	//.Property("ColorAndOpacity", MakeProperty(&STextBlock::FArguments::_ColorAndOpacity))
		//	.Property("ShadowOffset", MakeProperty(&STextBlock::FArguments::_ShadowOffset))
		//	.Register();
	}


	static TSharedPtr<STextBlock> CreateBySNew(/*CallbackInfoType info, */FJsObject Arguments, FString Filename = "")
	{
		//v8::Isolate* Isolate = info.GetIsolate();
		//v8::Isolate::Scope IsolateScope(Isolate);
		//v8::HandleScope HandleScope(Isolate);
		//v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
		//v8::Context::Scope ContextScope(Context);

		//int xx = Object.Get<int>("xx");
		//std::string cp1 = Object.Get<std::string>("cp1");

		//auto Arguments = Object.Get<FJsObject>("args");
		//@TODO 需要增加判断是否有属性
		FString Text = FString(Arguments.Get<std::string>("Text").c_str());
		FSlateColor ColorAndOpacity = Arguments.Get<FSlateColor>("ColorAndOpacity");

		return
			//SNew(STextBlock)
			MakeTDecl<STextBlock>("STextBlock", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs())
			<<= STextBlock::FArguments()
			.Text(FText::FromString(Text))
			.ColorAndOpacity(ColorAndOpacity)
			;

		//info.GetReturnValue().Set(
		//	FV8Utils::IsolateData<IObjectMapper>(Isolate)->FindOrAddStruct(Isolate, Context, ScriptStruct, Ptr, false));

		//auto Arguments = Object.Get<FJsObject>("args");


	}
	static void CreateBySAssignNew(TSharedPtr<STextBlock> ExposeAs, FJsObject Arguments, FString Filename = "")
	{
		MakeTDecl<STextBlock>("STextBlock", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()).Expose(ExposeAs)
			<<= STextBlock::FArguments()
			.Text(FText())
			;
	}
	static void SetText(const TSharedPtr<STextBlock> TextBlock, const FText Text)
	{

		if (TextBlock.IsValid())
		{
			TextBlock->SetText(Text);
		}

	}
};

STextBlockExtension __STextBlockExtension;



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
			.Register();

		puerts::DefineClass<SLeafWidget>()
			.Extends<SWidget>()
			.Register();

		puerts::DefineClass<STextBlock>()
			.Extends<SLeafWidget>()
			.Function("SNew", MakeFunction(&STextBlockExtension::CreateBySNew))
			//.Function("SNew", [](::puerts::CallbackInfoType info) { ::puerts::FuncCallWrapper<decltype(&STextBlockExtension::CreateBySNew), &STextBlockExtension::CreateBySNew>::callWithDefaultValues(info, FJsObject(), ""); }, ::puerts::FuncCallWrapper<decltype(&STextBlockExtension::CreateBySNew), &STextBlockExtension::CreateBySNew>::info(puerts::Count(FJsObject(), "")))
			.Function("SAssignNew", MakeFunction(&STextBlockExtension::CreateBySAssignNew))
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
			//不能直接传string，需要TAtrribute
			//.Method("SetText", MakeFunction(&STextBlock::SetText))
			.Method("SetMargin", MakeFunction(&STextBlock::SetMargin))
			//扩展函数self传递有问题
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
			.Register();


		//STextBlock::FArguments sfs = SNew(STextBlock);
		//puerts::DefineClass<STextBlock::FArguments>()
		//	.Property("Text", MakeProperty(&STextBlock::FArguments::_Text))
		//	.Register();

		RegisterTSharedPtr(STextBlock);
		//RegisterTSharedPtr(FVector);


	}
};
