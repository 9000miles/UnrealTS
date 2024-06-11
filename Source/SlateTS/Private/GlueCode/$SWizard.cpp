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
//#include "AppFramework/Public/Widgets/Workflow/SWizard.h"
//
//UsingCppType(SWizard);
//UsingTSharedPtr(SWizard);
//
//namespace $SWizard
//{
//	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SWizard::FArguments& Arguments)
//	{
//		if (!Info[ArgumentsIndex]->IsObject()) return;
//
//		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
//		$SLATE_NAMED_SLOT(FArguments, ButtonContent, );
//		$SLATE_ATTRIBUTE(FText, Name, );
//		$SLATE_ATTRIBUTE(bool, CanShow, );
//		//$SLATE_EVENT(FSimpleDelegate, OnEnter, );
//		//$SLATE_EVENT(FSimpleDelegate, OnLeave, );
//		$SLATE_DEFAULT_SLOT(FArguments, PageContent, );
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
//		SWizard::FArguments Arguments;
//		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);
//
//		FString Filename;
//		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));
//
//		TSharedPtr<SWizard> Widget = MakeTDecl<SWizard>("SWizard", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
//		if (InfoLength == 2)
//		{
//			auto V8Result = puerts::converter::Converter<TSharedPtr<SWizard>>::toScript(Context, Widget);
//			Info.GetReturnValue().Set(V8Result); return;
//		}
//
//		if (InfoLength == 3)
//		{
//			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
//			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
//				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SWizard>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
//			{
//				TSharedPtr<SWizard>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SWizard>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
//				*Arg1 = Widget; return;
//			}
//		}
//	}
//	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
//	{
//		v8::Isolate* Isolate = Info.GetIsolate();
//		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
//
//		TSharedPtr<SWizard> Widget = MakeShared<SWizard>();
//		auto V8Result = puerts::converter::Converter<TSharedPtr<SWizard>>::toScript(Context, Widget);
//		Info.GetReturnValue().Set(V8Result);
//	}
//	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
//}
//
//struct AutoRegister_SWizard
//{
//	DTS::DTSArguments RegisterArguments()
//	{
//		DTS::DTSArguments Args = DTS::DTSArguments("SWizard");
//		Args.Add<FArguments>("ButtonContent", DTS::EArgType::SLATE_NAMED_SLOT);
//		Args.Add<FText>("Name", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<bool>("CanShow", DTS::EArgType::SLATE_ATTRIBUTE);
//		Args.Add<FSimpleDelegate>("OnEnter", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FSimpleDelegate>("OnLeave", DTS::EArgType::SLATE_EVENT);
//		Args.Add<FArguments>("PageContent", DTS::EArgType::SLATE_DEFAULT_SLOT);
//		return Args;
//	}
//
//	void GenDTS()
//	{
//		DTS::Class ClassDTS = DTS::Class().Name("SWizard").Super("SCompoundWidget")
//			.Arguments(RegisterArguments())
//			.Functions(DTS::Array<DTS::Function>()
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("SNew").Static(true)
//						.Parameters(DTS::Array<DTS::Property>()
//							+ DTS::Property().Name("Arguments").Type("SWizard.Arguments")
//							+ DTS::Property().Name("Filename").Type(TS_string)
//						)
//						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SWizard>>::value().Data()))
//				]
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("SAssignNew").Static(true)
//						.Parameters(DTS::Array<DTS::Property>()
//							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SWizard>>::value().Data()).Out(true)
//							+ DTS::Property().Name("Arguments").Type("SWizard.Arguments")
//							+ DTS::Property().Name("Filename").Type(TS_string)
//						)
//				]
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("MakeShared").Static(true)
//						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SWizard>>::value().Data()))
//				]
//			);
//
//		DTS::FClassDTS::Add(ClassDTS);
//	}
//
//	AutoRegister_SWizard()
//	{
//		GenDTS();
//		RegisterTSharedPtr(SWizard);
//
//		puerts::JSClassDefinition Def = JSClassEmptyDefinition;
//
//		static puerts::JSFunctionInfo Methods[] =
//		{
//			{0, 0}
//		};
//		static puerts::JSFunctionInfo Functions[] =
//		{
//			{"SNew", $SWizard::$SNew},
//			{"SAssignNew", $SWizard::$SAssignNew},
//			{"MakeShared", $SWizard::$MakeShared},
//			{0, 0}
//		};
//
//		Def.ScriptName = "SWizard";
//		Def.TypeId = puerts::StaticTypeId<SWizard>::get();
//		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
//		Def.Methods = Methods;
//		Def.Functions = Functions;
//
//		puerts::RegisterJSClass(Def);
//	}
//};
//
//AutoRegister_SWizard _AutoRegister_SWizard;