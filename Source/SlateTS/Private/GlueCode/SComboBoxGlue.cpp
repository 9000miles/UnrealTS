//#pragma once
//
//#include "CoreMinimal.h"
//#include "JsObject.h"
//#include "Binding.hpp"
//#include "Defines.h"
//#include "TypeInfo.hpp"
//#include "UEDataBinding.hpp"
//#include "Helper/WidgetHelper.hpp"
//#include "DTSHelper.h"
//#include "PuertsEx.h"
//
//#include "Widgets/Input/SComboBox.h"
//
//UsingCppType(SComboBox);
//UsingTSharedPtr(SComboBox);
//
//namespace $SComboBox
//{
//	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SComboBox::FArguments& Arguments)
//	{
//		if (!Info[ArgumentsIndex]->IsObject()) return;
//
//		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
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
//		SComboBox::FArguments Arguments;
//		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);
//
//		FString Filename;
//		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));
//
//		TSharedPtr<SComboBox> Widget = MakeTDecl<SComboBox>("SComboBox", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
//		if (InfoLength == 2)
//		{
//			auto V8Result = puerts::converter::Converter<TSharedPtr<SComboBox>>::toScript(Context, Widget);
//			Info.GetReturnValue().Set(V8Result); return;
//		}
//
//		if (InfoLength == 3)
//		{
//			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
//			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
//				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SComboBox>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
//			{
//				TSharedPtr<SComboBox>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SComboBox>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
//				*Arg1 = Widget; return;
//			}
//		}
//	}
//	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
//	{
//		v8::Isolate* Isolate = Info.GetIsolate();
//		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
//
//		TSharedPtr<SComboBox> Widget = MakeShared<SComboBox>();
//		auto V8Result = puerts::converter::Converter<TSharedPtr<SComboBox>>::toScript(Context, Widget);
//		Info.GetReturnValue().Set(V8Result);
//	}
//	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
//}
//
//struct AutoRegister_SComboBox
//{
//	DTS::DTSArguments RegisterArguments()
//	{
//		DTS::DTSArguments DTSArgs = DTS::DTSArguments("SComboBox");
//		return DTSArgs;
//	}
//
//	void GenDTS()
//	{
//		DTS::Class ClassDTS = DTS::Class().Name("SComboBox").Super("SComboButton")
//			.Arguments(RegisterArguments())
//			.Functions(DTS::Array<DTS::Function>()
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("SNew").Static(true)
//						.Parameters(DTS::Array<DTS::Property>()
//							+ DTS::Property().Name("Arguments").Type("SComboBox.Arguments")
//							+ DTS::Property().Name("Filename").Type(TS_string)
//						)
//						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SComboBox>>::value().Data()))
//				]
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("SAssignNew").Static(true)
//						.Parameters(DTS::Array<DTS::Property>()
//							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SComboBox>>::value().Data()).Out(true)
//							+ DTS::Property().Name("Arguments").Type("SComboBox.Arguments")
//							+ DTS::Property().Name("Filename").Type(TS_string)
//						)
//				]
//				+ DTS::Function()
//				[
//					DTS::Function::Slot().Name("MakeShared").Static(true)
//						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SComboBox>>::value().Data()))
//				]
//			);
//
//		GenClassDTS.Add(ClassDTS);
//	}
//
//	AutoRegister_SComboBox()
//	{
//		GenDTS();
//		RegisterTSharedPtr(SComboBox);
//
//		puerts::JSClassDefinition Def = JSClassEmptyDefinition;
//
//		static puerts::JSFunctionInfo Methods[] =
//		{
//			{0, 0}
//		};
//		static puerts::JSFunctionInfo Functions[] =
//		{
//			{"SNew", $SComboBox::$SNew},
//			{"SAssignNew", $SComboBox::$SAssignNew},
//			{"MakeShared", $SComboBox::$MakeShared},
//			{0, 0}
//		};
//
//		Def.ScriptName = "SComboBox";
//		Def.TypeId = puerts::StaticTypeId<SComboBox>::get();
//		Def.SuperTypeId = puerts::StaticTypeId<SComboButton>::get();
//		Def.Methods = Methods;
//		Def.Functions = Functions;
//
//		puerts::RegisterJSClass(Def);
//	}
//};
//
//AutoRegister_SComboBox _AutoRegister_SComboBox;