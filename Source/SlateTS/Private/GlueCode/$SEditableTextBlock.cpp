#pragma once

#include "CoreMinimal.h"
#include "JsObject.h"
#include "Binding.hpp"
#include "DTSDefine.h"
#include "TypeInfo.hpp"
#include "UEDataBinding.hpp"
#include "Helper/WidgetHelper.hpp"
#include "DTSHelper.h"
#include "DTSDefine.h"
#include "PuertsEx.h"

UsingCppType(FEditableTextBlock);
UsingTSharedPtr(FEditableTextBlock);

namespace $FEditableTextBlock
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, FEditableTextBlock::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();

	}

	static void $SNew(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();
		const uint8 InfoLength = Info.Length();
		if (InfoLength <= 1) { puerts::DataTransfer::ThrowException(Isolate, "Invalid argument!"); return; }

		uint8 ExposeIndex = InfoLength == 3 ? 0 : -1;
		uint8 ArgumentsIndex = InfoLength == 3 ? 1 : 0;
		uint8 FilenameIndex = InfoLength == 3 ? 2 : 1;

		FEditableTextBlock::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<FEditableTextBlock> Widget = MakeTDecl<FEditableTextBlock>("FEditableTextBlock", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<FEditableTextBlock>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<FEditableTextBlock>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<FEditableTextBlock>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<FEditableTextBlock>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<FEditableTextBlock> Widget = MakeShared<FEditableTextBlock>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<FEditableTextBlock>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_FEditableTextBlock
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("FEditableTextBlock");

		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("FEditableTextBlock").Super("FMultiBlock")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("FEditableTextBlock.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<FEditableTextBlock>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<FEditableTextBlock>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("FEditableTextBlock.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<FEditableTextBlock>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_FEditableTextBlock()
	{
		GenDTS();
		RegisterTSharedPtr(FEditableTextBlock);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $FEditableTextBlock::$SNew},
			{"SAssignNew", $FEditableTextBlock::$SAssignNew},
			{"MakeShared", $FEditableTextBlock::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "FEditableTextBlock";
		Def.TypeId = puerts::StaticTypeId<FEditableTextBlock>::get();
		Def.SuperTypeId = puerts::StaticTypeId<FMultiBlock>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_FEditableTextBlock _AutoRegister_FEditableTextBlock;