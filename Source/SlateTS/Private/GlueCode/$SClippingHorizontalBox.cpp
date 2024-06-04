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
//#include "../Private/Framework/MultiBox/SClippingHorizontalBox.h"
//
//UsingCppType(SClippingHorizontalBox);
//UsingTSharedPtr(SClippingHorizontalBox);
//
//namespace $SClippingHorizontalBox
//{
//	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SClippingHorizontalBox::FArguments& Arguments)
//	{
//		if (!Info[ArgumentsIndex]->IsObject()) return;
//
//		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
//		$SLATE_ARGUMENT(OnWrapButtonClicked);
//		$SLATE_ARGUMENT(StyleSet);
//		$SLATE_ARGUMENT(StyleName);
//		$SLATE_ARGUMENT(IsFocusable);
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
//		SClippingHorizontalBox::FArguments Arguments;
//		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);
//
//		FString Filename;
//		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));
//
//		TSharedPtr<SClippingHorizontalBox> Widget = MakeTDecl<SClippingHorizontalBox>("SClippingHorizontalBox", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
//		if (InfoLength == 2)
//		{
//			auto V8Result = puerts::converter::Converter<TSharedPtr<SClippingHorizontalBox>>::toScript(Context, Widget);
//			Info.GetReturnValue().Set(V8Result); return;
//		}
//
//		if (InfoLength == 3)
//		{
//			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
//			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
//				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SClippingHorizontalBox>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
//			{
//				TSharedPtr<SClippingHorizontalBox>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SClippingHorizontalBox>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
//				*Arg1 = Widget; return;
//			}
//		}
//	}
//	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
//	{
//		v8::Isolate* Isolate = Info.GetIsolate();
//		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
//
//		TSharedPtr<SClippingHorizontalBox> Widget = MakeShared<SClippingHorizontalBox>();
//		auto V8Result = puerts::converter::Converter<TSharedPtr<SClippingHorizontalBox>>::toScript(Context, Widget);
//		Info.GetReturnValue().Set(V8Result);
//	}
//	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
//}
//
//struct AutoRegister_SClippingHorizontalBox
//{
//	DTS::DTSArguments RegisterArguments()
//	{
//		DTS::DTSArguments Args = DTS::DTSArguments("SClippingHorizontalBox");
//		Args.Add<FOnGetContent>("OnWrapButtonClicked", DTS::EArgType::SLATE_ARGUMENT);
//		Args.Add<const ISlateStyle*>("StyleSet", DTS::EArgType::SLATE_ARGUMENT);
//		Args.Add<FName>("StyleName", DTS::EArgType::SLATE_ARGUMENT);
//		Args.Add<bool>("IsFocusable", DTS::EArgType::SLATE_ARGUMENT);
//		return Args;
//	}
//
//	void GenDTS()
//	{
//		DTS::Class ClassDTS = DTS::Class().Name("SClippingHorizontalBox").Super("SHorizontalBox")
//			.Arguments(RegisterArguments())
//			.Functions(DTS::Array<DTS::Function>()
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("SNew").Static(true)
//						.Parameters(DTS::Array<DTS::Property>()
//							+ DTS::Property().Name("Arguments").Type("SClippingHorizontalBox.Arguments")
//							+ DTS::Property().Name("Filename").Type(TS_string)
//						)
//						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SClippingHorizontalBox>>::value().Data()))
//				]
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("SAssignNew").Static(true)
//						.Parameters(DTS::Array<DTS::Property>()
//							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SClippingHorizontalBox>>::value().Data()).Out(true)
//							+ DTS::Property().Name("Arguments").Type("SClippingHorizontalBox.Arguments")
//							+ DTS::Property().Name("Filename").Type(TS_string)
//						)
//				]
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("MakeShared").Static(true)
//						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SClippingHorizontalBox>>::value().Data()))
//				]
//			);
//
//		DTS::FClassDTS::Add(ClassDTS);
//	}
//
//	AutoRegister_SClippingHorizontalBox()
//	{
//		GenDTS();
//		RegisterTSharedPtr(SClippingHorizontalBox);
//
//		puerts::JSClassDefinition Def = JSClassEmptyDefinition;
//
//		static puerts::JSFunctionInfo Methods[] =
//		{
//			{0, 0}
//		};
//		static puerts::JSFunctionInfo Functions[] =
//		{
//			{"SNew", $SClippingHorizontalBox::$SNew},
//			{"SAssignNew", $SClippingHorizontalBox::$SAssignNew},
//			{"MakeShared", $SClippingHorizontalBox::$MakeShared},
//			{0, 0}
//		};
//
//		Def.ScriptName = "SClippingHorizontalBox";
//		Def.TypeId = puerts::StaticTypeId<SClippingHorizontalBox>::get();
//		Def.SuperTypeId = puerts::StaticTypeId<SHorizontalBox>::get();
//		Def.Methods = Methods;
//		Def.Functions = Functions;
//
//		puerts::RegisterJSClass(Def);
//	}
//};
//
//AutoRegister_SClippingHorizontalBox _AutoRegister_SClippingHorizontalBox;