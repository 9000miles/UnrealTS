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

UsingCppType(STimecode);
UsingTSharedPtr(STimecode);

namespace $STimecode
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, STimecode::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ATTRIBUTE(FTimecode, Timecode, );
		$SLATE_ATTRIBUTE(FSlateFontInfo, TimecodeFont, );
		$SLATE_ATTRIBUTE(FSlateColor, TimecodeColor, );
		$SLATE_ATTRIBUTE(bool, DisplayLabel, );
		$SLATE_ATTRIBUTE(FSlateFontInfo, LabelFont, );
		$SLATE_ATTRIBUTE(FSlateColor, LabelColor, );
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

		STimecode::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<STimecode> Widget = MakeTDecl<STimecode>("STimecode", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<STimecode>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<STimecode>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<STimecode>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<STimecode>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<STimecode> Widget = MakeShared<STimecode>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<STimecode>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_STimecode
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("STimecode");
		Args.Add<FTimecode>("Timecode", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateFontInfo>("TimecodeFont", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateColor>("TimecodeColor", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("DisplayLabel", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateFontInfo>("LabelFont", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateColor>("LabelColor", DTS::EArgType::SLATE_ATTRIBUTE);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("STimecode").Super("SLeafWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("STimecode.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<STimecode>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<STimecode>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("STimecode.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<STimecode>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_STimecode()
	{
		GenDTS();
		RegisterTSharedPtr(STimecode);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $STimecode::$SNew},
			{"SAssignNew", $STimecode::$SAssignNew},
			{"MakeShared", $STimecode::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "STimecode";
		Def.TypeId = puerts::StaticTypeId<STimecode>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SLeafWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_STimecode _AutoRegister_STimecode;