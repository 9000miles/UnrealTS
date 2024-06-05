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

UsingCppType(SEyeDropperButton);
UsingTSharedPtr(SEyeDropperButton);

namespace $SEyeDropperButton
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SEyeDropperButton::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_EVENT(FOnLinearColorValueChanged, OnValueChanged, );
		$SLATE_EVENT(FSimpleDelegate, OnBegin, );
		$SLATE_EVENT(FOnDropperComplete, OnComplete, );
		$SLATE_ATTRIBUTE(float, DisplayGamma, );
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

		SEyeDropperButton::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SEyeDropperButton> Widget = MakeTDecl<SEyeDropperButton>("SEyeDropperButton", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SEyeDropperButton>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SEyeDropperButton>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SEyeDropperButton>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SEyeDropperButton>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SEyeDropperButton> Widget = MakeShared<SEyeDropperButton>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SEyeDropperButton>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SEyeDropperButton
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SEyeDropperButton");
		Args.Add<FOnLinearColorValueChanged>("OnValueChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FSimpleDelegate>("OnBegin", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnDropperComplete>("OnComplete", DTS::EArgType::SLATE_EVENT);
		Args.Add<float>("DisplayGamma", DTS::EArgType::SLATE_ATTRIBUTE);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SEyeDropperButton").Super("SButton")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SEyeDropperButton.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SEyeDropperButton>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SEyeDropperButton>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SEyeDropperButton.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SEyeDropperButton>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SEyeDropperButton()
	{
		GenDTS();
		RegisterTSharedPtr(SEyeDropperButton);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SEyeDropperButton::$SNew},
			{"SAssignNew", $SEyeDropperButton::$SAssignNew},
			{"MakeShared", $SEyeDropperButton::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SEyeDropperButton";
		Def.TypeId = puerts::StaticTypeId<SEyeDropperButton>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SButton>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SEyeDropperButton _AutoRegister_SEyeDropperButton;