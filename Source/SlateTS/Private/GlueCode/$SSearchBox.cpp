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

UsingCppType(SSearchBox);
UsingTSharedPtr(SSearchBox);

namespace $SSearchBox
{
	static void $Arguments(const v8::FunctionCallbackInfo<v8::Value>& Info, uint8 ArgumentsIndex, v8::Local<v8::Context> Context, v8::Isolate* Isolate, SSearchBox::FArguments& Arguments)
	{
		if (!Info[ArgumentsIndex]->IsObject()) return;

		v8::Local<v8::Object> JsObject = Info[ArgumentsIndex].As<v8::Object>();
		$SLATE_STYLE_ARGUMENT(Style);
		$SLATE_ATTRIBUTE(HintText);
		$SLATE_ATTRIBUTE(InitialText);
		$SLATE_ATTRIBUTE(SearchResultData);
		$SLATE_ATTRIBUTE(IsSearching);
		$SLATE_EVENT(OnTextChanged);
		$SLATE_EVENT(OnTextCommitted);
		$SLATE_EVENT(OnSearch);
		$SLATE_ATTRIBUTE(SelectAllTextWhenFocused);
		$SLATE_ATTRIBUTE(MinDesiredWidth);
		$SLATE_ATTRIBUTE(DelayChangeNotificationsWhileTyping);
		$SLATE_ATTRIBUTE(DelayChangeNotificationsWhileTypingSeconds);
		$SLATE_EVENT(OnKeyDownHandler);
		$SLATE_EVENT(OnSearchGlassClicked);
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

		SSearchBox::FArguments Arguments;
		$Arguments(Info, ArgumentsIndex, Context, Isolate, Arguments);

		FString Filename;
		if (Info[FilenameIndex]->IsString()) Filename = UTF8_TO_TCHAR(*(v8::String::Utf8Value(Isolate, Info[FilenameIndex])));

		TSharedPtr<SSearchBox> Widget = MakeTDecl<SSearchBox>("SSearchBox", TCHAR_TO_ANSI(*Filename), 0, RequiredArgs::MakeRequiredArgs()) <<= Arguments;
		if (InfoLength == 2)
		{
			auto V8Result = puerts::converter::Converter<TSharedPtr<SSearchBox>>::toScript(Context, Widget);
			Info.GetReturnValue().Set(V8Result); return;
		}

		if (InfoLength == 3)
		{
			auto RefObject = puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex]);
			if (Info[ExposeIndex]->IsObject() && RefObject->IsObject() &&
				puerts::DataTransfer::IsInstanceOf(Isolate, puerts::StaticTypeId<TSharedPtr<SSearchBox>>::get(), RefObject->ToObject(Context).ToLocalChecked()))
			{
				TSharedPtr<SSearchBox>* Arg1 = puerts::DataTransfer::GetPointerFast<TSharedPtr<SSearchBox>>(puerts::DataTransfer::UnRef(Isolate, Info[ExposeIndex])->ToObject(Context).ToLocalChecked());
				*Arg1 = Widget; return;
			}
		}
	}
	static void $MakeShared(const v8::FunctionCallbackInfo<v8::Value>& Info)
	{
		v8::Isolate* Isolate = Info.GetIsolate();
		v8::Local<v8::Context> Context = Isolate->GetCurrentContext();

		TSharedPtr<SSearchBox> Widget = MakeShared<SSearchBox>();
		auto V8Result = puerts::converter::Converter<TSharedPtr<SSearchBox>>::toScript(Context, Widget);
		Info.GetReturnValue().Set(V8Result);
	}
	static void $SAssignNew(const v8::FunctionCallbackInfo<v8::Value>& Info) { $SNew(Info); }
}

struct AutoRegister_SSearchBox
{
	DTS::DTSArguments RegisterArguments()
	{
		DTS::DTSArguments Args = DTS::DTSArguments("SSearchBox");
		Args.Add<FSearchBoxStyle>("Style", DTS::EArgType::SLATE_STYLE_ARGUMENT);
		Args.Add<FText>("HintText", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FText>("InitialText", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<TOptional<FSearchResultData>>("SearchResultData", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("IsSearching", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOnTextChanged>("OnTextChanged", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnTextCommitted>("OnTextCommitted", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnSearch>("OnSearch", DTS::EArgType::SLATE_EVENT);
		Args.Add<bool>("SelectAllTextWhenFocused", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("MinDesiredWidth", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<bool>("DelayChangeNotificationsWhileTyping", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<float>("DelayChangeNotificationsWhileTypingSeconds", DTS::EArgType::SLATE_ATTRIBUTE);
		Args.Add<FOnKeyDown>("OnKeyDownHandler", DTS::EArgType::SLATE_EVENT);
		Args.Add<FOnClicked>("OnSearchGlassClicked", DTS::EArgType::SLATE_EVENT);
		return Args;
	}

	void GenDTS()
	{
		DTS::Class ClassDTS = DTS::Class().Name("SSearchBox").Super("SEditableTextBox")
			.Arguments(RegisterArguments())
			.Functions(DTS::Array<DTS::Function>()
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("Arguments").Type("SSearchBox.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SSearchBox>>::value().Data()))
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("SAssignNew").Static(true)
						.Parameters(DTS::Array<DTS::Property>()
							+ DTS::Property().Name("WidgetRef").Type(puerts::ScriptTypeName<TSharedPtr<SSearchBox>>::value().Data()).Out(true)
							+ DTS::Property().Name("Arguments").Type("SSearchBox.Arguments")
							+ DTS::Property().Name("Filename").Type(TS_string)
						)
				]
				+ DTS::Function()
				[
					DTS::Function::Slot().Name("MakeShared").Static(true)
						.Return(DTS::Property().Type(puerts::ScriptTypeName<TSharedPtr<SSearchBox>>::value().Data()))
				]
			);

		DTS::FClassDTS::Add(ClassDTS);
	}

	AutoRegister_SSearchBox()
	{
		GenDTS();
		RegisterTSharedPtr(SSearchBox);

		puerts::JSClassDefinition Def = JSClassEmptyDefinition;

		static puerts::JSFunctionInfo Methods[] =
		{
			{0, 0}
		};
		static puerts::JSFunctionInfo Functions[] =
		{
			{"SNew", $SSearchBox::$SNew},
			{"SAssignNew", $SSearchBox::$SAssignNew},
			{"MakeShared", $SSearchBox::$MakeShared},
			{0, 0}
		};

		Def.ScriptName = "SSearchBox";
		Def.TypeId = puerts::StaticTypeId<SSearchBox>::get();
		Def.SuperTypeId = puerts::StaticTypeId<SEditableTextBox>::get();
		Def.Methods = Methods;
		Def.Functions = Functions;

		puerts::RegisterJSClass(Def);
	}
};

AutoRegister_SSearchBox _AutoRegister_SSearchBox;