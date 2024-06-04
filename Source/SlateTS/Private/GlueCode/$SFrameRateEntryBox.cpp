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

UsingCppType(SFrameRateEntryBox);
UsingTSharedPtr(SFrameRateEntryBox);

namespace $SFrameRateEntryBox
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SFrameRateEntryBox::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ATTRIBUTE(Value);
		$SLATE_EVENT(OnValueChanged);
		$SLATE_ATTRIBUTE(HasMultipleValues);
		$SLATE_STYLE_ARGUMENT(Style);
		$SLATE_ATTRIBUTE(Font);
		$SLATE_ATTRIBUTE(ForegroundColor);
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

		SFrameRateEntryBox::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SFrameRateEntryBox> Widget = MakeTDecl<SFrameRateEntryBox>("SFrameRateEntryBox", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SFrameRateEntryBox>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SFrameRateEntryBox>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SFrameRateEntryBox>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SFrameRateEntryBox>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SFrameRateEntryBox> Widget = MakeShared<SFrameRateEntryBox>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SFrameRateEntryBox>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SFrameRateEntryBox
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SFrameRateEntryBox");
		Args.Add<FFrameRate>("Value", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOnValueChanged>("OnValueChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<bool>("HasMultipleValues", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FEditableTextBoxStyle>("Style", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FSlateFontInfo>("Font", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FSlateColor>("ForegroundColor", DTS::EArgType::SLATE_ATTRIBUTE);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SFrameRateEntryBox").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SFrameRateEntryBox.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SFrameRateEntryBox>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SFrameRateEntryBox>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SFrameRateEntryBox.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SFrameRateEntryBox>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SFrameRateEntryBox()
	{
		GenDTS();
		RegisterTSharedPtr(SFrameRateEntryBox);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SFrameRateEntryBox::$SNew},
			{"SAssignNew", $SFrameRateEntryBox::$SAssignNew},
			{"MakeShared", $SFrameRateEntryBox::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SFrameRateEntryBox";
		Def.TypeId = puerts::StaticTypeId<SFrameRateEntryBox>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SFrameRateEntryBox _AutoRegister_SFrameRateEntryBox;