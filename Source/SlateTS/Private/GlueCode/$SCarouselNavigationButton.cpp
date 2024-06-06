//#pragma once
//
//#include "CoreMinimal.h"
//#include "JsObject.h"
//#include "Binding.hpp"
//#include "DTSDefine.h"
//#include "TypeInfo.hpp"
//#include "UEDataBinding.hpp"
//#include "Helper/WidgetHelper.hpp"
//#include "DTSHelper.h"
//#include "DTSDefine.h"
//#include "PuertsEx.h"
//#include "SCarouselNavigationButton.h"
//
//UsingCppType(SCarouselNavigationButton);
//UsingTSharedPtr(SCarouselNavigationButton);
//
//namespace $SCarouselNavigationButton
//{
//	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SCarouselNavigationButton::FArguments& Arguments)
//	{
//		if (!Info[ArgumentsIndex]->IsObject()) return;
//
//		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
//		//$SLATE_EVENT(FOnBeginPeek, OnBeginPeek, );
//		//$SLATE_EVENT(FOnEndPeek, OnEndPeek, );
//		$SLATE_ARGUMENT(EHorizontalAlignment, HAlign, );
//		$SLATE_ARGUMENT(EVerticalAlignment, VAlign, );
//		$SLATE_ATTRIBUTE(FMargin, Padding, );
//		$SLATE_DEFAULT_SLOT(FArguments, Content, );
//	}
//
//	static void $SNew(const v8::FunctionCallbackInfo<v8::Value>& Info)
//	{
//		v8::Isolate* Isolate = Info.GetIsolate();
//		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
//		const uint8 InfoLength = Info.Length();
//		if (InfoLength <= 1) { puerts::DataTransfer::ThrowException(Isolate, "Invalid argument!"); return; }
//
//		uint8 ExposeIndex = InfoLength == 3 ? 0 : -1;
//		uint8 ArgumentsIndex = InfoLength == 3 ? 1 : 0;
//		uint8 FilenameIndex = InfoLength == 3 ? 2 : 1;
//
//		SCarouselNavigationButton::FArguments Arguments;
//		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);
//
//		FString Filename;
//		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));
//
//		TSharedPtr<SCarouselNavigationButton> Widget = MakeTDecl<SCarouselNavigationButton>("SCarouselNavigationButton", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
//		if (InfoLength == 2)
//		{
//			auto V8Result = puerts::converter::Converter<TSharedPtr<SCarouselNavigationButton>>::toScript(Context, Widget);
//			Info.GetReturnValue().Set(V8Result); return;
//		}
//
//		if (InfoLength == 3)
//		{
//			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
//			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
//				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SCarouselNavigationButton>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
//			{
//				TSharedPtr<SCarouselNavigationButton>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SCarouselNavigationButton>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
//				*Arg1 = Widget; return;
//			}
//		}
//	}
//	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
//	{
//		v8::Isolate* Isolate = Info.GetIsolate();
//		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
//
//		TSharedPtr<SCarouselNavigationButton> Widget = MakeShared<SCarouselNavigationButton>();
//		auto V8Result = puerts::converter::Converter<TSharedPtr<SCarouselNavigationButton>>::toScript(Context, Widget);
//		Info.GetReturnValue().Set(V8Result);
//	}
//	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
//}
//
//struct AutoRegister_SCarouselNavigationButton
//{
//	DTS::DTSArguments RegisterArguments()
//	{
//		DTS::DTSArguments Args = DTS::DTSArguments("SCarouselNavigationButton");
//		Args.Add<SCarouselNavigationButton::FOnBeginPeek>("OnBeginPeek", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FOnEndPeek>("OnEndPeek", DTS::EArgType::SLATE_EVENT);
//		Args.Add<EHorizontalAlignment>("HAlign", DTS::EArgType::SLATE_ARGUMENT);
//		Args.Add<EVerticalAlignment>("VAlign", DTS::EArgType::SLATE_ARGUMENT);
//		Args.Add<FMargin>("Padding", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<FArguments>("Content", DTS::EArgType::SLATE_DEFAULT_SLOT);
//		return Args;
//	}
//
//	void GenDTS()
//	{
//		DTS::Class ClassDTS = DTS::Class().Name("SCarouselNavigationButton").Super("SCompoundWidget")
//			.Arguments(RegisterArguments())
//			.Functions(DTS::Array<DTS::Function>()
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("SNew").Static(true)
//						.Parameters(DTS::Array<DTS::Property>()
//							+ DTS::Property().Name("Arguments").Type("SCarouselNavigationButton.Arguments")
//							+ DTS::Property().Name("Filename").Type(TS_string)
//						)
//						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SCarouselNavigationButton>>::value().Data()))
//				]
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("SAssignNew").Static(true)
//						.Parameters(DTS::Array<DTS::Property>()
//							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SCarouselNavigationButton>>::value().Data()).Out(true)
//							+ DTS::Property().Name("Arguments").Type("SCarouselNavigationButton.Arguments")
//							+ DTS::Property().Name("Filename").Type(TS_string)
//						)
//				]
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("MakeShared").Static(true)
//						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SCarouselNavigationButton>>::value().Data()))
//				]
//			);
//
//		DTS::FClassDTS::Add(ClassDTS);
//	}
//
//	AutoRegister_SCarouselNavigationButton()
//	{
//		GenDTS();
//		RegisterTSharedPtr(SCarouselNavigationButton);
//
//		puerts::JSClassDefinition Def = JSClassEmptyDefinition;
//
//		static puerts::JSFunctionInfo Methods[] =
//		{
//			{0, 0}
//		};
//		static puerts::JSFunctionInfo Functions[] =
//		{
//			{"SNew", $SCarouselNavigationButton::$SNew},
//			{"SAssignNew", $SCarouselNavigationButton::$SAssignNew},
//			{"MakeShared", $SCarouselNavigationButton::$MakeShared},
//			{0, 0}
//		};
//
//		Def.ScriptName = "SCarouselNavigationButton";
//		Def.TypeId = puerts::StaticTypeId<SCarouselNavigationButton>::get();
//		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
//		Def.Methods = Methods;
//		Def.Functions = Functions;
//
//		puerts::RegisterJSClass(Def);
//	}
//};
//
//AutoRegister_SCarouselNavigationButton _AutoRegister_SCarouselNavigationButton;