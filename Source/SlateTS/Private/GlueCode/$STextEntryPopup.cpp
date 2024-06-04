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

UsingCppType(STextEntryPopup);
UsingTSharedPtr(STextEntryPopup);

namespace $STextEntryPopup
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, STextEntryPopup::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_ARGUMENT(Label);
		$SLATE_ARGUMENT(DefaultText);
		$SLATE_EVENT(OnTextChanged);
		$SLATE_EVENT(OnTextCommitted);
		$SLATE_ARGUMENT(SelectAllTextWhenFocused);
		$SLATE_ATTRIBUTE(ClearKeyboardFocusOnCommit);
		$SLATE_ATTRIBUTE(HintText);
		$SLATE_ATTRIBUTE(MaxWidth);
		$SLATE_EVENT(OnVerifyTextChanged);
		$SLATE_ARGUMENT(ErrorReporting);
		$SLATE_ARGUMENT(AutoFocus);
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

		STextEntryPopup::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<STextEntryPopup> Widget = MakeTDecl<STextEntryPopup>("STextEntryPopup", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<STextEntryPopup>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<STextEntryPopup>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<STextEntryPopup>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<STextEntryPopup>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<STextEntryPopup> Widget = MakeShared<STextEntryPopup>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<STextEntryPopup>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_STextEntryPopup
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("STextEntryPopup");
		Args.Add<FText>("Label", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FText>("DefaultText", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<FOnTextChanged>("OnTextChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTextCommitted>("OnTextCommitted", DTS::EArgType::SLATE_EVENT);
		Args.Add<bool>("SelectAllTextWhenFocused", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("ClearKeyboardFocusOnCommit", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FText>("HintText", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("MaxWidth", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOnVerifyTextChanged>("OnVerifyTextChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<TSharedPtr<class IErrorReportingWidget>>("ErrorReporting", DTS::EArgType::SLATE_ARGUMENT);
		Args.Add<bool>("AutoFocus", DTS::EArgType::SLATE_ARGUMENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("STextEntryPopup").Super("SCompoundWidget")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("STextEntryPopup.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<STextEntryPopup>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<STextEntryPopup>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("STextEntryPopup.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<STextEntryPopup>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_STextEntryPopup()
	{
		GenDTS();
		RegisterTSharedPtr(STextEntryPopup);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $STextEntryPopup::$SNew},
			{"SAssignNew", $STextEntryPopup::$SAssignNew},
			{"MakeShared", $STextEntryPopup::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "STextEntryPopup";
		Def.TypeId = puerts::StaticTypeId<STextEntryPopup>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SCompoundWidget>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_STextEntryPopup _AutoRegister_STextEntryPopup;